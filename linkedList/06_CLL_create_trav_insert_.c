#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void display(struct node *head){
    struct node *temp = head;
    printf("The listed list : \n");
    printf("%d ",temp->data);
    temp = temp->next; 
    while(temp != head){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    return ;
}

void *create(int total_elem){
    int i = 1;
    struct node *head = calloc(1,sizeof(struct node));
    printf("Enter the value of node %d : ",i);
    scanf(" %d",&(head->data));
    head->next = NULL;
    struct node *temp = head;
    
    while(++i <= total_elem){
        struct node *newNode = calloc(1,sizeof(struct node));
        temp->next = newNode;
        printf("Enter the value of node %d : ",i);
        scanf(" %d",&(newNode->data));
        newNode->next = NULL;
        temp = temp->next;
        if(i == total_elem)
            newNode->next = head;
    }
    display(head);
    return head;
}

void insert_first(struct node *head){
    struct node *tail = head->next;
    while(tail->next != head){
        tail = tail->next;
    }
    struct node *newNode = calloc(1,sizeof(struct node));
    printf("enter the value : ");
    scanf(" %d",&newNode->data);
    newNode->next = head;
    tail->next = newNode;
    head = tail->next ;
    display(head);
    return;

}

void insert_middle(struct node *head,int idx){
    int i = 1;
    struct node *node = head;
    while(++i != idx){
        node = node->next;
    }
    struct node *newNode = calloc(1,sizeof(struct node));
    printf("enter the value : ");
    scanf(" %d",&newNode->data);
    newNode->next = node->next;
    node->next = newNode;
    display(head);
    return;
}

void insert_last(struct node *head){
    struct node *temp = head->next;
    while(temp->next != head){
        temp = temp->next;
    }
    struct node *newNode = calloc(1,sizeof(struct node));
    printf("\nEnter the value of new node : ");
    
    scanf(" %d",&newNode->data);
    temp->next = newNode; 
    newNode->next = head;
    display(head);
    return ;
}


int main()
{
    int n ;
    printf("Enter the no. of element : ");
    scanf("%d",&n);
    struct node *head = create(n);
    printf("\n\n\tInsertion at last : \n");
    insert_last(head);
    printf("\n\n\tInsertion at first : \n");
    insert_first(head);
    printf("\n\n\tInsertion at middle : \n");
    printf("\nIn which index? : ");
    int n1;
    scanf(" %d",&n1);
    insert_middle(head,n1);
    return 0;
}

