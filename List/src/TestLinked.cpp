/*
 * TestLinked.cpp
 *
 *  Created on: 2017年9月11日
 *      Author: baoxd
 */
#include <iostream>
#include "LinkedList.h"
#include "Person.h"
using namespace std;

bool compareLinkedInt(int n, int m)
{
	return n == m ;
}

void visitLinkedInt(int n)
{
	cout << n << endl;
}

bool compareLinkedPerson(Person p1, Person p2)
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

void visitLinkedPerson(Person p)
{
	cout << "姓名:" << p.getName() << " 年龄:" << p.getAge() << endl;
}


//int main()
//{
//	cout << "***************链表-整形数据**************" << endl;
////	LinkedList<int> linkedList(compareLinkedInt, visitLinkedInt);
////
////	Node<int> node1;
////	node1.data = 1;
////	Node<int> node2;
////	node2.data = 2;
////	Node<int> node3;
////	node3.data = 3;
////	Node<int> node4;
////	node4.data = 4;
////
////	// 插入
////	linkedList.ListInsert(0, &node1);
////	linkedList.ListInsert(1, &node2);
////	linkedList.ListInsert(2, &node3);
////	linkedList.ListInsert(3, &node4);
////	linkedList.ListTraverse();
////	cout << "链表长度：" << linkedList.ListLength() << endl;
////	// 获取指定位置元素
////	Node<int> tmp;
////	linkedList.getElem(2, &tmp);
////	cout << "第三号元素是:" << tmp.data << endl;
////	// 元素定位
////	cout << "node2在链表中的位置:" << linkedList.locateElem(&node2) << endl;
////	// 获取前驱
////	linkedList.priorElem(&node2, &tmp);
////	cout << "node2的前驱是:" << tmp.data << endl;
////	// 获取后继
////	linkedList.nextElem(&node2, &tmp);
////	cout << "node2的后继是:" << tmp.data << endl;
////	// 删除第一个节点
////	linkedList.ListDelete(0, &tmp);
////	cout << "被删除的元素：" << tmp.data << endl;
////	linkedList.ListTraverse();
////	// 插入
////	cout << "重新插入" << endl;
////	linkedList.ListInsert(0, &node1);
////	linkedList.ListInsert(4, &node1);
////	linkedList.ListInsert(5, &node2);
////	linkedList.ListInsert(6, &node3);
////	linkedList.ListInsert(7, &node4);
////	linkedList.ListTraverse();
////	// 删除最后一个
////	linkedList.ListDelete(7, &tmp);
////	cout << "被删除的元素：" << tmp.data << endl;
////	linkedList.ListTraverse();
////	// 删除中间元素
////	linkedList.ListDelete(3, &tmp);
////	cout << "被删除的元素：" << tmp.data << endl;
////	linkedList.ListTraverse();
////	// 获取长度
////	cout << "删除后的长度:" << linkedList.ListLength() << endl;
//
//
//	cout << "***************链表-Person**************" << endl;
//	LinkedList<Person> linkedPerson(compareLinkedPerson, visitLinkedPerson);
//	Person p1(20, "张三");
//	Person p2(22, "李四");
//	Person p3(24, "王五");
//	Node<Person> node1;
//	node1.data = p1;
//	Node<Person> node2;
//	node2.data = p2;
//	Node<Person> node3;
//	node3.data = p3;
//	// 插入
//	linkedPerson.ListInsert(0, &node1);
//	linkedPerson.ListInsert(1, &node2);
//	linkedPerson.ListInsert(2, &node3);
//	linkedPerson.ListTraverse();
//	cout << "链表长度：" << linkedPerson.ListLength() << endl;
//	// 获取指定位置元素
//	Node<Person> tmp;
//	linkedPerson.getElem(2, &tmp);
//	cout << "第三号节点数据是：";
//	visitLinkedPerson(tmp.data);
//	// 元素定位
//	cout << "node2在链表中的位置:" << linkedPerson.locateElem(&node2) << endl;
//	// 获取前驱
//	linkedPerson.priorElem(&node2, &tmp);
//	cout << "node2的前驱是:" ;
//	visitLinkedPerson(tmp.data);
//	// 获取后继
//	linkedPerson.nextElem(&node2, &tmp);
//	cout << "node2的后继是:" ;
//	visitLinkedPerson(tmp.data);
//	// 删除第一个节点
//	linkedPerson.ListDelete(0, &tmp);
//	cout << "被删除的节点：";
//	visitLinkedPerson(tmp.data);
//	linkedPerson.ListTraverse();
//	// 插入
//	cout << "重新插入" << endl;
//	linkedPerson.ListInsert(0, &node1);
//	linkedPerson.ListInsert(3, &node1);
//	linkedPerson.ListInsert(4, &node2);
//	linkedPerson.ListInsert(5, &node3);
//	linkedPerson.ListTraverse();
//	// 删除最后一个
//	linkedPerson.ListDelete(5, &tmp);
//	cout << "被删除的元素：";
//	visitLinkedPerson(tmp.data);
//	linkedPerson.ListTraverse();
//	// 删除中间元素
//	linkedPerson.ListDelete(2, &tmp);
//	cout << "被删除的元素：" ;
//	visitLinkedPerson(tmp.data);
//	linkedPerson.ListTraverse();
//	// 获取长度
//	cout << "删除后的长度:" << linkedPerson.ListLength() << endl;
//
//	return 0;
//}

