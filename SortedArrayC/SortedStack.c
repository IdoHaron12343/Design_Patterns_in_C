#include "protected_SortedStack.h"
SortedStackC* create_SortedStack(int* start_array, int length_array) {
	SortedStackC* sorted_stack = (SortedStackC*)malloc(sizeof(SortedStackC));
	if (sorted_stack == NULL)
		return NULL;
	construct_SortedArrayC((SortedArrayC*)sorted_stack, start_array, length_array);
	sorted_stack->ordered_elements = (NodeC*) NULL;
	return sorted_stack;
};

int get_last_enterd_element_SortedStack(SortedStackC* sorted_stack) {
	return  get_head_value_Node(sorted_stack->ordered_elements);
};

void free_SortedStack(SortedStackC* sorted_stack_free) {
	free_Node(sorted_stack_free->ordered_elements);
	free(sorted_stack_free);
};