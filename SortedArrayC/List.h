#pragma once
#ifndef baseheader
#include "base_header.h"
#endif // baseheader

typedef struct NodeS NodeC;

typedef struct NodeS
{
	int value;
	NodeC* next;
}
NodeC;

NodeC* add_element_List(NodeC* list, int element);

int get_head_value_Node(NodeC* list);

void free_Node(NodeC* node_to_free);