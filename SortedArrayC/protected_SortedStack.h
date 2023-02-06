#pragma once
#include "SortedStack.h"
#include "protected_SortedArray.h"
#include "List.h"

typedef struct SortedStackS
{
	int* arr;
	int length;
	NodeC* ordered_elements;
} SortedStackC;