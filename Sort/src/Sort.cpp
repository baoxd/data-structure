/*
 * Sort.cpp
 *
 *  Created on: 2017��9��21��
 *      Author: baoxd
 */
#include <iostream>
#include "Sort.h"
using namespace std;

void Sort::Quicksort(int a[], int low, int high)
{
	if(low > high)
	{
		return;
	}
	int first = low;
	int last = high;
	int key = a[first];

	while(first < last)
	{
		while(first < last && a[last] > key)
		{
			last--;
		}
		a[first] = a[last];
		while(first < last && a[first] < key)
		{
			first++;
		}
		a[last] = a[first];
	}
	a[first] = key;
	Quicksort(a,low,first-1);
	Quicksort(a, first+1, high);
}

/**
 * �������ѣ���֤���ڵ���ں��ӽڵ㣬�Һ��ӽڵ�������ӽڵ�
 */
void Sort::MaxHeapify(int *array, int start, int end)
{
	int parent = start;
	int child = 2 * parent + 1;

	while(child <= end)
	{
		if(child + 1 <= end && array[child] < array[child+1])
			child++;
		if(array[parent] > array[child])
		{
			return;
		}
		else
		{
			swap(array[parent], array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
	}
}

void Sort::HeapSort(int *array, int size)
{
	int i;
	// ��ʼ����
	for(i = size / 2 - 1; i>=0; i--)
	{
		MaxHeapify(array, i, size - 1);
	}
	for(i = size - 1; i>0; i--)
	{
		swap(array[0], array[i]);
		MaxHeapify(array, 0, i-1);
	}
}




