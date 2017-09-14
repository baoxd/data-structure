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
	// 清空节点
	void clear();
public:
	T data;
	Node *lChild;
	Node *rChild;
};

template<class T>
Node<T>::Node()
{
	lChild = NULL;
	rChild = NULL;
}

template<class T>
Node<T>::~Node()
{
}

template<class T>
void Node<T>::clear()
{
	Node<T> *lChild = this->lChild;
	Node<T> *rChild = this->rChild;

	if(lChild != NULL)
	{
		lChild->clear();
	}
	if(rChild != NULL)
	{
		rChild->clear();
	}
	delete this;
}




#endif /* NODE_H_ */
