//============================================================================
// Name        : Tree.cpp
// Author      : baoxd
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Tree.h"
#include "Node.h"

/**
 * ������
 *
 * 		    	   1(1)
 *
 *
 * 	   		 2(2)	     3(3)
 *
 *
 *  	4(4)    5(5)   6(6)    7(7)
 *
 *  8(8)   9(9)
 */


void toString(char c)
{
	cout << c ;
}

void testChar()
{
	Node<char> *node1 = new Node<char>;
	node1->m_data = '1';
	node1->m_iIndex = 1;

	Node<char> *tmp = new Node<char>;
	Tree<char> tree(node1, toString);

	// ����ڵ�
	tree.insertChild(1, '2', '0');
	tree.insertChild(1, '3', '1');
	tree.insertChild(2, '4', '0');
	tree.insertChild(2, '5', '1');
	tree.insertChild(3, '6', '0');
	tree.insertChild(3, '7', '1');
	tree.insertChild(4, '8', '0');
	tree.insertChild(4, '9', '1');

	// ��ȡ���ڵ�
	tree.getParent(4, tmp);
	cout << "4�ĸ��ڵ��ǣ�" << tmp->m_data << endl;
	// ��ȡ����
	tree.getLChild(4, tmp);
	cout << "4�������ǣ�" << tmp->m_data << endl;
	// ��ȡ�Һ���
	tree.getRChild(2, tmp);
	cout << "2���Һ����ǣ�" << tmp->m_data << endl;
	// ��ȡ���ֵܽڵ�
	tree.getLSibling(7, tmp);
	cout << "7�����ֵܽڵ�:" << tmp->m_data << endl;
	// ��ȡ���ֵܽڵ�
	tree.getRSibling(8, tmp);
	cout << "8�����ֵܽڵ㣺" << tmp->m_data << endl;
	// ǰ�����
	tree.preOrderTraverse();
	cout << endl;
	// �������
	tree.inOrderTraverse();
	cout << endl;
	// �������
	tree.postOrderTraverse();
	cout << endl;
	// ɾ��2�ڵ�
	tree.deleteChild(1, '0');
	cout << "ɾ���ڵ�2" << endl;
	// ǰ�����
	tree.preOrderTraverse();
	cout << endl;
	cout << "��ȣ�" << tree.depth() << endl;
	cout << "isEmpty��" << tree.isEmpty() << endl;
	tree.getRoot(tmp);
	cout << "���ڵ�:" << tmp->m_data << endl;
	tree.clear();
	cout << "��ȣ�" << tree.depth() << endl;
	cout << "isEmpty��" << tree.isEmpty() << endl;

	delete tmp;
}


//int main() {
//	// �����ַ���
//	testChar();
//	return 0;
//}
