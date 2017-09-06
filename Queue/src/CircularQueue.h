/*
 * circularQueue.h
 *
 *  Created on: 2017年9月6日
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
	// 构造函数
	CircularQueue(int capacity);
	// 析构函数
	virtual ~CircularQueue();
	// 清除队列
	void clearQueue();
	// 入队
	bool enQueue(T element);
	// 出队
	bool deQueue(T &element);
	// 判空
	bool isEmpty();
	// 判满
	bool isFull();
	// 队列长度
	int length();
	// 打印队列
	void printQueue(void(*Func)(T));

private:
	// 队列数组指针
	T *m_pQueue;
	// 队列容量
	int m_iCapacity;
	// 队列头
	int m_iHead;
	// 队列尾
	int m_iTail;
	// 队列长度
	int m_iLength;
};

template<class T>
CircularQueue<T>::CircularQueue(int capacity)
{
	m_pQueue = new T[capacity];
	m_iCapacity = capacity;
	clearQueue();
	if(m_pQueue == NULL){
		throw string("队列内存分配失败");
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
