#pragma once
#include "SortedArray.h"

typedef struct SortedArrayS
{
	int* arr;
	int length;
}
SortedArrayt;

int* copy_array(int* arr, int length);

SortedArrayt* initilaize_SortedArrayC(SortedArrayt* obj, int* arr, int length);