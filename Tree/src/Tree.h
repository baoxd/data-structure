/*
 * Tree.h
 *
 *  Created on: 2017年9月14日
 *      Author: baoxd
 */

#ifndef TREE_H_
#define TREE_H_
#include "Node.h"

template<class T>
class Tree{
public:
	Tree(Node<T> *node, bool (*compare)(T, T) = NULL,void (*toString)(T) = NULL);
	~Tree();
	// 销毁二叉树
	void destory();
	// 清空二叉树
	void clear();
	// 判空
	bool isEmpty();
	// 二叉树深度
	int depth();
	// 获取树根节点
	bool getRoot(Node<T> *node);
	// 获取双亲节点
	bool getParent(Node<T> *node, Node<T> *parentNode);
	// 获取节点左孩子
	bool getLChild(Node<T> *parentNode);
	// 获取右孩子
	bool getRChild(Node<T> *parentNode);
	// 获取左兄弟
	bool getLSibling(Node<T> *node);
	// 获取右兄弟
	bool getRSibling(Node<T> *node);
    // 插入子节点
	bool insertChild(Node<T> *parentNode, char direction);
	// 删除子树
	bool deleteChild(Node<T> *parentNode, char direction);
	// 前序遍历
	void preOrderTraverse(void(*visit)(T));
	// 中序遍历
	void inOrderTraverse(void(*visit)(T));
	// 后序遍历
	void postOrderTraverse(void(*visit)(T));

private:
	// 头结点
	Node<T> *m_pRoot;
	// 节点比较函数
	bool (*m_pCompare)(T, T);
	// 节点打印函数
	void (*m_pToString)(T);
};

template<class T>
Tree<T>::Tree(Node<T> *node, bool (*compare)(T, T),void (*toString)(T))
{
	m_pRoot = new Node<T>;
	if(node != NULL)
	{
		m_pRoot->data = node->data;
	}
	m_pCompare = compare;
	m_pToString = toString;
}

template<class T>
void Tree<T>::clear()
{
	if(m_pRoot != NULL)
	{
		if(m_pRoot->lChild != NULL)
		{
			m_pRoot->lChild->clear();
		}
		if(m_pRoot->rChild)
		{
			m_pRoot->rChild->clear();
		}
	}
}

template<class T>
void Tree<T>::destory()
{
	clear();
	if(m_pRoot != NULL)
	{
		delete m_pRoot;
	}
}

template<class T>
Tree<T>::~Tree()
{
	destory();
}

template<class T>
bool Tree<T>::isEmpty()
{
	return m_pRoot == NULL ? true : false;
}

template<class T>
int Tree<T>::depth()
{
	if(m_pRoot == NULL)
	{
		return  0;
	}
	Node<T> *lChild = m_pRoot->lChild;
	Node<T> *rChild = m_pRoot->rChild;
	int num = 1;

	while(lChild != NULL || rChild != NULL)
	{
		num++;
		if(lChild)
		{
			lChild = lChild->lChild;
		}
		if(rChild)
		{
			rChild = rChild->rChild;
		}
	}
	return num;
}

template<class T>
bool Tree<T>::getRoot(Node<T> *node)
{
	if(m_pRoot == NULL)
	{
		return false;
	}
	node->data = m_pRoot->data;
	node->lChild = m_pRoot->lChild;
	node->rChild = m_pRoot->rChild;
	return true;
}



#endif /* TREE_H_ */
