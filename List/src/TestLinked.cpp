/*
 * TestLinked.cpp
 *
 *  Created on: 2017��9��11��
 *      Author: baoxd
 */
#include <iostream>
#include "LinkedList.h"
using namespace std;

bool compareLinkedInt(int n, int m)
{
	return n == m ;
}

void visitLinkedInt(int n)
{
	cout << n << endl;
}


int main()
{
	cout << "***************����-��������**************" << endl;
	LinkedList<int> linkedList(compareLinkedInt, visitLinkedInt);

	Node<int> node1;
	node1.data = 1;
	Node<int> node2;
	node2.data = 2;
	Node<int> node3;
	node3.data = 3;
	Node<int> node4;
	node4.data = 4;

	// ����
	linkedList.ListInsert(0, &node1);
	linkedList.ListInsert(1, &node2);
	linkedList.ListInsert(2, &node3);
	linkedList.ListInsert(3, &node4);
	linkedList.ListTraverse();
	cout << "�����ȣ�" << linkedList.ListLength() << endl;
	// ��ȡָ��λ��Ԫ��
	Node<int> tmp;
	linkedList.getElem(2, &tmp);
	cout << "������Ԫ����:" << tmp.data << endl;
	// Ԫ�ض�λ
	cout << "node2�������е�λ��:" << linkedList.locateElem(&node2) << endl;
	// ��ȡǰ��
	linkedList.priorElem(&node2, &tmp);
	cout << "node2��ǰ����:" << tmp.data << endl;
	// ��ȡ���
	linkedList.nextElem(&node2, &tmp);
	cout << "node2�ĺ����:" << tmp.data << endl;
	// ɾ����һ���ڵ�
	linkedList.ListDelete(0, &tmp);
	cout << "��ɾ����Ԫ�أ�" << tmp.data << endl;
	linkedList.ListTraverse();
	// ����
	cout << "���²���" << endl;
	linkedList.ListInsert(0, &node1);
	linkedList.ListInsert(4, &node1);
	linkedList.ListInsert(5, &node2);
	linkedList.ListInsert(6, &node3);
	linkedList.ListInsert(7, &node4);
	linkedList.ListTraverse();
	// ɾ�����һ��
	linkedList.ListDelete(7, &tmp);
	cout << "��ɾ����Ԫ�أ�" << tmp.data << endl;
	linkedList.ListTraverse();
	// ɾ���м�Ԫ��
	linkedList.ListDelete(3, &tmp);
	cout << "��ɾ����Ԫ�أ�" << tmp.data << endl;
	linkedList.ListTraverse();
	// ��ȡ����
	cout << "ɾ����ĳ���:" << linkedList.ListLength() << endl;

	return 0;
}

