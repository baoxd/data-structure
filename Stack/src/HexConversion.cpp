/*
 * HexConversion.h
 *
 *  Created on: 2017年9月7日
 *      Author: baoxd
 */

#ifndef HEXCONVERSION_H_
#define HEXCONVERSION_H_
#include <iostream>
#include "SeqStack.h"

/**
 *  栈应用--进制转换
 *  十进制数转换为其他进制是栈的一个应用之一，其原理如下
 *  N: 十进制数  d: 其他进制
 *  N = (N / d) * d + N % d
 *
 *	例如：(1348)10 = (2504)8, 转换过程如下
 *	N           N / 8        N % 8
 *	1348        168          4
 *  168         21           0
 *  21          2            5
 *  2           0            2
 */


void conversion(int N, int d)
{
	char hex[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	// 清空栈
	SeqStack<int> stack(32);
	while(N)
	{
		stack.enStack(N % d);
		N = N / d;
	}

	int tmp;
	while(!stack.isEmpty()){
		stack.deStack(tmp);
		cout << hex[tmp];
	}
	cout << endl;

	stack.destoryStck();
}


//int main()
//{
//	int N, d;
//	while(true)
//	{
//		cout << "*****进制转换工具*****" << endl;
//		cout << "请输十进制数:";
//		cin >> N;
//		cout << "请选择要转换的进制:" << endl;
//		cout << "1: 二进制" << endl;
//		cout << "2: 八进制" << endl;
//		cout << "3: 16进制" << endl;
//		cin >> d;
//		d = d == 1 ? 2 : (d == 2 ? 8 : 16);
//		conversion(N, d);
//	}
//	return 0;
//}


#endif /* HEXCONVERSION_H_ */
