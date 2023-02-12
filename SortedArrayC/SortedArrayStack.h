#pragma once
#ifndef baseheader
#include "base_header.h"
#endif // baseheader
#include "List.h"

typedef void* SortedArrayStack;

SortedArrayStack create_SortedStack(int* start_array, int length_array);

int get_last_enterd_element_SortedStack(SortedArrayStack sorted_stack);

void free_SortedStack(SortedArrayStack sorted_stack_free);
