/*
 * Quicksort.h
 *
 *  Created on: 2017��9��21��
 *      Author: baoxd
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

class Sort{
public:
	// ��������
	void Quicksort(int a[], int low, int high);
	// ������ -- ��������
	void MaxHeapify(int *array, int size, int element);
	// ������
	void HeapSort(int *array, int size);
};



#endif /* QUICKSORT_H_ */
