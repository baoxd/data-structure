/*
 * StringMatchingKPM.cpp
 *
 *  Created on: 2017��9��13��
 *      Author: baoxd
 */
#include <iostream>
#include "List.h"

using namespace std;
/**
 * ģʽƥ���һ�ָĽ��㷨--KMP�㷨
 * ���㷨������O(n+m)ʱ�������������ɴ���ģʽƥ���������Ľ�����ÿ��ƥ�䲻ͨ��ʱ����������i���û���
 * ���������Ѿ��õ��ġ�����ƥ�䡱�Ľ����ģʽ���ҡ�������������Զ�ľ��롣
 *
 * ��KPM�㷨֮ǰ���ȿ�һ��ƥ�����
 * ��һ��ƥ��
 * a b a b c a b c a c  b a b
 * a b c    			i = 3, j = 3
 *
 * �ڶ���ƥ��
 * a b a b c a b c a c  b a b
 *   a      			i = 2, j = 1
 *
 * ������ƥ��
 * a b a b c a b c a c  b a b
 *     a b c a c    	i = 7, j = 5
 *
 * ������ƥ��
 * a b a b c a b c a c  b a b
 *		 a				i = 4, j = 1
 *
 * ������ƥ��
 * a b a b c a b c a c  b a b
 *		   a 			i = 5, j = 1
 *
 * ������ƥ��
 * a b a b c a b c a c  b a b
 *	         a b c a c
 *
 * �ڵ�����i=7,j=5ƥ��ʧ��ʱ���н����˵����ˡ������˵�ƥ�䣬��ʵ����û�б�Ҫ�ģ���Ϊͨ��������ƥ���Ѿ�֪��������4,5,6λ����'b', 'c', 'a'��
 * ��ƥ�䴮�е�һ����'a', ���Կ���ֱ������4,5,6��λ�� ��
 * ��������һ���������������`s1s2s3s4s4...sn`, ģʽ��`p1p2p3p4...pm`(n >= m), �����������֪��Ϊ�˸Ľ�ƥ���㷨����Ҫ����������ǣ�
 * ��ƥ��ʧ��ʱ��si!=pj��, ģʽ�����ҡ��������ľ����Ƕ�Զ�� ����˵������������i���������£�Ӧ�����Ӵ����Ǹ�λ�ý���һ���ֵ�ƥ�䡣
 *
 * �����ʱӦ��ģʽ���е�kλ����ƥ�䣨k<j��, ��ģʽ����ǰk-1���ַ�����һ�¹�ϵ
 * `p1p2...pk-1` = `s(i-k+1)s(i-k+2)...s(i-1)`
 * �Ѿ��õ��ġ����֡�ƥ������
 * `p(j-k+1)p(j-k+2)p(j-1)` = `s(i-k+1)s(i-k+2)...s(i-1)`
 * ��������ʽ�ã�
 * `p1p2...pk-1` = `p(j-k+1)p(j-k+2)p(j-1)`
 *
 * ���ģʽ�������������ϵ�������Ӵ��� ������s(i)��ģʽ��p(j)��ƥ��ʱ��ֻ�轫ģʽ�����ҡ������� ����k����������i�����Ƚϼ��ɡ�
 * ���ǳ�next[j] = k�� �������֪��ģʽ��ÿ��λ�õ�next, �������ƥ���ٶȡ��������next[j] (j=1,2,3....m)�ĺ���
 * ���������ۿ�֪next����ֵ�������޹�
 * next[1] = 0
 * ��next[j] = k, �� `p1p2...pk-1` = `p(j-k+1)p(j-k+2)p(j-1)`
 * next[j+1]��һ�����ֿ��ܣ�
 *
 *  ��1�������p(k) = p(j) ����  `p1p2...pk-1pk` = `p(j-k+1)p(j-k+2)p(j-1)p(j)`
 *   �� �� next[j+1] = k+1
 *	     next[j+1] = next[k] + 1;
 *
 *	��2����p(k) != p(j) ����  `p1p2...pk-1pk` != `p(j-k+1)p(j-k+2)p(j-1)p(j)`
 *   ��ʱ�ɽ���next����ֵ�Ĺ��̿���ģʽƥ��Ĺ��̣�����ģʽ���������������Ӵ������ڵ�ǰ��ƥ���Ѿ����㣺
 *   p(j-k+1) = p1
 *   p(j-k+2) = p2
 *   	...
 *   p(k-1) = p(j-1) ��p(k) != p(j)ʱ��Ӧ����ģʽ��������next[k]λ�ú�������jλ�ñȽϣ���next[k] = k', ��p(j) = p(k'),
 *   ��˵��������λ��Ϊ��j+1�����ַ�֮ǰ���ڳ���Ϊk'����next[k]������Ӵ���ģʽ���д����ַ���ʼ��k'���ַ�����ȣ�����
 *   `p1p2...pk-1p(k')` != `p(j-k'+1)p(j-k'+2)...p(j)`
 *   Ҳ���ǣ�
 *   next[j+1] = k'+ 1  => next[j+1] = next[k] + 1
 *
 * ͬ�����p(j) != p(k') , ��ģʽ����������������next[k']���ַ�ͬp(j)�Ƚϣ� �Դ����ƣ�p(j)��ģʽ����ĳ���ַ�ƥ�䣬���� ������������k'
 * ��next[j+1] = 1
 *
 * nextʵ����
 * 		-------------------------------
 * 		|j   |  1  2  3  4  5  6  7  8 |
 * 		|----|-------------------------|
 * 		|ģʽ	 |  a  b  a  a  b  c  a  c |
 * 		|----|-------------------------|
 * 		|next|  0  1  1  2  2  3  1  2 |
 * 		-------------------------------
 * ���������next[6] = 3, next[7] = ?
 * ������������� ��next[6] = 3, p6 != p3, next[3] = 1, ��p6 != p1 ��next[1] = 0,����next[7] = 1����p7 = p1,
 * ����next[8] = next[7] + 1 = 2
 *
 *
 */

