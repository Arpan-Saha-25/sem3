#include<stdio.h>
#include<stdlib.h>

/* Creating a stack structure. */
struct stack
{
    int data;
    struct stack *next;
};

/* Creating a global variable TOP so that it could be accessed by all functions. */
struct stack *top  = NULL;

/* To display the stack. */
void display(struct stack *top){
    if(top == NULL){
        printf("Stack Empty.\n");
        return;
    }
    else {
        printf("\nStack : [");
        struct stack *ptr = top;
        while (ptr != NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
        printf("]\n");
    }
}

/* To enter an element into the stack. */
struct stack *push(struct stack *top,int value){

    struct stack *ptr = malloc(sizeof(struct stack));

    if (ptr == NULL)
    {
        printf("Memory allocation failed. Stack not updated.\n");
        return top;
    }
    
    ptr->data = value;

    if(top == NULL){                        //stack is empty
        ptr->next = NULL;
        top = ptr;
    }
    else{                                   //if stack is not empty
        ptr->next = top;
        top = ptr;
    }
    //display(top);
    return top;
}

/* to remove an element from the top of the stack. */
struct stack *pop(struct stack *top){

    struct stack *ptr = top;

    if(top == NULL) {
        printf("Stack underflow.\n");
        return top;
    }
    
    top = top->next;
    printf("The popped item is %d.\n",ptr->data);
    free(ptr);
    return top;
}

/* to to get the value of the TOP element. */
void peek(struct stack *top){
    if(top == NULL){
        printf("No elements found.\n");
    }
    else
    {
        printf("Top Element is %d.\n",top->data);
    }
}


int main() {

    /*
    "option" variable is used for selection of the options and 
    the "value" var is used for taking a value for the insertion into the stack.
    */
    int option,value;

    /* This do-while will run until the value of the option equals to 5 as the user would have opt for number 5. */
    do{
    printf("\nMain menu : \n\n");
    printf("1. Push \n2. Pop\n3. Display\n4. Peak\n5. EXIT\n\n>>> ");
    scanf("%d",&option);

    switch (option)
    {
    case 1:
        //int value;                                        This line will throw error. Why? Check the end of the code.
        printf("Enter the value to be inserted : ");
        scanf("%d",&value);
        top = push(top,value);
        display(top);
        break;
    case 2:
        top = pop(top);
        display(top);
        break;
    case 3:
        display(top);
        break;
    case 4:
        peek(top);
        break;
    case 5:
        return 0;
    default:
        printf("Invalid input.");
        break;
    }
    } while (option != 5);
    
    return 0;
}

/*
case 1:
    int value;

This line will throw an error saying "error: a label can only be part of a statement and a declaration is not a statement" because in C ,
labels can only be followed by statements, and declarations do not count as statements. 

*/