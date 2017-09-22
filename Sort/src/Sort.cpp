/*
 * Sort.cpp
 *
 *  Created on: 2017年9月21日
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
 * 创建最大堆，保证根节点大于孩子节点，右孩子节点大于左孩子节点
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
	// 初始化堆
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




