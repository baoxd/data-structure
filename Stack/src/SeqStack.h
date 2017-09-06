/*
 * SeqStack.h
 *
 *  Created on: 2017��9��6��
 *      Author: baoxd
 */

#ifndef SEQSTACK_H_
#define SEQSTACK_H_
#include <iostream>
#include <string>

using namespace std;



/**
 * ����ģ���� -- ˳��ջ
 */
template<class T>
class SeqStack{
public:
	// ���캯��
	SeqStack(int size);
	// ��������
	virtual ~SeqStack();
	// ����ջ
	void destoryStck();
	// ���ջ
	void clearStack();
	// �п�
	bool isEmpty();
	// ջ����
	int length();
	// ��ȡջ��Ԫ��
	bool getTop(T &element);
	// ��ջ
	bool enStack(T element);
	// ��ջ
	bool deStack(T &element);
	// ����ջԪ��
	void visitStack(void(*Func)(T));
private:
	// ���ջ��������ָ��
	T *m_pStack;
	// Ԫ�ظ���
	int m_iLength;
	// ջ����
	int m_iCapacity;
};

template<class T>
SeqStack<T>::SeqStack(int size)
{
	m_pStack = new T[size];
	m_iLength = 0;
	m_iCapacity = size;
	if(m_pStack == NULL){
		throw string("ջ�ռ�������");
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
	// ��ӡ��ջ�Ķ����ڴ��ַ
	cout << "��ʱ�����ڴ��ַ:" << &element << endl;
	// ջ��
	if(m_iLength >= m_iCapacity){
		return false;
	}

	m_pStack[m_iLength] = element;
	// ջ�е��ڴ��ַ
	cout << "ջ�е��ڴ��ַ:" << &m_pStack[m_iLength] << endl;
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
