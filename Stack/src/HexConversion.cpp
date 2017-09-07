/*
 * HexConversion.h
 *
 *  Created on: 2017��9��7��
 *      Author: baoxd
 */

#ifndef HEXCONVERSION_H_
#define HEXCONVERSION_H_
#include <iostream>
#include "SeqStack.h"

/**
 *  ջӦ��--����ת��
 *  ʮ������ת��Ϊ����������ջ��һ��Ӧ��֮һ����ԭ������
 *  N: ʮ������  d: ��������
 *  N = (N / d) * d + N % d
 *
 *	���磺(1348)10 = (2504)8, ת����������
 *	N           N / 8        N % 8
 *	1348        168          4
 *  168         21           0
 *  21          2            5
 *  2           0            2
 */


void conversion(int N, int d)
{
	char hex[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	// ���ջ
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
//		cout << "*****����ת������*****" << endl;
//		cout << "����ʮ������:";
//		cin >> N;
//		cout << "��ѡ��Ҫת���Ľ���:" << endl;
//		cout << "1: ������" << endl;
//		cout << "2: �˽���" << endl;
//		cout << "3: 16����" << endl;
//		cin >> d;
//		d = d == 1 ? 2 : (d == 2 ? 8 : 16);
//		conversion(N, d);
//	}
//	return 0;
//}


#endif /* HEXCONVERSION_H_ */
