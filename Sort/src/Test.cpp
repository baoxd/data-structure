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
	sort.Quicksort(a, 0, sizeof(a) / sizeof(a[0]) - 1);

	int i = 0;
	for(i = 0; i < (int)sizeof(a) / sizeof(a[0]); i++)
	{
		cout << a[i] << " =";
	}
	return 0;
}
