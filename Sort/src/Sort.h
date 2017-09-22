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
	// 快速排序
	void Quicksort(int a[], int low, int high);
	// 堆排序 -- 创建最大堆
	void MaxHeapify(int *array, int size, int element);
	// 堆排序
	void HeapSort(int *array, int size);
};



#endif /* QUICKSORT_H_ */
