#include "protected_SortedArray.h"

/* private methods */

static void swap(int* a, int* b);
static int partition(int* array, int low, int high);
static int* __quick_sort(int* array, int low, int high);
static int* quick_sort(int* arr, int length);
static SortedArrayt* convert_pointer(SortedArray pointer) { return (SortedArrayt*)pointer; };



SortedArray construct_SortedArray(int* arr, int length) {
    SortedArrayt* sorted_arr = (SortedArrayt*)malloc(sizeof(SortedArrayt));
    if (sorted_arr == NULL)
        return NULL;
    initilaize_SortedArrayC(sorted_arr, arr, length);
    return (SortedArray)sorted_arr;
}

SortedArrayt* initilaize_SortedArrayC(SortedArrayt* obj, int* arr, int length) {
    obj->arr = copy_array(arr, length);
    arr = quick_sort(obj->arr, length);
    obj->length = length;
    return obj;
}

int get_element_place_SortedArray(SortedArrayt* sorted_array, int element_to_find) {
    int current_end = sorted_array->length;
    int current_start = 0;
    int current_place;
    while (current_start != (current_end - 1)) {
        current_place = (current_start + (current_end - 1)) / 2;
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

void print_SortedArray(SortedArray to_print) {

    for (int i = 0; i < convert_pointer(to_print)->length; i++) {
        printf("%d\t", convert_pointer(to_print)->arr[i]);
    }
    printf("\n");
}

int* get_array_copy_SortedArray(SortedArray arr) {
    return copy_array(convert_pointer(arr)->arr);
}

int get_element_SortedArray(SortedArray arr, int place) {
    if (convert_pointer(arr)->length <= place) {
        printf("illegal request. place: %d is larger than length: %d", place, convert_pointer(arr)->length);
        return NULL; /* in future articles, we are going to learn about more saphisticated error hadling method, as this is simply equivilent to returning 0*/
    }
    return convert_pointer(arr)->arr[place];
}

void deconstruct_SortedArray(SortedArray to_free) {
    free(convert_pointer(to_free)->arr);
    free(convert_pointer(to_free));
}


/* private method */
void swap(int* a, int* b) {
    (*a) = (*a) ^ (*b);
    (*b) = (*a) ^ (*b);
    (*a) = (*a) ^ (*b);
}

/* private method */
int partition(int* array, int low, int high) {
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

int* __quick_sort(int* array, int low, int high) {
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
    return __quick_sort(arr, 0, length - 1);
}