#include<stdio.h>

void *takeArray(int arr[],int size){
    int i = 0;
    while(i++ < size){
        printf("Enter a element : ");
        scanf("%d",&arr[i]);
    }
    return arr;
}

void printHeap(int arr[],int size){
    int i = 0;
    while(i++ < size){
        printf("%d",arr[i]);
    }
}

int main(int argc, char const *argv[])
{
    int size;
    printf("Enter the no. of elements : ");
    scanf("%d",&size);

    int *head,arr[size];
    head = takeArray(arr,size);
    printf("Array : ");
    printHeap(head,size);

    return 0;
}
