#pragma once
#ifndef baseheader
#include "base_header.h"
#endif // baseheader
#include "SortedStack.h"
#include "List.h"

typedef struct SortedStackS
{
	int* arr;
	int length;
	NodeC* ordered_elements;
} SortedStackC;

SortedStackC* create_SortedStack(int* start_array, int length_array);

int get_last_enterd_element_SortedStack(SortedStackC* sorted_stack);

void free_SortedStack(SortedStackC* sorted_stack_free);