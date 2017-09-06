/*
 * circularQueue.h
 *
 *  Created on: 2017��9��6��
 *      Author: baoxd
 */

#ifndef CIRCULARQUEUE_H_
#define CIRCULARQUEUE_H_
#include <iostream>
#include <string>

using namespace std;

template<class T>
class CircularQueue{
public:
	// ���캯��
	CircularQueue(int capacity);
	// ��������
	virtual ~CircularQueue();
	// �������
	void clearQueue();
	// ���
	bool enQueue(T element);
	// ����
	bool deQueue(T &element);
	// �п�
	bool isEmpty();
	// ����
	bool isFull();
	// ���г���
	int length();
	// ��ӡ����
	void printQueue(void(*Func)(T));

private:
	// ��������ָ��
	T *m_pQueue;
	// ��������
	int m_iCapacity;
	// ����ͷ
	int m_iHead;
	// ����β
	int m_iTail;
	// ���г���
	int m_iLength;
};

template<class T>
CircularQueue<T>::CircularQueue(int capacity)
{
	m_pQueue = new T[capacity];
	m_iCapacity = capacity;
	clearQueue();
	if(m_pQueue == NULL){
		throw string("�����ڴ����ʧ��");
	}
}

template<class T>
CircularQueue<T>::~CircularQueue()
{
	delete []m_pQueue;
	m_pQueue = NULL;
}

template<class T>
void CircularQueue<T>::clearQueue()
{
	m_iHead = 0;
	m_iTail = 0;
	m_iLength = 0;
}

template<class T>
bool CircularQueue<T>::isEmpty()
{
	return m_iLength == 0 ? true : false;
}

template<class T>
bool CircularQueue<T>::isFull()
{
	return m_iLength == m_iCapacity ? true : false;
}

template <class T>
int CircularQueue<T>::length()
{
	return m_iLength;
}

template<class T>
bool CircularQueue<T>::enQueue(T element)
{
	if(isFull()){
		return false;
	}
	m_pQueue[m_iTail] = element;
	m_iTail++;
	m_iLength++;
	m_iTail = m_iTail % m_iCapacity;
	return true;
}

template<class T>
bool CircularQueue<T>::deQueue(T &element)
{
	if(isEmpty()){
		return false;
	}
	element = m_pQueue[m_iHead];
	m_iHead++;
	m_iLength--;
	m_iHead = m_iHead % m_iCapacity;
	return true;
}

template<class T>
void CircularQueue<T>::printQueue(void(*Func)(T)){
	if(isEmpty()){
	}
	for(int i = m_iHead; i < m_iHead + m_iLength ; i++){
		Func(m_pQueue[i % m_iCapacity]);
	}
}




#endif /* CIRCULARQUEUE_H_ */
