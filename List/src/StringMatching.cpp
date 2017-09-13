/*
 * StringMatching.cpp
 *
 *  Created on: 2017��9��13��
 *      Author: baoxd
 */
#include <iostream>
#include "List.h"
using namespace std;

/**
 *  �ַ�����ģʽƥ��һ���㷨Index(S, T, pos)
 *  	�Ӵ��Ķ�λ����ͨ����������ģʽƥ��(SΪ������TΪģʽ����posΪƥ����ʼλ��)
 *	����
 *		���� a b a b c a b c a c  b a b
 *	 	�Ӵ� a b c a c
 *	ƥ�����̣�
 *
 *	��һ��ƥ��
 *	a b a b c a b c a c  b a b
 *	a b c
 *	i = 3, j = 3
 *
 *	�ڶ���ƥ��
 *	a b a b c a b c a c  b a b
 *	  a
 *	i = 2, j = 1
 *
 *	������ƥ��
 *	a b a b c a b c a c  b a b
 *		a b c a c
 *	i = 7, j = 5
 *
 *	������ƥ��
 *	a b a b c a b c a c  b a b
 *		  a
 *	i = 4, j = 1
 *
 *	������ƥ��
 *	a b a b c a b c a c  b a b
 *			a
 *	i = 5, j = 1
 *
 *	������ƥ��
 *	a b a b c a b c a c  b a b
 *	          a b c a c
 *	i = 11, j = 6
 */

int Index(List<char> S, List<char> T, int pos = 0)
{
	int i = pos , j = 0;
	int sLength = S.ListLength();
	int tLength = T.ListLength();
	char s, t;
	int num = 1 ;

	while(i < sLength && j < tLength)
	{
		cout << "��" << num ++ << "��ƥ��" << endl;
		S.getElem(i, s);
		T.getElem(j, t);
		if(s != '\0' && t != '\0'){
			if(s == t)
			{
				i++;
				j++;
			}else
			{
				i = i - j + 1;
				j = 0;
			}
		}
	}
	cout << "j:" << j << endl;
	if(j >= tLength)
	{
		return i - j ;
	}
	return -1;
}


//int main()
//{
////	List<char> S(32);
////	List<char> T(5);
////	char s0 = 'a';
////	char s1 = 'b';
////	char s2 = 'a';
////	char s3 = 'b';
////	char s4 = 'c';
////	char s5 = 'a';
////	char s6 = 'b';
////	char s7 = 'c';
////	char s8 = 'a';
////	char s9 = 'c';
////	char s10 = 'b';
////	char s11 = 'a';
////	char s12 = 'b';
////
////	char t0 = 'a';
////	char t1 = 'b';
////	char t2 = 'c';
////	char t3 = 'a';
////	char t4 = 'c';
////
////	S.ListInsert(0, &s0);
////	S.ListInsert(1, &s1);
////	S.ListInsert(2, &s2);
////	S.ListInsert(3, &s3);
////	S.ListInsert(4, &s4);
////	S.ListInsert(5, &s5);
////	S.ListInsert(6, &s6);
////	S.ListInsert(7, &s7);
////	S.ListInsert(8, &s8);
////	S.ListInsert(9, &s9);
////	S.ListInsert(10, &s10);
////	S.ListInsert(11, &s11);
////	S.ListInsert(12, &s12);
////
////	T.ListInsert(0, &t0);
////	T.ListInsert(1, &t1);
////	T.ListInsert(2, &t2);
////	T.ListInsert(3, &t3);
////	T.ListInsert(4, &t4);
////
////	int index = Index(S, T);
////	cout << "�ַ���ƥ���λ�ã�" << index << endl;
//
//	/**
//	 * ���� a c a b a a b a a b c a c a a b c
//	 * �Ӵ�                       a b a a b c a c
//	 *
//	 * 	-------------------------------
//	 * 	|j   |  1  2  3  4  5  6  7  8 |
//	 *  |----|-------------------------|
//	 *  |ģʽ	 |  a  b  a  a  b  c  a  c |
//	 * 	|----|-------------------------|
//	 * 	|next| -1  0  0  1  1  2  0  1 |
//	 * 	|up  | -1  0 -1  1  0  2 -1  1 |
//	 */
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
//	// 20��ƥ��
//	int index = Index(S, T);
//	cout << "�ַ���ƥ���λ�ã�" << index << endl;
//
//	return 0;
//}