/**
 * ģʽ��nextֵ����
 *	a  b  a  a  b  c  a  c
 *	-1 0  0  1  1  2  0  1
 */
void Next(List<char> T, int next[])
{
	int length = T.ListLength();
	next[0] = -1;
	int i = 0, j = -1;
	char t1 = '\0', t2 = '\0';

	while(i < length)
	{
		T.getElem(i, t1);
		if(j >= 0)
		{
			T.getElem(j, t2);
		}
		if(j == -1 || t1 == t2)
		{
			i++; j++;
			next[i] = j;
		}else{
			j = next[j];
		}
	}
}

/**
 * ǰ���NEXT������һ��ȱ�ݡ����磺`aaaab`������`aaabaaaab`ƥ��ʱ����i = 4, j = 4�� s[4] != p[4]
 * ��������� �㷨��Ҫ����next[4]=3, next[3] = 2, next[2] = 1 ����ƥ�䣬ʵ��������ƥ��ʱ����Ҫ�ġ�
 * ���next[j] = k, ��p(j) = p(k), ��������si��pj�Ƚϲ���ʱ��s(i)������Ҫ��p(k)�Ƚϣ���ֱ�Ӻ�p(next[k])�Ƚ�
 *
 * j     |  1  2  3  4  5
 *-------|----------------
 * ģʽ	 |  a  a  a  a  b
 *-------|----------------
 * NEXT  |  0  1  2  3  4
 *-------|----------------
 * NEXT2 |  0  0  0  0  4
 *-------|----------------
 */
