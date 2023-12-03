#include<stdio.h>

void takeArray(int arr[],int size){
    printf("Enter your elements : \n");
    int i = 0;
    while(i < size){
        scanf("%d",&arr[i]);
        i++;
    }
}

void printHeap(int arr[], int size) {
    printf("Your array is : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(int arr[],int i,int size){
    int lowest = i;
    int leftc = 2*i + 1;
    int rightc = 2*i + 2;

    if(rightc < size && arr[rightc] < arr[lowest]){
        lowest = rightc;
    }
    if(leftc < size && arr[leftc] < arr[lowest]){
        lowest = leftc;
    }
    if(lowest != i){
        swap(&arr[i],&arr[lowest]);
        min_heapify(arr,lowest,size);
    }

}

void build_min_heap(int arr[], int size) {
    // for intermediate nodes
    for (int i = size / 2 - 1; i >= 0; i--) {
        min_heapify(arr, i, size);
    }
}

int main() {

    int size;
    printf("Enter the no. of elements : ");
    scanf("%d",&size);

    int heap[size];
    takeArray(heap,size);

    build_min_heap(heap,size);
    printHeap(heap,size);

    return 0;
}