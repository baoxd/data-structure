/*
 * BracketsMatching.cpp
 *
 *  Created on: 2017��9��7��
 *      Author: baoxd
 */
#include <iostream>
#include <string.h>
#include "SeqStack.h"

using namespace std;

/**
 * ����ƥ����
 * ������ʽ�����������������:Բ���š������ţ���Ƕ�׵�˳������
 * (()[])��[([])[()]]������ȷ�ģ�[(])Ϊ����ȷ��ʽ������ͨ��ջ�������ʽ�������Ƿ�����ȷ�ĸ�ʽ
 */


void matching(char *brackets, int length)
{
	if(brackets == NULL)
	{
		throw string("������Ϸ��ַ�����");
		return;
	}
	SeqStack<char> stack(32);
	// �ڴ��������ַ���
	SeqStack<char> expectStack(32);
	// �������ַ�
	char lastExpectChar = '\0', tmp;
	for(int i = 0 ; i < length ; i++)
	{
		if(lastExpectChar == '\0')
		{
			stack.enStack(brackets[i]);
			switch(brackets[i])
			{
				case '[':
					lastExpectChar = ']';
					break;
				case '(':
					lastExpectChar = ')';
					break;
			}
		}
		else
		{
			if(brackets[i] == lastExpectChar)
			{
				stack.deStack(tmp);
				expectStack.deStack(lastExpectChar);
			}
			else
			{
				stack.enStack(brackets[i]);
				expectStack.enStack(lastExpectChar);
				switch(brackets[i])
				{
					case '[':
						lastExpectChar = ']';
						break;
					case '(':
						lastExpectChar = ')';
						break;
				}
			}
		}
	}

	if(stack.isEmpty() && expectStack.isEmpty())
	{
		cout << "����ƥ��" << endl;
	}else{
		cout << "���Ų�ƥ��" << endl;
	}
}


//int main()
//{
//	/**
//	 *  sizeof��strlen�ڻ�ȡ�ַ�������ʱ������
//	 *  sizeof��ȡʱʵ�ʳ��ȣ�strlen��ȡ���Ǵӿ�ʼ��'\0'�������ĳ��ȣ��п��ܻ�ȡ��׼ȷ
//	 *	������ַ���������ַ����飬���Զ������һλ���'\0', ��sizeof��ȡʱҪ��һ����ʵ
//	 *	��֧������
//	 */
//	char chars[] = "(([]([()]))([(])))";
////	char chars[6] = {'a', 'c', '0', 'z', '3','d'};
////	cout << sizeof(chars);
////	cout << strlen(chars);
//	// �ѱ����ַ���
//	matching(chars, strlen(chars));
//	return 0;
//}



