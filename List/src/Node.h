/*
 * Node.h
 *
 *  Created on: 2017��9��11��
 *      Author: baoxd
 */

#ifndef NODE_H_
#define NODE_H_
#include <iostream>

/**
 *  ����ڵ�
 */

template<class T>
class Node{
public:
	Node();
	~Node();
	// ��Žڵ�����
public:
	T data;
	Node *next;
};

template<class T>
Node<T>::Node()
{
	next = NULL;
}

template<class T>
Node<T>::~Node()
{
//	delete this;
}


#endif /* NODE_H_ */
