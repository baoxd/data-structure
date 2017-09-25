/*
 * Sort.cpp
 *
 *  Created on: 2017年9月21日
 *      Author: baoxd
 */
#include <iostream>
#include "Sort.h"
using namespace std;

void Sort::InsertionSort(int a[], int len)
{
	int i, j, tmp;

	for(i = 1; i<len; i++)
	{
		tmp = a[i];
		for(j  = i - 1; j >= 0 ;j--)
		{
			if(tmp < a[j])
			{
				a[j+1] = a[j];
			}else
			{
				break;
			}
		}
		a[j+1] = tmp;
	}
}

void Sort::ShellSort(int a[], int len)
{
	// 增量
	int div = len / 2;
	// 定增量不断减小
	for(; div>=1; div = div / 2)
	{
		// 分成div组
		for(int i = 0 ; i<=div; i++)
		{
			// 对每组进行插入排序
			for(int j = i + div ; j < len; j = j + div)
			{
				if(a[j] < a[j - div])
				{
					int tmp = a[j];
					int k = j - div;
					while(k>=0 && a[k] > tmp)
					{
						a[k + div] = a[k];
						k -= div;
					}
					a[k + div] = tmp;
				}
			}
		}
	}
}

void Sort::BubbleSort(int a[], int len)
{
	for(int i = 0; i< len-1; i++)
	{
		for(int j = 0 ; j < len - 1 - i;j++)
		{
			if(a[j+1] < a[j])
			{
				swap(a[j+1], a[j]);
			}
		}
	}
}

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

void Sort::SelectionSort(int a[], int len)
{
	for(int i = 0 ;i<len-1; i++)
	{
		int min = i;
		for(int j = i+1; j < len; j++)
		{
			if(a[j]<a[min])
			{
				min = j;
			}
		}
		swap(a[min], a[i]);
	}
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

void Sort::merge(int a[], int start, int mid, int end, int result[])
{
	int i,j,k;
	i = start;
	j = mid + 1;
	k = 0;
	while(i<=mid && j<=end)
	{
		if(a[i]<a[j])
		{
			result[k++] = a[i++];
		}
		else
		{
			result[k++] = a[j++];
		}
	}
	while(i <= mid)
	{
		result[k++] = a[i++];
	}
	while(j <= end)
	{
		result[k++] = a[j++];
	}
	for(int i = 0;i<k;i++)
	{
		a[start+i] = result[i];
	}
}

void Sort::MergeSort(int a[], int start, int end, int result[])
{
	if(start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(a, start, mid, result);
		MergeSort(a, mid+1, end, result);
		merge(a,start,mid,end,result);
	}
}




