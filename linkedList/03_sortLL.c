#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *makeLL(int n){
    struct node *newNode, *temp,*head;
    int data;

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

    head->data = data; 
    head->next = NULL; 
    temp = head;

    for(int i=2; i<=n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data; 
        newNode->next = NULL; 

        temp->next = newNode; 
        temp = temp->next;    
    }
    return head;
}

int main(int argc, char const *argv[]){
    
    int elem,sum = 0;
    printf("Enter total number of elements : ");
    scanf("%d",&elem);
    struct node *headMain = makeLL(elem);
    printf("Sorted array is : \n");

    struct node *current = (struct node *) malloc(sizeof(struct node));
    current = headMain;

    while (current->next != NULL){
        if(current->data > current->next->data){
            
        }
    }
    




    return 0;
}
