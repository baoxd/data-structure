/*
 * LinkedList.h
 *
 *  Created on: 2017��9��11��
 *      Author: baoxd
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
#include "Node.h"
using namespace std;

template<class T>
class LinkedList{
public:
	LinkedList(bool (*compare)(T, T),void (*toString)(T));
	~LinkedList();
	// �������
	void clearList();
	// �п�
	bool isEmpty();
    // ������
	int ListLength();
	// ��ȡָ��λ��Ԫ��
	bool getElem(int index, Node<T> *node);
	// ��λ�ڵ�λ��
	int locateElem(Node<T> *node);
	// ��ȡǰ���ڵ�
	bool priorElem(Node<T> *currNode, Node<T> *prevNode);
	// ��ȡ���Ԫ��
	bool nextElem(Node<T> *currNode, Node<T> *nextNode);
	// ����ڵ�
	bool ListInsert(int index, Node<T> *node);
	// ɾ���ڵ�
	bool ListDelete(int index, Node<T> *node);
	// �����ڵ�
	void ListTraverse();
private:
	// ������
	int m_iLength;
	// ͷָ��
	Node<T> *m_pList;
	// �ڵ�ȽϺ���
	bool (*m_pCompare)(T, T);
	// �ڵ��ӡ����
	void (*m_pToString)(T);
};

template<class T>
LinkedList<T>::LinkedList(bool (*compare)(T, T), void (*toString)(T))
{
	m_pToString = toString;
	m_pCompare = compare;
	m_iLength = 0;
	m_pList = new Node<T>;
}

template<class T>
bool LinkedList<T>::isEmpty()
{
	return m_iLength == 0 ? true : false;
}

template<class T>
int LinkedList<T>::ListLength()
{
	return m_iLength;
}

template<class T>
void LinkedList<T>::clearList()
{
	if(!isEmpty())
	{
		Node<T> *currNode = m_pList->next;
		while(currNode != NULL)
		{
			Node<T> *tmp = currNode->next;
			delete currNode;
			currNode = tmp;
		}
		m_pList->next = NULL;
		m_iLength = 0;
	}
}

template<class T>
LinkedList<T>::~LinkedList()
{
	clearList();
	delete m_pList;
	m_pList = NULL;
}

template<class T>
bool LinkedList<T>::getElem(int index, Node<T> *node)
{
	if(isEmpty())
	{
		return false;
	}
	Node<T> *currNode = m_pList->next;
	for(int i = 0 ; i < index; i++)
	{
		currNode = currNode->next;
	}
	node->data = currNode->data;
	return false;
}

template<class T>
int LinkedList<T>::locateElem(Node<T> *node)
{
	if(isEmpty())
	{
		return -1;
	}
	Node<T> *currNode = m_pList->next;
	for(int i = 0 ; i < m_iLength ; i++)
	{
		if(m_pCompare(currNode->data, node->data))
		{
			return i;
		}
		currNode = currNode->next;
	}
	return -1;
}

template<class T>
bool LinkedList<T>::priorElem(Node<T> *currNode, Node<T> *prevNode)
{
	int currIndex = locateElem(currNode);
	if(currIndex == -1)
	{
		return false;
	}
	// ��һ��Ԫ��û��ǰ��
	if(currIndex == 0){
		return false;
	}
	Node<T> *tmp = m_pList->next;
	for(int i = 0; i < currIndex - 1 ; i++)
	{
		tmp = tmp->next;
	}
	prevNode->data = tmp->data;
	return true;
}

template<class T>
bool LinkedList<T>::nextElem(Node<T> *currNode, Node<T> *nextNode)
{
	int index = locateElem(currNode);
	if(index == -1)
	{
		return false;
	}
	// ���һ��Ԫ��û�к��
	if(index == m_iLength - 1)
	{
		return false;
	}
	Node<T> *tmp = m_pList->next;
	for(int i = 0 ; i < index + 1; i++)
	{
		tmp = tmp->next;
	}
	nextNode->data = tmp->data;
	return true;
}

template<class T>
bool LinkedList<T>::ListInsert(int index, Node<T> *node)
{
	if(index < 0 || index > m_iLength)
	{
		return false;
	}
	Node<T> *prev = m_pList;
	Node<T> *tmp = m_pList->next;
	for(int i = 0 ; i < index ;i++)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	Node<T> *curr = new Node<T>;
	curr->next = tmp;
	curr->data = node->data;
	prev->next = curr;
	m_iLength++;
	return true;
}

template<class T>
bool LinkedList<T>::ListDelete(int index, Node<T> *node)
{
	if(index < 0 || index > m_iLength - 1)
	{
		return false;
	}
	Node<T> *prev = m_pList;
	Node<T> *tmp = m_pList->next;
	for(int i = 0 ; i < index; i++)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	node->data = tmp->data;
	prev->next = tmp->next;
	delete tmp;
	tmp = NULL;
	m_iLength--;
	return true;
}

template<class T>
void LinkedList<T>::ListTraverse()
{
	if(!isEmpty())
	{
		Node<T> *curr = m_pList->next;
		for(int i = 0 ; i < m_iLength; i++)
		{
			m_pToString(curr->data);
			curr = curr->next;
		}
	}
}



#endif /* LINKEDLIST_H_ */
