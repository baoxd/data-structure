//============================================================================
// Name        : Sort.cpp
// Author      : baoxd
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Sort.h"

using namespace std;


int main() {
	Sort sort;
    // ��������
	int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24};
	int len =sizeof(a) / sizeof(a[0]);
//	// ��������
//	sort.Quicksort(a, 0, len - 1);
//	// ������
//	sort.HeapSort(a, len);
//	// �򵥲�������
//	sort.InsertionSort(a, len);
//	// ��ѡ������
//	sort.SelectionSort(a, len);
//	// ð������
//	sort.BubbleSort(a, len);
	// ϣ������
	sort.ShellSort(a, len);

	int i = 0;
	for(i = 0; i < (int)sizeof(a) / sizeof(a[0]); i++)
	{
		cout << a[i] << " =";
	}
	return 0;
}
