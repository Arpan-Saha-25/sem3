#include<stdio.h>

void *takeArray(int arr[], int size) {
    int i = 0;
    while (i < size) {
        printf("Enter an element : ");
        scanf("%d", &arr[i]);
        i++;
    }
    return arr;
}

void printHeap(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        max_heapify(arr, size, largest);
    }
}

void build_max_heap(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        max_heapify(arr, size, i);
    }
}

int main(int argc, char const *argv[]) {
    int size;
    printf("Enter the number of elements : ");
    scanf("%d", &size);

    int arr[size];
    takeArray(arr, size);

    printf("Array : ");
    printHeap(arr, size);

    build_max_heap(arr, size);

    printf("\nMax heap : ");
    printHeap(arr, size);

    return 0;
}
