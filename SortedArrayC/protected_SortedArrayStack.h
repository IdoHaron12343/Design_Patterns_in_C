#pragma once
#include "SortedStack.h"
#include "protected_SortedArray.h"
#include "List.h"

typedef struct SortedArrayStackS
{
	int* arr;
	int length;
	NodeC* ordered_elements;
} SortedStackC;