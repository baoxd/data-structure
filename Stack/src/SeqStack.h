/*
 * SeqStack.h
 *
 *  Created on: 2017年9月6日
 *      Author: baoxd
 */

#ifndef SEQSTACK_H_
#define SEQSTACK_H_
#include <iostream>
#include <string>

using namespace std;



/**
 * 定义模板类 -- 顺序栈
 */
template<class T>
class SeqStack{
public:
	// 构造函数
	SeqStack(int size);
	// 析构函数
	virtual ~SeqStack();
	// 销毁栈
	void destoryStck();
	// 清空栈
	void clearStack();
	// 判空
	bool isEmpty();
	// 栈长度
	int length();
	// 获取栈顶元素
	bool getTop(T &element);
	// 进栈
	bool enStack(T element);
	// 出栈
	bool deStack(T &element);
	// 访问栈元素
	void visitStack(void(*Func)(T));
private:
	// 存放栈数据数组指针
	T *m_pStack;
	// 元素个数
	int m_iLength;
	// 栈容量
	int m_iCapacity;
};

template<class T>
SeqStack<T>::SeqStack(int size)
{
	m_pStack = new T[size];
	m_iLength = 0;
	m_iCapacity = size;
	if(m_pStack == NULL){
		throw string("栈空间分配出错");
	}
}

template<class T>
SeqStack<T>::~SeqStack()
{
	destoryStck();
}

template<class T>
void SeqStack<T>::destoryStck()
{
	delete []m_pStack;
	m_pStack = NULL;
}

template<class T>
bool SeqStack<T>::isEmpty()
{
	return m_iLength == 0 ? true : false;
}

template<class T>
int SeqStack<T>::length(){
	return m_iLength;
}

template<class T>
bool SeqStack<T>::getTop(T &element)
{
	if(isEmpty()){
		return false;
	}
	element = m_pStack[m_iLength - 1];
	return true;
}

template<class T>
bool SeqStack<T>::enStack(T element)
{
	// 打印进栈的对象内存地址
	cout << "临时变量内存地址:" << &element << endl;
	// 栈满
	if(m_iLength >= m_iCapacity){
		return false;
	}

	m_pStack[m_iLength] = element;
	// 栈中的内存地址
	cout << "栈中的内存地址:" << &m_pStack[m_iLength] << endl;
	m_iLength++;
	return true;
}

template<class T>
bool SeqStack<T>::deStack(T &element)
{
	if(isEmpty()){
		return false;
	}
	m_iLength--;
	element = m_pStack[m_iLength];
	return true;
}

template<class T>
void SeqStack<T>::visitStack(void(*Func)(T))
{
	if(!isEmpty()){
		for(int i = 0 ; i < m_iLength ; i++){
			Func(m_pStack[i]);
		}
	}
}



#endif /* SEQSTACK_H_ */
