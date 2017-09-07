//============================================================================
// Name        : Stack.cpp
// Author      : baoxd
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "SeqStack.h"
#include "Person.h"
using namespace std;

void printInt(int o){
	cout << o << endl;
}

void printPerson(Person p)
{
	cout << "(" << p.getName() << "," << p.getAge() << ")" << endl;
}

//int main() {
//
//	cout << "**********int����ջ����**********" << endl;
//	SeqStack<int> sStack(3);
//	int n1 = 1;
//	int n2 = 2;
//	int n3 = 3;
//	sStack.enStack(n1);
//	sStack.enStack(n2);
//	sStack.enStack(n3);
//	// ջ�б����
//	sStack.visitStack(&printInt);
//	// ��ջ
//	int tmp;
//	sStack.deStack(tmp);
//	cout << "n1��ַ�� " << &n1 << endl;
//	cout << "tmp��ַ�� " << &tmp << endl;
//	cout << tmp << endl;
//	cout << "��ջ�������" << endl;
//	sStack.visitStack(&printInt);
//
//	cout << "**********Person����ջ����**********" << endl;
//	SeqStack<Person> sStackPerson(3);
//	Person *p1 = new Person("zhangsan", 20);
//	Person *p2 = new Person("lisi", 21);
//	Person *p3 = new Person("wangwu", 22);
//	//person��ջ
//	cout << "�ڴ��ַ:" << p1 << endl;
//	sStackPerson.enStack(*p1);
//	cout << "�ڴ��ַ:" << p2 << endl;
//	sStackPerson.enStack(*p2);
//	cout << "�ڴ��ַ:" << p3 << endl;
//	sStackPerson.enStack(*p3);
////	Person p1("zhangsan", 20);
////	Person p2("lisi", 21);
////	Person p3("wangwu", 22);
////	cout << "�ڴ��ַ:" << &p1 << endl;
////	sStackPerson.enStack(p1);
////	cout << "�ڴ��ַ:" << &p2 << endl;
////	sStackPerson.enStack(p2);
////	cout << "�ڴ��ַ:" << &p3 << endl;
////	sStackPerson.enStack(p3);
//	sStackPerson.visitStack(&printPerson);
//
//
//	// ��ջ
//	Person pTmp;
//	sStackPerson.deStack(pTmp);
//	cout << "��ջ���ڴ��ַ:" << &tmp << endl;
//	cout << pTmp.getName() << "," << pTmp.getAge() << endl;
//	sStackPerson.visitStack(&printPerson);
//
////	delete p1;
////	delete p2;
////	delete p3;
//	return 0;
//}
