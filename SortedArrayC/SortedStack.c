#include "protected_SortedStack.h"

static SortedStackC* convert_pointer(SortedStack obj) { return (SortedStackC*)obj; }

SortedStack create_SortedStack(int* start_array, int length_array) {
	SortedStackC* sorted_stack = (SortedStackC*)malloc(sizeof(SortedStackC));
	if (sorted_stack == NULL)
		return NULL;
	construct_SortedArrayC((SortedArrayC*)sorted_stack, start_array, length_array);
	sorted_stack->ordered_elements = (NodeC*) NULL;
	return (SortedStack)sorted_stack;
};

int get_last_enterd_element_SortedStack(SortedStack sorted_stack) {
	return  get_head_value_Node(convert_pointer(sorted_stack)->ordered_elements);
};

void free_SortedStack(SortedStack to_free) {
	SortedStackC* sorted_stack_free = convert_pointer(to_free);
	free_Node(sorted_stack_free->ordered_elements);
	free(sorted_stack_free);
};