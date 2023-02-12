#pragma once
#ifndef baseheader
#include "base_header.h"
#endif // baseheader


typedef void* SortedArray;

/*constructor based on start array*/
SortedArray construct_SortedArray(int* start_array, int length_array);

/*returns a copy of the SortedArrayy*/
int* get_array_copy_SortedArray(SortedArray arr);

/*retruns the element from the element_place in the SortedArray*/
int get_element_SortedArray(SortedArray arr, int element_place);

/*prints the SortedArray's elements.*/
void print_SortedArray(SortedArray arr);

/*cleans the allocation of the SortedArray*/
void deconstruct_SortedArray(SortedArray current_array);
