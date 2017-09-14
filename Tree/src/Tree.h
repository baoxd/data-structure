/*
 * Tree.h
 *
 *  Created on: 2017��9��14��
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
	// ���ٶ�����
	void destory();
	// ��ն�����
	void clear();
	// �п�
	bool isEmpty();
	// ���������
	int depth();
	// ��ȡ�����ڵ�
	bool getRoot(Node<T> *node);
	// ��ȡ˫�׽ڵ�
	bool getParent(Node<T> *node, Node<T> *parentNode);
	// ��ȡ�ڵ�����
	bool getLChild(Node<T> *parentNode);
	// ��ȡ�Һ���
	bool getRChild(Node<T> *parentNode);
	// ��ȡ���ֵ�
	bool getLSibling(Node<T> *node);
	// ��ȡ���ֵ�
	bool getRSibling(Node<T> *node);
    // �����ӽڵ�
	bool insertChild(Node<T> *parentNode, char direction);
	// ɾ������
	bool deleteChild(Node<T> *parentNode, char direction);
	// ǰ�����
	void preOrderTraverse(void(*visit)(T));
	// �������
	void inOrderTraverse(void(*visit)(T));
	// �������
	void postOrderTraverse(void(*visit)(T));

private:
	// ͷ���
	Node<T> *m_pRoot;
	// �ڵ�ȽϺ���
	bool (*m_pCompare)(T, T);
	// �ڵ��ӡ����
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
