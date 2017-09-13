/*
 * SeqList.h
 *
 *  Created on: 2017��9��8��
 *      Author: baoxd
 */

#ifndef SEQLIST_H_
#define SEQLIST_H_
#include <iostream>
#include <string.h>
//typedef bool (FuncType)(int,int);
//typedef void (FuncType2)(int);

using namespace std;

/**
 *  ���Ա� -- ˳���
 */
template<class T>
class List{
public:
	List(int size, bool (*compare)(T, T) = NULL, void (*toString)(T) = NULL);
	virtual ~List();
	// �������
	void clearList();
	// �п�
	bool isEmpty();
	// ������
	int ListLength();
	// ��ȡָ��λ��Ԫ��
	bool getElem(int i, T &elem);
	// ��λԪ��λ��
	int locateElem(T elem);
	// ��ȡǰ��
	bool priorElem(T *currentElem, T *preElem);
	// ��ȡ���
	bool nextElem(T *currentElem, T *nextElem);
	// ����
	bool ListInsert(int i, T *elem);
	// ɾ��
	bool ListDelete(int i, T *elem);
	// ����
	void ListTraverse();
private:
	T *m_pList;
	int m_iSize;
	int m_iLength;
//	FuncType *m_pCompare;
//	FuncType2 *m_pToString;
	bool (*m_pCompare)(T, T);
	void (*m_pToString)(T);
};

template<class T>
List<T>::List(int size,bool (*compare)(T, T), void (*toString)(T))
{
	m_pList = new T[size];
	m_iSize = size;
	m_iLength = 0;
	// �Զ���ȽϺ���
	m_pCompare = compare;
	// �Զ����ӡ����
	m_pToString = toString;
}

template<class T>
List<T>::~List()
{
	delete []m_pList;
	m_pList = NULL;
}

template<class T>
void List<T>::clearList()
{
	m_iSize = 0;
	m_iLength = 0;
}

template<class T>
bool List<T>::isEmpty()
{
	return m_iLength == 0 ? true : false;
}

template<class T>
int List<T>::ListLength()
{
	return m_iLength;
}

template<class T>
bool List<T>::getElem(int i, T &elem)
{
	if(i >= m_iLength || i < 0)
	{
		throw string("�����±�Խ��");
		return false;
	}
	else
	{
		elem = m_pList[i];
		return true;
	}
}

template<class T>
int List<T>::locateElem(T elem)
{
	for(int i = 0 ; i < m_iLength; i++)
	{
		if(m_pCompare(m_pList[i], elem))
		{
			return i;
		}
	}
	return -1;
}

template<class T>
bool List<T>::priorElem(T *currentElem, T *preElem)
{
	int currIndex = locateElem(*currentElem);
	if(currIndex == -1 || currIndex == 0)
	{
		return false;
	}
	(*preElem) = m_pList[currIndex - 1];
	return true;
}

template<class T>
bool List<T>::nextElem(T *currentElem, T *nextElem)
{
	int currIndex = locateElem(*currentElem);
	if(currIndex == -1 || currIndex == m_iLength - 1)
	{
		return false;
	}
	(*nextElem) = m_pList[currIndex + 1];
	return true;
}

template<class T>
bool List<T>::ListInsert(int i, T *elem)
{
	if(i < 0 || i > m_iLength || i >= m_iSize)
	{
		return false;
	}
	if(m_iLength >= m_iSize)
	{
		return false;
	}
	for(int j = m_iLength ; j > i ; j-- )
	{
		m_pList[j] = m_pList[j-1];
	}
	m_pList[i] = (*elem);
	m_iLength++;
	return true;
}

template<class T>
bool List<T>::ListDelete(int i, T *elem)
{
	if(i<0 || i>=m_iLength)
	{
		return false;
	}
	(*elem) = m_pList[i];

	for(int j = i + 1; j < m_iLength ;j++ )
	{
		m_pList[j - 1] = m_pList[j];
	}
	m_iLength--;
	return true;
}

template<class T>
void List<T>::ListTraverse()
{
	if(!isEmpty())
	{
		for(int i = 0 ; i < m_iLength ; i++)
		{
			m_pToString(m_pList[i]);
		}
		cout << endl;
	}
}



#endif /* SEQLIST_H_ */
