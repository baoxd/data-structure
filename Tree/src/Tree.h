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
	Tree(Node<T> *node = NULL, void (*toString)(T) = NULL);
	~Tree();
	// ��ն�����
	void clear();
	// �п�
	bool isEmpty();
	// ���������
	int depth();
	// ��ѯָ�������ڵ�
	Node<T> *searchNode(int currIndex);
	// ��ȡ�����ڵ�
	bool getRoot(Node<T> *node);
	// ��ȡ˫�׽ڵ�
	bool getParent(int childIndex, Node<T> *parentNode);
	// ��ȡ�ڵ�����
	bool getLChild(int parentIndex, Node<T> *lChild);
	// ��ȡ�Һ���
	bool getRChild(int parentIndex, Node<T> *rChild);
	// ��ȡ���ֵ�
	bool getLSibling(int rIndex, Node<T> *lSibling);
	// ��ȡ���ֵ�
	bool getRSibling(int lIndex, Node<T> *rSibling);
    // �����ӽڵ�
	bool insertChild(int parentIndex, T t, char direction);
	// ɾ������
	bool deleteChild(int parentIndex, char direction);
	// ǰ�����
	void preOrderTraverse();
	// �������
	void inOrderTraverse();
	// �������
	void postOrderTraverse();
	// ���������ڵ�
	void setRoot(Node<T> *root);

private:
	// ͷ���
	Node<T> *m_pRoot;
	// �ڵ��ӡ����
	void (*m_pToString)(T);
};

template<class T>
Tree<T>::Tree(Node<T> *node, void (*toString)(T))
{
	m_pRoot = new Node<T>;
	if(node != NULL)
	{
		m_pRoot->m_data = node->m_data;
		m_pRoot->m_iIndex = node->m_iIndex;
	}
	m_pToString = toString;
}

template<class T>
void Tree<T>::setRoot(Node<T> *root)
{
	m_pRoot->m_data = root->m_data;
	m_pRoot->m_iIndex = root->m_iIndex;
	m_pRoot->m_pLChild = root->m_pLChild;
	m_pRoot->m_pParent = NULL;
	m_pRoot->m_pRChild = root->m_pRChild;
}

template<class T>
Node<T> * Tree<T>::searchNode(int currIndex)
{
	Node<T> *node = m_pRoot->searchNode(currIndex);
	return node;
}

template<class T>
bool Tree<T>::deleteChild(int parentIndex, char direction)
{
	Node<T> *parentNode = searchNode(parentIndex);
	if(parentNode == NULL)
	{
		return false;
	}
	// ɾ��������
	if(direction == '0' && parentNode->m_pLChild != NULL)
	{
		parentNode->m_pLChild->deleteNode();
	}
	// ɾ��������
	if(direction == '1' && parentNode->m_pRChild != NULL)
	{
		parentNode->m_pRChild->deleteNode();
	}
	return true;
}

template<class T>
void Tree<T>::clear()
{
	if(m_pRoot != NULL)
	{
		m_pRoot->deleteNode();
		m_pRoot = NULL;
	}
}


