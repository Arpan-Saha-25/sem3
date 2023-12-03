#include<stdio.h>
#include<stdlib.h>
/*
Q. Create linked list; insert and delete element from any position.
Q. Sort the following linked list in ascending or descending order.
Q. Create a list containing natural numbers, find the average of all elements
*/

struct node{
    int element;
    struct node *next;
};

void *makeLL(int n){
    struct node *newNode, *temp,*head;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    // not allocated then ........
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }

    // Input data ...........
    printf("Enter the data of node 1: ");
    scanf("%d", &data);

    head->element = data; 
    head->next = NULL; 
    temp = head;

    for(i=2; i<=n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->element = data; 
        newNode->next = NULL; 

        temp->next = newNode; 
        temp = temp->next;    
    }
    return head;
}


int main(){
    int elem,sum = 0;
    printf("Enter total number of elements : ");
    scanf("%d",&elem);
    struct node *head = makeLL(elem);
    printf("The average of the given numbers are : \t");
    struct node *temp = head;
    for(int i = 0;i < elem ;i++){
        sum = sum + temp->element;
        temp = temp->next;
        //printf("%d ",sum);                        //sum check .....
    }
    float avg = (float)sum/elem ;
    printf("%f",avg);

    return 0;
}