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
	// �������� -- ֱ�Ӳ���
	void InsertionSort(int a[], int len);
	// �������� -- ϣ������
	void ShellSort(int a[], int len);
	// �������� -- ð������
	void BubbleSort(int a[], int len);
	// �������� -- ��������
	void Quicksort(int a[], int low, int high);
	// ������ -- ��������
	void MaxHeapify(int *array, int size, int element);
	// ѡ������ -- ��ѡ������
	void SelectionSort(int a[], int len);
	// ѡ������ -- ������
	void HeapSort(int *array, int size);
	// �鲢����
	void merge(int a[], int start, int mid, int end, int result[]);
	void MergeSort(int a[], int start, int end, int result[]);
};



#endif /* QUICKSORT_H_ */
