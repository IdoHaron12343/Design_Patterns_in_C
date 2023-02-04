#include "List.h"

NodeC* add_element_List(NodeC* list, int element) {
	NodeC* new_node = (NodeC*)malloc(sizeof(NodeC));
	if (new_node == NULL)
		return NULL;
	new_node->value = element;
	new_node->next = NULL;
	if (list != NULL) {
		new_node->next = list;
	}
	return new_node;
}

int get_head_value_Node(NodeC* list) {
	int value = list->value;
	return value;
};

NodeC* get_next_Node(NodeC* node) {
	return node->next;
}

void free_Node(NodeC* node_to_free) {
	if (node_to_free == NULL)
		return;
	free(node_to_free);
	free_Node(node_to_free->next);
};