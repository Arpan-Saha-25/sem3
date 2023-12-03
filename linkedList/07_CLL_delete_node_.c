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

void delete_last(struct node *head){
    struct node *temp = head->next;
    while(temp->next->next != head){
        temp = temp->next;
    }
    struct node *p = temp->next;
    temp->next = head;
    //p->next = NULL;
    free(p);
    display(head);
}

void delete_first(struct node *head){
    struct node *temp = head->next;
    while(temp->next != head){
        temp = temp->next;
    }
    struct node *t = head;
    temp->next = temp->next->next;
    head = t->next;
    free(t);
     

    display(head);
}

void delete_middle(struct node *head){
    
}

int main(){
    int n ;
    printf("\nEnter the no. of element : ");
    scanf("%d",&n);
    struct node *head = create(n);
    printf("\n\nLast element deleted \n");
    
    delete_last(head);
    printf("\n\nFirst element deleted \n");
    delete_first(head);
    printf("\n\nMiddle element deleted \n");
    delete_middle();
    return 0;
}