void Next_update(List<char> T, int next[])
{
	int length = T.ListLength();
	next[0] = -1;
	int i = 0, j = -1;
	char t1 = '\0', t2 = '\0';

	while(i < length-1)
	{
		T.getElem(i, t1);
		if(j >= 0)
		{
			T.getElem(j, t2);
		}
		if(j == -1 || t1 == t2)
		{
			i++; j++;
			char tt1 = '\0', tt2 = '\0';
			T.getElem(i, tt1);
			if(j >= 0)
			{
				T.getElem(j, tt2);
			}

			if(tt1 != tt2)
			{
				next[i] = j;
			}else{
				next[i] = next[j];
			}
		}else{
			j = next[j];
		}
	}
}


/**
 *  �Ľ��㷨����һ������
 */
void Next_update2(List<char> T, int next[])
{
	next[0] = -1;
	for(int i = 1 ; i < T.ListLength(); i++)
	{
		int j = next[i - 1];
		char t1 = '\0', t2 = '\0';

		T.getElem(i - 1, t1);
		T.getElem(j, t2);

		while(t1 != t2 && j >= 0)
		{
			j = next[j];
			if(j >= 0)
			{
				T.getElem(j, t2);
			}
		}
		if(j >= 0)
		{
			T.getElem(j, t2);
		}
		else
		{
			t2 = '\0';
		}
		if(t1 == t2)
		{
			next[i] = j + 1;
		}
		else
		{
			next[i] = 0;
		}
	}
}



int Index_KMP(List<char> S, List<char> T, int pos = 0)
{
	int i = pos , j = 0;
	int sLength = S.ListLength();
	int tLength = T.ListLength();
	char s, t;
	int num = 1 ;
	int next[tLength];
//	Next_update(T, next);
	Next(T, next);

	for(int i = 0 ; i < tLength ; i++)
	{
		cout << next[i] << "," ;
	}

	cout << endl;

	while(i < sLength && j < tLength)
	{
		cout << "��" << num ++ << "��ƥ��" << endl;
		S.getElem(i, s);
		T.getElem(j, t);
		if(s == t)
		{
			i++; j++;
		}
		else
		{
			j = next[j];
			if(j < 0)
			{
				j = 0 ;
				i++;
			}
		}
	}
	cout << "i:" << i << endl;
	cout << "j:" << j << endl;
	if(j >= tLength)
	{
		return i - j ;
	}
	return -1;
}



