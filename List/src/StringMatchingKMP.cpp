/*
 * StringMatchingKPM.cpp
 *
 *  Created on: 2017年9月13日
 *      Author: baoxd
 */
#include <iostream>
#include "List.h"

using namespace std;
/**
 * 模式匹配的一种改进算法--KMP算法
 * 该算法可以在O(n+m)时间的数量级上完成串的模式匹配操作，其改进在于每次匹配不通过时，主串索引i不用回溯
 * 而是利用已经得到的“部分匹配”的结果将模式向右“滑动”尽可能远的距离。
 *
 * 在KPM算法之前，先看一般匹配过程
 * 第一趟匹配
 * a b a b c a b c a c  b a b
 * a b c    			i = 3, j = 3
 *
 * 第二趟匹配
 * a b a b c a b c a c  b a b
 *   a      			i = 2, j = 1
 *
 * 第三趟匹配
 * a b a b c a b c a c  b a b
 *     a b c a c    	i = 7, j = 5
 *
 * 第四趟匹配
 * a b a b c a b c a c  b a b
 *		 a				i = 4, j = 1
 *
 * 第五趟匹配
 * a b a b c a b c a c  b a b
 *		   a 			i = 5, j = 1
 *
 * 第六趟匹配
 * a b a b c a b c a c  b a b
 *	         a b c a c
 *
 * 在第三趟i=7,j=5匹配失败时，有进行了第四趟、第五趟的匹配，这实际是没有必要的，因为通过第三趟匹配已经知道主串中4,5,6位置是'b', 'c', 'a'，
 * 而匹配串中第一个是'a', 所以可以直接跳过4,5,6的位置 。
 * 现在讨论一般情况，假设主串`s1s2s3s4s4...sn`, 模式串`p1p2p3p4...pm`(n >= m), 从上面分析可知，为了改进匹配算法，需要解决的问题是：
 * 当匹配失败时（si!=pj）, 模式串向右“滑动”的距离是多远？ 或者说，在主串索引i不变的情况下，应该与子串中那个位置进行一下轮的匹配。
 *
 * 假设此时应与模式串中的k位置相匹配（k<j）, 则模式串的前k-1个字符满足一下关系
 * `p1p2...pk-1` = `s(i-k+1)s(i-k+2)...s(i-1)`
 * 已经得到的“部分”匹配结果是
 * `p(j-k+1)p(j-k+2)p(j-1)` = `s(i-k+1)s(i-k+2)...s(i-1)`
 * 由以上两式得：
 * `p1p2...pk-1` = `p(j-k+1)p(j-k+2)p(j-1)`
 *
 * 如果模式串中满足上面关系的两个子串， 则当主串s(i)和模式串p(j)不匹配时，只需将模式串向右“滑动” 至第k个串与主串i继续比较即可。
 * 我们称next[j] = k， 如果我们知道模式串每个位置的next, 则大大提高匹配速度。下面求解next[j] (j=1,2,3....m)的函数
 * 由以上讨论可知next函数值和主串无关
 * next[1] = 0
 * 设next[j] = k, 则 `p1p2...pk-1` = `p(j-k+1)p(j-k+2)p(j-1)`
 * next[j+1]有一下两种可能：
 *
 *  （1）：如果p(k) = p(j) 表明  `p1p2...pk-1pk` = `p(j-k+1)p(j-k+2)p(j-1)p(j)`
 *   则 ： next[j+1] = k+1
 *	     next[j+1] = next[k] + 1;
 *
 *	（2）：p(k) != p(j) 表明  `p1p2...pk-1pk` != `p(j-k+1)p(j-k+2)p(j-1)p(j)`
 *   此时可将求next函数值的过程看做模式匹配的过程，整个模式串既是主串又是子串，而在当前的匹配已经满足：
 *   p(j-k+1) = p1
 *   p(j-k+2) = p2
 *   	...
 *   p(k-1) = p(j-1) 则当p(k) != p(j)时，应当将模式串滑动至next[k]位置和主串的j位置比较，若next[k] = k', 且p(j) = p(k'),
 *   则说明主串中位置为（j+1）的字符之前存在长度为k'（即next[k]）的最长子串和模式串中从首字符开始的k'个字符串相等，即：
 *   `p1p2...pk-1p(k')` != `p(j-k'+1)p(j-k'+2)...p(j)`
 *   也就是：
 *   next[j+1] = k'+ 1  => next[j+1] = next[k] + 1
 *
 * 同理如果p(j) != p(k') , 则将模式串继续“滑动”至next[k']个字符同p(j)比较， 以此类推，p(j)和模式串中某个字符匹配，或者 不存在这样的k'
 * 则：next[j+1] = 1
 *
 * next实例：
 * 		-------------------------------
 * 		|j   |  1  2  3  4  5  6  7  8 |
 * 		|----|-------------------------|
 * 		|模式	 |  a  b  a  a  b  c  a  c |
 * 		|----|-------------------------|
 * 		|next|  0  1  1  2  2  3  1  2 |
 * 		-------------------------------
 * 假设已求出next[6] = 3, next[7] = ?
 * 利用上面的推理， 因next[6] = 3, p6 != p3, next[3] = 1, 因p6 != p1 且next[1] = 0,所以next[7] = 1。因p7 = p1,
 * 所以next[8] = next[7] + 1 = 2
 *
 *
 */

/**
 * 模式串next值函数
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
 * 前面的NEXT方法有一点缺陷。例如：`aaaab`和主串`aaabaaaab`匹配时，当i = 4, j = 4是 s[4] != p[4]
 * 根据上面的 算法需要进行next[4]=3, next[3] = 2, next[2] = 1 三种匹配，实际这三种匹配时不必要的。
 * 如果next[j] = k, 且p(j) = p(k), 当主串中si和pj比较不等时，s(i)不再需要和p(k)比较，而直接和p(next[k])比较
 *
 * j     |  1  2  3  4  5
 *-------|----------------
 * 模式	 |  a  a  a  a  b
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
 *  改进算法的另一种描述
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
		cout << "第" << num ++ << "此匹配" << endl;
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
	 *  测试一
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
//	cout << "字符串匹配的位置：" << index << endl;


	/**
	 * 测试2
	 * 主串 a c a b a a b a a b c a c a a b c
	 * 子串                       a b a a b c a c
	 *
	 * 	-------------------------------
	 * 	|j   |  1  2  3  4  5  6  7  8 |
	 *  |----|-------------------------|
	 *  |模式	 |  a  b  a  a  b  c  a  c |
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
//	cout << "字符串匹配的位置：" << index << endl;



	/**
	 * 测试3
	 * Next和Next_update的区别
	 * 主串 a a a b a a a a b
	 * 子串 a a a a b
	 * 	-----------------------
	 * 	|j   |  1  2  3  4  5 |
	 *  |----|----------------|
	 *  |模式	 |  a  a  a  a  b |
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
	cout << "字符串匹配的位置：" << index << endl;

	return 0;
}




