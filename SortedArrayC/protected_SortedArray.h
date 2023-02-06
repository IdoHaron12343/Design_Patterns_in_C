#pragma once
#include "SortedArray.h"

typedef struct SortedArrayS
{
	int* arr;
	int length;
}
SortedArrayC;

int* copy_array(int* arr, int length);

SortedArrayC* construct_SortedArrayC(SortedArrayC* obj, int* arr, int length);