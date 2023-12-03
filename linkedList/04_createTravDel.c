#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
};

void display(struct node *head){
    do{
        printf("%d ",head->data);
        head = head->next;
    }
    while(head != NULL);

    return;
}

void *newNodeAdd(int no){
    int i = 1;
    struct node *head = calloc(1,sizeof(struct node));
    printf("Enter the data for node %d : ",i);
    int data;
    scanf("%d",&data);

    head->data = data;
    head->next = NULL;

    struct node *temp = head;
    for(int i = 2;i <= no;i++){
        struct node *newestNode = calloc(1,sizeof(struct node));
        printf("Enter the data for node %d : ",i);
        int data1;
        scanf("%d",&data1);
        newestNode->data = data1;
        newestNode->next = NULL;

        temp->next = newestNode;
        temp = temp->next;
    }
    printf("\nLinkedList : ");
    display(head);
    return head;
}


void *delete_first(struct node *head){
    struct node *temp = head;
    head = head->next;
    free(temp);
    printf("\nFirst element deleted.\n");
    display(head);
    return head;
}

void del_middle(struct node *head,int findEle){
    struct node *temp = head;
    int count = 0;                                  // checker
    while (temp->next != NULL){
        if(temp->next->data == findEle){
            struct node *tp = temp->next;
            temp->next = temp->next->next;
            free(tp);
            //printf("->>>>>>>>>>>   %d ",count++);
            display(head);
            return;

        }
        temp = temp->next;
    }
    printf("\nItem deleted from middle. \n");
    display(head);
    return ;
}

void delete_last(struct node *head) {
    struct node *current = head;

    if (head == NULL || head->next == NULL) {                                               //underflow
        printf("\nThe list is empty or has only one element.");
        return;
    }

    while (current->next->next != NULL) {
        current = current->next;
    }
    
    struct node *tmp = current->next;
    current->next = NULL;
    free(tmp);
    
    printf("\nLast element deleted.\n");
}

int main(){
    printf("\nHow many nodes you want to make : ");
    int n;
    scanf("%d",&n);
    struct node *head = newNodeAdd(n);

    delete_last(head);
    display(head);
    head = delete_first(head);
    printf("\nEnter a element that you want to delete from middle : ");
    int find;
    scanf("%d",&find);
    del_middle(head,find);

}    

