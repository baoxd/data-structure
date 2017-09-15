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
 * 二叉树
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

	// 插入节点
	tree.insertChild(1, '2', '0');
	tree.insertChild(1, '3', '1');
	tree.insertChild(2, '4', '0');
	tree.insertChild(2, '5', '1');
	tree.insertChild(3, '6', '0');
	tree.insertChild(3, '7', '1');
	tree.insertChild(4, '8', '0');
	tree.insertChild(4, '9', '1');

	// 获取父节点
	tree.getParent(4, tmp);
	cout << "4的父节点是：" << tmp->m_data << endl;
	// 获取左孩子
	tree.getLChild(4, tmp);
	cout << "4的左孩子是：" << tmp->m_data << endl;
	// 获取右孩子
	tree.getRChild(2, tmp);
	cout << "2的右孩子是：" << tmp->m_data << endl;
	// 获取左兄弟节点
	tree.getLSibling(7, tmp);
	cout << "7的左兄弟节点:" << tmp->m_data << endl;
	// 获取右兄弟节点
	tree.getRSibling(8, tmp);
	cout << "8的右兄弟节点：" << tmp->m_data << endl;
	// 前序遍历
	tree.preOrderTraverse();
	cout << endl;
	// 中序遍历
	tree.inOrderTraverse();
	cout << endl;
	// 后序遍历
	tree.postOrderTraverse();
	cout << endl;
	// 删除2节点
	tree.deleteChild(1, '0');
	cout << "删除节点2" << endl;
	// 前序遍历
	tree.preOrderTraverse();
	cout << endl;
	cout << "深度：" << tree.depth() << endl;
	cout << "isEmpty：" << tree.isEmpty() << endl;
	tree.getRoot(tmp);
	cout << "根节点:" << tmp->m_data << endl;
	tree.clear();
	cout << "深度：" << tree.depth() << endl;
	cout << "isEmpty：" << tree.isEmpty() << endl;

	delete tmp;
}


//int main() {
//	// 测试字符串
//	testChar();
//	return 0;
//}
