#pragma once
#ifndef baseheader
#include "base_header.h"
#endif // baseheader

typedef struct SortedArrayS
{
	int* arr;
	int length;
}
SortedArrayC;
/*constructor based on start array*/
SortedArrayC* create_SortedArray(int* start_array, int length_array);


int* quick_sort(int* arr, int length);

// int get_element_place_in_SortedArray(SortedArrayC* sorted_array, int element_to_find);

void print_sorted_array(SortedArrayC* arr);

void free_SortedArray(SortedArrayC* current_array);
