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



int main(){
    int elem,sum = 0;
    printf("Enter total number of elements : ");
    scanf("%d",&elem);
    struct node *head = makeLL(elem);
    printf("Enter the element you want to insert : ");
    int newElem,findElem;
    scanf("%d",&newElem);
    printf("After which element you want to insert : ");
    scanf("%d",&findElem);

    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Unable to allocate memory.");
        exit(0);
    }
    newNode->data = newElem;

    struct node *current = head;
    while (current != NULL && current->data != findElem) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Element not found in the linked list.\n");
    } else{
        newNode->next = current->next;
        current->next = newNode;
    }

//printing .........
    printf("INserted linked list: \n");
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");


    return 0;
}