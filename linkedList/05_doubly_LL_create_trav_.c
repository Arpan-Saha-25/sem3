#include<stdio.h>
#include<stdlib.h>


typedef struct DoublyLL
{
    struct DoublyLL *prev;
    int data;
    struct DoublyLL *next;
} DLL;


void display(DLL *head){
        do{
            printf("%d ",head->data);
            head = head->next;
        }
        while(head != NULL);
        printf("\n");
        return;
}

void display_back(DLL *head){
    DLL *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    while(tail != NULL){
        printf("%d ",tail->data);
        tail = tail->prev;
    }
    printf("\n");
    return;
}

void *createNode(int no){
    int i = 1;
    DLL *head = calloc(1,sizeof(DLL));
    printf("Enter the data for node %d : ",i);
    int data;
    scanf("%d",&data);
    head->data = data;
    head->prev = NULL;
    head->next = NULL;

    DLL *temp = head;
    for(int i = 2;i <= no;i++){
        DLL *newestNode = calloc(1,sizeof(DLL));
        printf("Enter the data for node %d : ",i);
        int data1;
        scanf("%d",&data1);
        newestNode->data = data1;
        newestNode->next = NULL;
        newestNode->prev = temp;

        temp->next = newestNode;
        temp = temp->next;
    }
        printf("\nLinkedList : \n");
        display(head);
        return head;
}


void main(){
    int numEle;
    printf("How many elements you want to enter : ");
    scanf("%d",&numEle);
    DLL *head = createNode(numEle);
    printf("Press Y for displaying the list in reverse order. Press S for skip.\n");
    // char temp;
    // scanf(" %c",&temp);
    char ch;
    scanf(" %c",&ch);
    if(ch == 'y' || ch == 'Y')
        display_back(head);
    else
        printf("Skipped.\n");

    
    

    return;
}