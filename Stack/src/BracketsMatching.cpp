/*
 * BracketsMatching.cpp
 *
 *  Created on: 2017年9月7日
 *      Author: baoxd
 */
#include <iostream>
#include <string.h>
#include "SeqStack.h"

using namespace std;

/**
 * 括号匹配检测
 * 假设表达式中允许包含两种括号:圆括号、方括号，其嵌套的顺序任意
 * (()[])、[([])[()]]都是正确的，[(])为不正确格式，可以通过栈来检测表达式的括号是否是正确的格式
 */


void matching(char *brackets, int length)
{
	if(brackets == NULL)
	{
		throw string("请输入合法字符数组");
		return;
	}
	SeqStack<char> stack(32);
	// 期待遍历的字符串
	SeqStack<char> expectStack(32);
	// 期望的字符
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
		cout << "括号匹配" << endl;
	}else{
		cout << "括号不匹配" << endl;
	}
}


//int main()
//{
//	/**
//	 *  sizeof和strlen在获取字符串长度时有区别：
//	 *  sizeof获取时实际长度，strlen获取的是从开始到'\0'结束符的长度，有可能获取不准确
//	 *	如果是字符串定义的字符数组，会自动在最后一位添加'\0', 用sizeof获取时要减一才是实
//	 *	际支付长度
//	 */
//	char chars[] = "(([]([()]))([(])))";
////	char chars[6] = {'a', 'c', '0', 'z', '3','d'};
////	cout << sizeof(chars);
////	cout << strlen(chars);
//	// 已遍历字符串
//	matching(chars, strlen(chars));
//	return 0;
//}