template<class T>
Tree<T>::~Tree()
{
	clear();
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
	Node<T> *lChild = m_pRoot->m_pLChild;
	Node<T> *rChild = m_pRoot->m_pRChild;
	int num = 1;

	while(lChild != NULL || rChild != NULL)
	{
		num++;
		if(lChild)
		{
			lChild = lChild->m_pLChild;
		}
		if(rChild)
		{
			rChild = rChild->m_pRChild;
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
	node->m_data = m_pRoot->m_data;
	node->m_iIndex = m_pRoot->m_iIndex;
	node->m_pLChild = m_pRoot->m_pLChild;
	node->m_pRChild = m_pRoot->m_pRChild;
	node->m_pParent = m_pRoot->m_pParent;
	return true;
}

template<class T>
bool Tree<T>::insertChild(int parentIndex, T t, char direction)
{
	Node<T> *parentNode = searchNode(parentIndex);
	if(parentNode == NULL)
	{
		return false;
	}
	Node<T> *tmp;
	// �����ڵ�
	if(direction == '0')
	{
		if(parentNode->m_pLChild != NULL)
		{
			// �Ѵ���������
			return false;
		}
		tmp = new Node<T>;
		parentNode->m_pLChild = tmp;
		tmp->m_data = t;
		tmp->m_iIndex = 2 * parentIndex;
		tmp->m_pParent = parentNode;
	}
	// ���������
	if(direction == '1')
	{
		if(parentNode->m_pRChild != NULL)
		{
			// �Ѵ���������
			return false;
		}
		tmp = new Node<T>;
		parentNode->m_pRChild = tmp;
		tmp->m_data = t;
		tmp->m_iIndex = 2 * parentIndex + 1;
		tmp->m_pParent = parentNode;
	}
	return true;
}

template<class T>
bool Tree<T>::getParent(int childIndex, Node<T> *parentNode)
{
	Node<T> *childNode = searchNode(childIndex);
	if(childNode == NULL)
	{
		return false;
	}
	if(childNode->m_pParent == NULL)
	{
		return false;
	}
	parentNode->m_data = childNode->m_pParent->m_data;
	parentNode->m_iIndex = childNode->m_pParent->m_iIndex;
	return true;
}

template<class T>
bool Tree<T>::getLChild(int parentIndex, Node<T> *lChild)
{
	Node<T> *parentNode = searchNode(parentIndex);
	if(parentNode == NULL)
	{
		return false;
	}
	if(parentNode->m_pLChild == NULL)
	{
		return false;
	}
	lChild->m_data = parentNode->m_pLChild->m_data;
	lChild->m_iIndex = parentNode->m_pLChild->m_iIndex;
	return true;
}

template<class T>
bool Tree<T>::getRChild(int parentIndex, Node<T> *rChild)
{
	Node<T> *parentNode = searchNode(parentIndex);
	if(parentNode == NULL)
	{
		return false;
	}
	if(parentNode->m_pRChild == NULL)
	{
		return false;
	}
	rChild->m_data = parentNode->m_pRChild->m_data;
	rChild->m_iIndex = parentNode->m_pRChild->m_iIndex;
	return true;
}

template<class T>
bool Tree<T>::getLSibling(int rIndex, Node<T> *lSibling)
{
	Node<T> *rChild = searchNode(rIndex);
	if(rChild == NULL)
	{
		return false;
	}
	// ���ڵ�
	if(rChild->m_pParent == NULL)
	{
		return false;
	}
	// ���������ڵ�
	if(rChild->m_pParent->m_pLChild == rChild)
	{
		return false;
	}
	lSibling->m_data = rChild->m_pParent->m_pLChild->m_data;
	lSibling->m_iIndex = rChild->m_pParent->m_pLChild->m_iIndex;
	return true;
}

template<class T>
bool Tree<T>::getRSibling(int lIndex, Node<T> *rSibling)
{
	Node<T> *lChild = searchNode(lIndex);
	if(lChild == NULL)
	{
		return false;
	}
	// ���ڵ�
	if(lChild->m_pParent == NULL)
	{
		return false;
	}
	// �������ҽڵ�
	if(lChild->m_pParent->m_pRChild == lChild)
	{
		return false;
	}
	rSibling->m_data = lChild->m_pParent->m_pRChild->m_data;
	rSibling->m_iIndex = lChild->m_pParent->m_pRChild->m_iIndex;
	return true;
}

template<class T>
void Tree<T>::preOrderTraverse()
{
	m_pRoot->preOrderTraverse(m_pToString);
}

template<class T>
void Tree<T>::inOrderTraverse()
{
	m_pRoot->inOrderTraverse(m_pToString);
}

template<class T>
void Tree<T>::postOrderTraverse()
{
	m_pRoot->postOrderTraverse(m_pToString);
}


#endif /* TREE_H_ */
