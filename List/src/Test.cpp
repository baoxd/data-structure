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
	cout << "����:" << p.getName() << " ����:" << p.getAge() << endl;
}

int main() {
	cout << "***********���Ա�-˳���-����***********"<< endl;
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
	// �����
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
	cout << "����:" << list.ListLength();
	// ��ȡָ��λ��Ԫ��
	int tmp;
	list.getElem(7, tmp);
	cout << "8��Ԫ��:" << tmp << endl;
	// ��λ
	cout << "Ԫ��5������:" << list.locateElem(5) << endl;
	// ǰ��
	int curr = 3;
	int prev;
	list.priorElem(&curr, &prev);
	cout << "Ԫ��3��ǰ����:" << prev << endl;
	// ���
	curr = 8;
	int next;
	list.nextElem(&curr, &next);
	cout << "Ԫ��8�� ���:" << next << endl;
	// ����
	int n10 = 10;
	int n11 = 11;
	list.ListInsert(9, &n10);
	list.ListInsert(8, &n9);
	list.ListInsert(8, &n9);
	list.ListInsert(9,&n11);
	list.ListTraverse();
	// ɾ��
	list.ListDelete(4, &tmp);
	cout << "ɾ����Ԫ�أ�" << tmp << endl;
	list.ListInsert(5, &n5);
	list.ListTraverse();

	cout << "***********���Ա�-˳���-Person***********"<< endl;
	List<Person> listPerson(3, comparePerson, visitPerson);
	Person p1(20,"����");
	Person p2(22,"����");
	Person p3(24,"����");
	// ����
	listPerson.ListInsert(0, &p1);
	listPerson.ListInsert(0, &p2);
	listPerson.ListInsert(0, &p3);
	listPerson.ListTraverse();
	cout << "����:" << listPerson.ListLength() << endl;
	// ��ȡָ��λ��Ԫ��
	Person tmpPerson;
	listPerson.getElem(2, tmpPerson);
	cout << "2��Ԫ��:" << tmpPerson.getName() << "," << tmpPerson.getAge() << endl;
	// ��λ
	cout << "p2������:" << listPerson.locateElem(p2) << endl;
	// ǰ��
	listPerson.priorElem(&p2, &tmpPerson);
	cout << "p2��ǰ����:" << tmpPerson.getName() << "," << tmpPerson.getAge() << endl;
	// ���
	listPerson.nextElem(&p2, &tmpPerson);
	cout << "p2�ĺ��:" << tmpPerson.getName() << "," << tmpPerson.getAge() << endl;
	// ����
	listPerson.ListInsert(0, &p3);
	listPerson.ListTraverse();
	// ɾ��
	listPerson.ListDelete(2, &tmpPerson);
	cout << "ɾ����Ԫ�أ�" << tmpPerson.getName() << "," << tmpPerson.getAge() << endl;
	listPerson.ListTraverse();

	return 0;
}
