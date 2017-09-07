/*
 * EvaluateExpression.cpp
 *
 *  Created on: 2017年9月7日
 *      Author: baoxd
 */
#include <iostream>
#include "SeqStack.h"
#include <string.h>

using namespace std;

/**
 * 栈应用 -- 表达式求值
 *
 * 任意两个连续出现的符号优先级
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

// 判断操作符是否合法
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

// 判断两个操作符的优先级
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

	// 获取字符在二维数组中的索引
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


// 计算
int operate(int n1, char oper, int n2)
{
	// 将字符转换为整形
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


// 表达式求值
void evaluate(char chars[], int size)
{
	// 操作数栈
	SeqStack<int> stackOperand(32);
	// 操作符栈
	SeqStack<char> stackOperator(32);
	stackOperator.enStack('#');

	for(int i = 0 ; i < size; i++)
	{
		char currChar = chars[i];

		// 判断字符是否是运算符
		if(isOperator(currChar) < 0)
		{
			// char -> int
			stackOperand.enStack(currChar - '0');
		}else{
			// 判断当前运算符和栈顶运算符的优先级
			char tmp;
			int n1, n2;
			stackOperator.getTop(tmp);
			switch(Precede(tmp, currChar))
			{
				case '<': // 栈顶优先级低
					stackOperator.enStack(currChar);
					break;
				case '=': // 脱括号并接收下一个字符
					stackOperator.deStack(tmp);
					break;
				case '>': // 退栈，并将计算结果入栈
					stackOperator.deStack(tmp);
					stackOperand.deStack(n2);
					stackOperand.deStack(n1);
					cout << "计算过程: " << n1 << tmp << n2 << "=" << operate(n1, tmp, n2) << endl;
					stackOperand.enStack(operate(n1, tmp, n2));
					//这里之所以i--，是因为当前的运算符（currChar）需要继续和栈顶的运算符比较，否则currChar会丢失，不会再参与运算
					i--;
					break;
			}
		}
	}
	int result;
	stackOperand.getTop(result);
	cout << "表达式的计算结果：" << result << endl;
}

int main()
{
	char chars[] = "1-3*(7-2)+1#";
	evaluate(chars, strlen(chars));
	return 0;
}

