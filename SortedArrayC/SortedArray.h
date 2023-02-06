#pragma once
#ifndef baseheader
#include "base_header.h"
#endif // baseheader

typedef void* SortedArray;

/*constructor based on start array*/
SortedArray create_SortedArray(int* start_array, int length_array);


int* quick_sort(int* arr, int length);

// int get_element_place_in_SortedArray(SortedArrayC* sorted_array, int element_to_find);

void print_sorted_array(SortedArray arr);

void free_SortedArray(SortedArray current_array);