int main()
{
	/**
	 *  ����һ
	 *  a b a b c a b c a c  b a b
	 *	          a b c a c
	 */
//	List<char> S(32);
//	List<char> T(5);
//	char s0 = 'a';
//	char s1 = 'b';
//	char s2 = 'a';
//	char s3 = 'b';
//	char s4 = 'c';
//	char s5 = 'a';
//	char s6 = 'b';
//	char s7 = 'c';
//	char s8 = 'a';
//	char s9 = 'c';
//	char s10 = 'b';
//	char s11 = 'a';
//	char s12 = 'b';
//
//	char t0 = 'a';
//	char t1 = 'b';
//	char t2 = 'c';
//	char t3 = 'a';
//	char t4 = 'c';
//
//	S.ListInsert(0, &s0);
//	S.ListInsert(1, &s1);
//	S.ListInsert(2, &s2);
//	S.ListInsert(3, &s3);
//	S.ListInsert(4, &s4);
//	S.ListInsert(5, &s5);
//	S.ListInsert(6, &s6);
//	S.ListInsert(7, &s7);
//	S.ListInsert(8, &s8);
//	S.ListInsert(9, &s9);
//	S.ListInsert(10, &s10);
//	S.ListInsert(11, &s11);
//	S.ListInsert(12, &s12);
//
//	T.ListInsert(0, &t0);
//	T.ListInsert(1, &t1);
//	T.ListInsert(2, &t2);
//	T.ListInsert(3, &t3);
//	T.ListInsert(4, &t4);
//
//	int index = Index_KMP(S, T);
//	cout << "�ַ���ƥ���λ�ã�" << index << endl;


	/**
	 * ����2
	 * ���� a c a b a a b a a b c a c a a b c
	 * �Ӵ�                       a b a a b c a c
	 *
	 * 	-------------------------------
	 * 	|j   |  1  2  3  4  5  6  7  8 |
	 *  |----|-------------------------|
	 *  |ģʽ	 |  a  b  a  a  b  c  a  c |
	 * 	|----|-------------------------|
	 * 	|next| -1  0  0  1  1  2  0  1 |
	 * 	|up  | -1  0 -1  1  0  2 -1  1 |
	 */
//	List<char> S(32);
//	List<char> T(8);
//	char s0 = 'a';
//	char s1 = 'c';
//	char s2 = 'a';
//	char s3 = 'b';
//	char s4 = 'a';
//	char s5 = 'a';
//	char s6 = 'b';
//	char s7 = 'a';
//	char s8 = 'a';
//	char s9 = 'b';
//	char s10 = 'c';
//	char s11 = 'a';
//	char s12 = 'c';
//	char s13 = 'a';
//	char s14 = 'a';
//	char s15 = 'b';
//	char s16 = 'c';
//
//	char t0 = 'a';
//	char t1 = 'b';
//	char t2 = 'a';
//	char t3 = 'a';
//	char t4 = 'b';
//	char t5 = 'c';
//	char t6 = 'a';
//	char t7 = 'c';
//
//	S.ListInsert(0, &s0);
//	S.ListInsert(1, &s1);
//	S.ListInsert(2, &s2);
//	S.ListInsert(3, &s3);
//	S.ListInsert(4, &s4);
//	S.ListInsert(5, &s5);
//	S.ListInsert(6, &s6);
//	S.ListInsert(7, &s7);
//	S.ListInsert(8, &s8);
//	S.ListInsert(9, &s9);
//	S.ListInsert(10, &s10);
//	S.ListInsert(11, &s11);
//	S.ListInsert(12, &s12);
//	S.ListInsert(13, &s13);
//	S.ListInsert(14, &s14);
//	S.ListInsert(15, &s15);
//	S.ListInsert(16, &s16);
//
//	T.ListInsert(0, &t0);
//	T.ListInsert(1, &t1);
//	T.ListInsert(2, &t2);
//	T.ListInsert(3, &t3);
//	T.ListInsert(4, &t4);
//	T.ListInsert(5, &t5);
//	T.ListInsert(6, &t6);
//	T.ListInsert(7, &t7);
//
//	int index = Index_KMP(S, T);
//	cout << "�ַ���ƥ���λ�ã�" << index << endl;



	/**
	 * ����3
	 * Next��Next_update������
	 * ���� a a a b a a a a b
	 * �Ӵ� a a a a b
	 * 	-----------------------
	 * 	|j   |  1  2  3  4  5 |
	 *  |----|----------------|
	 *  |ģʽ	 |  a  a  a  a  b |
	 * 	|----|----------------|
	 * 	|next| -1  0  1  2  3 |
	 * 	|up  | -1 -1 -1 -1  3 |
	 */
	List<char> S(10);
	List<char> T(5);
	char s0 = 'a';
	char s1 = 'a';
	char s2 = 'a';
	char s3 = 'b';
	char s4 = 'a';
	char s5 = 'a';
	char s6 = 'a';
	char s7 = 'a';
	char s8 = 'b';


	char t0 = 'a';
	char t1 = 'a';
	char t2 = 'a';
	char t3 = 'a';
	char t4 = 'b';


	S.ListInsert(0, &s0);
	S.ListInsert(1, &s1);
	S.ListInsert(2, &s2);
	S.ListInsert(3, &s3);
	S.ListInsert(4, &s4);
	S.ListInsert(5, &s5);
	S.ListInsert(6, &s6);
	S.ListInsert(7, &s7);
	S.ListInsert(8, &s8);

	T.ListInsert(0, &t0);
	T.ListInsert(1, &t1);
	T.ListInsert(2, &t2);
	T.ListInsert(3, &t3);
	T.ListInsert(4, &t4);

	int index = Index_KMP(S, T);
	cout << "�ַ���ƥ���λ�ã�" << index << endl;

	return 0;
}




