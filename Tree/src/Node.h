/*
 * Node.h
 *
 *  Created on: 2017年9月14日
 *      Author: baoxd
 */

#ifndef NODE_H_
#define NODE_H_
#include <iostream>

template<class T>
class Node{
public:
	Node();
	~Node();
	// 查询节点
	Node<T> *searchNode(int currIndex);
	// 删除节点
	void deleteNode();
	// 前序遍历
	void preOrderTraverse(void(*toString)(T));
	// 中序遍历
	void inOrderTraverse(void(*toString)(T));
	// 后序遍历
	void postOrderTraverse(void(*toString)(T));
public:
	int m_iIndex;
	T m_data;
	Node<T> *m_pLChild;
	Node<T> *m_pRChild;
	Node<T> *m_pParent;
};

template<class T>
Node<T>::Node()
{
	m_iIndex = 0;
	m_pLChild = NULL;
	m_pRChild = NULL;
	m_pParent = NULL;
}

template<class T>
Node<T>::~Node()
{
//	delete();
}

template<class T>
Node<T> *Node<T>::searchNode(int currIndex)
{
	if(this->m_iIndex == currIndex)
	{
		return this;
	}
	Node<T> *node = NULL;
	if(this->m_pLChild != NULL)
	{
		node = this->m_pLChild->searchNode(currIndex);
	}
	if(node == NULL && this->m_pRChild !=NULL)
	{
		node = this->m_pRChild->searchNode(currIndex);
	}
	return node;
}

template<class T>
void Node<T>::deleteNode()
{
	if(this->m_pLChild)
	{
		this->m_pLChild->deleteNode();
	}
	if(this->m_pRChild)
	{
		this->m_pRChild->deleteNode();
	}
	if(this->m_pRChild)
	{
		if(this->m_pParent->m_pLChild == this)
		{
			this->m_pParent->m_pLChild = NULL;
		}
		if(this->m_pParent->m_pRChild == this)
		{
			this->m_pParent->m_pRChild = NULL;
		}
	}
	delete this;
}

template<class T>
void Node<T>::preOrderTraverse(void(*toString)(T))
{
	toString(this->m_data);
	if(this->m_pLChild != NULL)
	{
		this->m_pLChild->preOrderTraverse(toString);
	}
	if(this->m_pRChild != NULL)
	{
		this->m_pRChild->preOrderTraverse(toString);
	}
}

template<class T>
void Node<T>::inOrderTraverse(void(*toString)(T))
{
	if(this->m_pLChild !=NULL)
	{
		this->m_pLChild->inOrderTraverse(toString);
	}
	toString(this->m_data);
	if(this->m_pRChild)
	{
		this->m_pRChild->inOrderTraverse(toString);
	}
}

template<class T>
void Node<T>::postOrderTraverse(void(*toString)(T))
{
	if(this->m_pLChild !=NULL)
	{
		this->m_pLChild->inOrderTraverse(toString);
	}
	if(this->m_pRChild)
	{
		this->m_pRChild->inOrderTraverse(toString);
	}
	toString(this->m_data);
}

#endif /* NODE_H_ */
