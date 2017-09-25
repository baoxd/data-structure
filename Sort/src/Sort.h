/*
 * Quicksort.h
 *
 *  Created on: 2017年9月21日
 *      Author: baoxd
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

class Sort{
public:
	// 插入排序 -- 直接插入
	void InsertionSort(int a[], int len);
	// 插入排序 -- 希尔排序
	void ShellSort(int a[], int len);
	// 交换排序 -- 冒泡排序
	void BubbleSort(int a[], int len);
	// 交换排序 -- 快速排序
	void Quicksort(int a[], int low, int high);
	// 堆排序 -- 创建最大堆
	void MaxHeapify(int *array, int size, int element);
	// 选择排序 -- 简单选择排序
	void SelectionSort(int a[], int len);
	// 选择排序 -- 堆排序
	void HeapSort(int *array, int size);
	// 归并排序
	void merge(int a[], int start, int mid, int end, int result[]);
	void MergeSort(int a[], int start, int end, int result[]);
};



#endif /* QUICKSORT_H_ */
