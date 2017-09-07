/*
 * EvaluateExpression.cpp
 *
 *  Created on: 2017��9��7��
 *      Author: baoxd
 */
#include <iostream>
#include "SeqStack.h"
#include <string.h>

using namespace std;

/**
 * ջӦ�� -- ���ʽ��ֵ
 *
 * ���������������ֵķ������ȼ�
 * ----------------------------------------------------------
 * |       |   +  |   -  |   *  |   /  |   (  |   )  |   #  |
 * |------ |------|------|------|------|------|------|------|
 * |   +   |   >  |   >  |   <  |   <  |   <  |   >  |   >  |
 * |------ |------|------|------|------|------|------|------|
 * |   -   |   >  |   >  |   <  |   <  |   <  |   >  |   >  |
 * |------ |------|------|------|------|------|------|------|
 * |   *   |   >  |   >  |   >  |   >  |   <  |   >  |   >  |
 * |------ |------|------|------|------|------|------|------|
 * |   /   |   >  |   >  |   >  |   >  |   <  |   >  |   >  |
 * |------ |------|------|------|------|------|------|------|
 * |   (   |   <  |   <  |   <  |   <  |   <  |   =  |      |
 * |------ |------|------|------|------|------|------|------|
 * |   )   |   >  |   >  |   >  |   >  |      |   >  |   >  |
 * |------ |------|------|------|------|------|------|------|
 * |   #   |   <  |   <  |   <  |   <  |   <  |      |   =  |
 * |-------|------|------|------|------|------|------|------|
 */

// �жϲ������Ƿ�Ϸ�
int isOperator(char o)
{
	char operators[] = {'+', '-', '*', '/', '(', ')', '#'};
	int size = sizeof(operators);
	for(int i = 0 ; i < size ; i++)
	{
		if(operators[i] == o)
		{
			return i;
		}
	}
	return -1;
}

// �ж����������������ȼ�
char Precede(char c1, char c2)
{
	char operatorsArr[][7] = {
			{'>', '>', '<', '<', '<', '>', '>'},
			{'>', '>', '<', '<', '<', '>', '>'},
			{'>', '>', '>', '>', '<', '>', '>'},
			{'>', '>', '>', '>', '<', '>', '>'},
			{'<', '<', '<', '<', '<', '=', '\0'},
			{'>', '>', '>', '>', '\0', '>', '>'},
			{'<', '<', '<', '<', '<', '\0', '='}
	};

	// ��ȡ�ַ��ڶ�ά�����е�����
	int c1_index = isOperator(c1);
	int c2_index = isOperator(c2);

	if(c1_index >=0 && c2_index >=0)
	{
		return operatorsArr[c1_index][c2_index];
	}
	else
	{
		return '\0';
	}

}


// ����
int operate(int n1, char oper, int n2)
{
	// ���ַ�ת��Ϊ����
	switch(oper)
	{
		case '+':
			return n1 + n2;
			break;
		case '-':
			return n1 - n2;
			break;
		case '*':
			return n1 * n2;
			break;
		case '/':
			return n1 / n2;
			break;
	}
	return 0;
}


// ���ʽ��ֵ
void evaluate(char chars[], int size)
{
	// ������ջ
	SeqStack<int> stackOperand(32);
	// ������ջ
	SeqStack<char> stackOperator(32);
	stackOperator.enStack('#');

	for(int i = 0 ; i < size; i++)
	{
		char currChar = chars[i];

		// �ж��ַ��Ƿ��������
		if(isOperator(currChar) < 0)
		{
			// char -> int
			stackOperand.enStack(currChar - '0');
		}else{
			// �жϵ�ǰ�������ջ������������ȼ�
			char tmp;
			int n1, n2;
			stackOperator.getTop(tmp);
			switch(Precede(tmp, currChar))
			{
				case '<': // ջ�����ȼ���
					stackOperator.enStack(currChar);
					break;
				case '=': // �����Ų�������һ���ַ�
					stackOperator.deStack(tmp);
					break;
				case '>': // ��ջ��������������ջ
					stackOperator.deStack(tmp);
					stackOperand.deStack(n2);
					stackOperand.deStack(n1);
					cout << "�������: " << n1 << tmp << n2 << "=" << operate(n1, tmp, n2) << endl;
					stackOperand.enStack(operate(n1, tmp, n2));
					//����֮����i--������Ϊ��ǰ���������currChar����Ҫ������ջ����������Ƚϣ�����currChar�ᶪʧ�������ٲ�������
					i--;
					break;
			}
		}
	}
	int result;
	stackOperand.getTop(result);
	cout << "���ʽ�ļ�������" << result << endl;
}

int main()
{
	char chars[] = "1-3*(7-2)+1#";
	evaluate(chars, strlen(chars));
	return 0;
}

