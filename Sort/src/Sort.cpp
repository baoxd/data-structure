/*
 * Sort.cpp
 *
 *  Created on: 2017Äê9ÔÂ21ÈÕ
 *      Author: baoxd
 */
#include "Sort.h"

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




