//============================================================================
// Name        : List.cpp
// Author      : baoxd
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "List.h"
#include "Person.h"


bool compareInt(int n, int m)
{
	return n == m ;
}

void visitInt(int n)
{
	cout << n;
}

bool comparePerson(Person p1, Person p2)
{
	if(p1.getAge() == p2.getAge() && p1.getName() == p2.getName())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void visitPerson(Person p)
{
	cout << "姓名:" << p.getName() << " 年龄:" << p.getAge() << endl;
}

int main() {
	cout << "***********线性表-顺序表-整形***********"<< endl;
	List<int> list(10, compareInt, visitInt);
	int n1 = 1;
	int n2 = 2;
	int n3 = 3;
	int n4 = 4;
	int n5 = 5;
	int n6 = 6;
	int n7 = 7;
	int n8 = 8;
	int n9 = 9;
	// 入队列
	list.ListInsert(0, &n1);
	list.ListTraverse();
	list.ListInsert(1, &n2);
	list.ListTraverse();
	list.ListInsert(2, &n3);
	list.ListTraverse();
	list.ListInsert(3, &n4);
	list.ListTraverse();
	list.ListInsert(4, &n5);
	list.ListTraverse();
	list.ListInsert(5, &n6);
	list.ListTraverse();
	list.ListInsert(6, &n7);
	list.ListTraverse();
	list.ListInsert(7, &n8);
	list.ListTraverse();
	list.ListInsert(8, &n9);
	list.ListTraverse();
	cout << "表长度:" << list.ListLength();
	// 获取指定位置元素
	int tmp;
	list.getElem(7, tmp);
	cout << "8号元素:" << tmp << endl;
	// 定位
	cout << "元素5的索引:" << list.locateElem(5) << endl;
	// 前驱
	int curr = 3;
	int prev;
	list.priorElem(&curr, &prev);
	cout << "元素3的前驱是:" << prev << endl;
	// 后继
	curr = 8;
	int next;
	list.nextElem(&curr, &next);
	cout << "元素8的 后继:" << next << endl;
	// 插入
	int n10 = 10;
	int n11 = 11;
	list.ListInsert(9, &n10);
	list.ListInsert(8, &n9);
	list.ListInsert(8, &n9);
	list.ListInsert(9,&n11);
	list.ListTraverse();
	// 删除
	list.ListDelete(4, &tmp);
	cout << "删除的元素：" << tmp << endl;
	list.ListInsert(5, &n5);
	list.ListTraverse();

	cout << "***********线性表-顺序表-Person***********"<< endl;
	List<Person> listPerson(3, comparePerson, visitPerson);
	Person p1(20,"张三");
	Person p2(22,"李四");
	Person p3(24,"王五");
	// 插入
	listPerson.ListInsert(0, &p1);
	listPerson.ListInsert(0, &p2);
	listPerson.ListInsert(0, &p3);
	listPerson.ListTraverse();
	cout << "表长度:" << listPerson.ListLength() << endl;
	// 获取指定位置元素
	Person tmpPerson;
	listPerson.getElem(2, tmpPerson);
	cout << "2号元素:" << tmpPerson.getName() << "," << tmpPerson.getAge() << endl;
	// 定位
	cout << "p2的索引:" << listPerson.locateElem(p2) << endl;
	// 前驱
	listPerson.priorElem(&p2, &tmpPerson);
	cout << "p2的前驱是:" << tmpPerson.getName() << "," << tmpPerson.getAge() << endl;
	// 后继
	listPerson.nextElem(&p2, &tmpPerson);
	cout << "p2的后继:" << tmpPerson.getName() << "," << tmpPerson.getAge() << endl;
	// 插入
	listPerson.ListInsert(0, &p3);
	listPerson.ListTraverse();
	// 删除
	listPerson.ListDelete(2, &tmpPerson);
	cout << "删除的元素：" << tmpPerson.getName() << "," << tmpPerson.getAge() << endl;
	listPerson.ListTraverse();

	return 0;
}
