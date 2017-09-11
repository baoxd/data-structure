/*
 * Node.h
 *
 *  Created on: 2017年9月11日
 *      Author: baoxd
 */

#ifndef NODE_H_
#define NODE_H_
#include <iostream>

/**
 *  链表节点
 */

template<class T>
class Node{
public:
	Node();
	~Node();
	// 存放节点数据
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
