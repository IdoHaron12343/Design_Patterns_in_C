#include "protected_SortedArray.h"

/* private methods */

void swap(int* a, int* b);
int partition(int* array, int low, int high);
int* __quick_sort(int* array, int low, int high);


/* private method */
void swap(int *a, int *b) {
	(*a) = (*a) ^ (*b);
	(*b) = (*a) ^ (*b); 
	(*a) = (*a) ^ (*b);
}

/* private method */
int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
   swap(&array[i + 1], &array[high]);
    return (i + 1);
}

int* __quick_sort(int *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        __quick_sort(array, low, pi - 1);
        __quick_sort(array, pi + 1, high);
    }
    return array;
}

int* copy_array(int* arr, int length) {
    if (length == 0)
        return NULL;
    int* new_arr = (int*)malloc(sizeof(int) * length);
    if (new_arr == NULL)
        return NULL;
    for (int i = 0; i < length; i++) {
        new_arr[i] = arr[i];
    }
    return new_arr;
}

 /* public static method */
int* quick_sort(int* arr, int length) {
    return __quick_sort(arr, 0, length);
}


SortedArrayC* create_SortedArray(int* arr, int length) {
    arr = quick_sort(arr, length);
    SortedArrayC* sorted_arr = (SortedArrayC*)malloc(sizeof(SortedArrayC));
    if (sorted_arr == NULL)
        return NULL;
    construct_SortedArrayC(sorted_arr, arr, length);
    return sorted_arr;
}

void free_SortedArray(SortedArrayC* to_free) {
    free(to_free->arr);
    free(to_free);
}

void print_sorted_array(SortedArrayC* to_print) {
    for (int i = 0; i < to_print->length; i++) {
        printf("%d\t", to_print->arr[i]);
    }
    printf("\n");
}

SortedArrayC* construct_SortedArrayC(SortedArrayC* obj, int* arr, int length) {
    obj->arr = copy_array(arr, length);
    obj->length = length;
    return obj;
}
int get_element_place_in_SortedArray(SortedArrayC* sorted_array, int element_to_find) {
    int current_end = sorted_array->length;
    int current_start = 0;
    int current_place;
    while (current_start != (current_end -1)) {
        current_place = (current_start + (current_end-1)) / 2;
        if (element_to_find < sorted_array->arr[current_place]) {
            current_end = current_place;
            continue;
        }
        if (element_to_find > sorted_array->arr[current_place]) {
            current_start = current_place;
            continue;
        }
        if (element_to_find == sorted_array->arr[current_place])
            return current_place;
    }
    if (sorted_array->arr[current_start] == element_to_find) {
        return current_start;
    }
    return -1;
};