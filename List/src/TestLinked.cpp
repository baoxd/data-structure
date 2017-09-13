/*
 * TestLinked.cpp
 *
 *  Created on: 2017��9��11��
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
	cout << "����:" << p.getName() << " ����:" << p.getAge() << endl;
}


//int main()
//{
//	cout << "***************����-��������**************" << endl;
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
////	// ����
////	linkedList.ListInsert(0, &node1);
////	linkedList.ListInsert(1, &node2);
////	linkedList.ListInsert(2, &node3);
////	linkedList.ListInsert(3, &node4);
////	linkedList.ListTraverse();
////	cout << "�����ȣ�" << linkedList.ListLength() << endl;
////	// ��ȡָ��λ��Ԫ��
////	Node<int> tmp;
////	linkedList.getElem(2, &tmp);
////	cout << "������Ԫ����:" << tmp.data << endl;
////	// Ԫ�ض�λ
////	cout << "node2�������е�λ��:" << linkedList.locateElem(&node2) << endl;
////	// ��ȡǰ��
////	linkedList.priorElem(&node2, &tmp);
////	cout << "node2��ǰ����:" << tmp.data << endl;
////	// ��ȡ���
////	linkedList.nextElem(&node2, &tmp);
////	cout << "node2�ĺ����:" << tmp.data << endl;
////	// ɾ����һ���ڵ�
////	linkedList.ListDelete(0, &tmp);
////	cout << "��ɾ����Ԫ�أ�" << tmp.data << endl;
////	linkedList.ListTraverse();
////	// ����
////	cout << "���²���" << endl;
////	linkedList.ListInsert(0, &node1);
////	linkedList.ListInsert(4, &node1);
////	linkedList.ListInsert(5, &node2);
////	linkedList.ListInsert(6, &node3);
////	linkedList.ListInsert(7, &node4);
////	linkedList.ListTraverse();
////	// ɾ�����һ��
////	linkedList.ListDelete(7, &tmp);
////	cout << "��ɾ����Ԫ�أ�" << tmp.data << endl;
////	linkedList.ListTraverse();
////	// ɾ���м�Ԫ��
////	linkedList.ListDelete(3, &tmp);
////	cout << "��ɾ����Ԫ�أ�" << tmp.data << endl;
////	linkedList.ListTraverse();
////	// ��ȡ����
////	cout << "ɾ����ĳ���:" << linkedList.ListLength() << endl;
//
//
//	cout << "***************����-Person**************" << endl;
//	LinkedList<Person> linkedPerson(compareLinkedPerson, visitLinkedPerson);
//	Person p1(20, "����");
//	Person p2(22, "����");
//	Person p3(24, "����");
//	Node<Person> node1;
//	node1.data = p1;
//	Node<Person> node2;
//	node2.data = p2;
//	Node<Person> node3;
//	node3.data = p3;
//	// ����
//	linkedPerson.ListInsert(0, &node1);
//	linkedPerson.ListInsert(1, &node2);
//	linkedPerson.ListInsert(2, &node3);
//	linkedPerson.ListTraverse();
//	cout << "�����ȣ�" << linkedPerson.ListLength() << endl;
//	// ��ȡָ��λ��Ԫ��
//	Node<Person> tmp;
//	linkedPerson.getElem(2, &tmp);
//	cout << "�����Žڵ������ǣ�";
//	visitLinkedPerson(tmp.data);
//	// Ԫ�ض�λ
//	cout << "node2�������е�λ��:" << linkedPerson.locateElem(&node2) << endl;
//	// ��ȡǰ��
//	linkedPerson.priorElem(&node2, &tmp);
//	cout << "node2��ǰ����:" ;
//	visitLinkedPerson(tmp.data);
//	// ��ȡ���
//	linkedPerson.nextElem(&node2, &tmp);
//	cout << "node2�ĺ����:" ;
//	visitLinkedPerson(tmp.data);
//	// ɾ����һ���ڵ�
//	linkedPerson.ListDelete(0, &tmp);
//	cout << "��ɾ���Ľڵ㣺";
//	visitLinkedPerson(tmp.data);
//	linkedPerson.ListTraverse();
//	// ����
//	cout << "���²���" << endl;
//	linkedPerson.ListInsert(0, &node1);
//	linkedPerson.ListInsert(3, &node1);
//	linkedPerson.ListInsert(4, &node2);
//	linkedPerson.ListInsert(5, &node3);
//	linkedPerson.ListTraverse();
//	// ɾ�����һ��
//	linkedPerson.ListDelete(5, &tmp);
//	cout << "��ɾ����Ԫ�أ�";
//	visitLinkedPerson(tmp.data);
//	linkedPerson.ListTraverse();
//	// ɾ���м�Ԫ��
//	linkedPerson.ListDelete(2, &tmp);
//	cout << "��ɾ����Ԫ�أ�" ;
//	visitLinkedPerson(tmp.data);
//	linkedPerson.ListTraverse();
//	// ��ȡ����
//	cout << "ɾ����ĳ���:" << linkedPerson.ListLength() << endl;
//
//	return 0;
//}

