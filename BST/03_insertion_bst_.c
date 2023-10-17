#include <stdio.h>
#include <stdlib.h>

/*
          50
        /   \
     30      70
    /  \    /  \
  20   40  60   80

*/ 

struct node
{
  int data;
  struct node *left, *right;
};

struct node * createNode(int data1){
  struct node *n;
  n = (struct node *) malloc(sizeof(struct node));
  n->left = NULL;
  n->right = NULL;
  n->data = data1;

  return n;
}

void inOrder(struct node *root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

struct node *insert(struct node *root,int dataIn){

    if (root == NULL) {
        return createNode(dataIn);
    }

    if (dataIn < root->data) {
        root->left = insert(root->left, dataIn);
    } else if (dataIn > root->data) {
        root->right = insert(root->right, dataIn);
    }

    return root;
}

int main()
{
  struct node *p =  createNode(50);
  struct node *p1 =  createNode(30);
  struct node *p2 =  createNode(20);
  struct node *p3 =  createNode(40);
  struct node *p4 =  createNode(70);
  struct node *p5 =  createNode(60);
  struct node *p6 =  createNode(80);
      
  p->left = p1;
  p->right = p4;

  p1->left = p2;
  p1->right = p3;

  p4->left = p5;
  p4->right = p6;

  printf("Enter the element to be inserted : ");
  int inp;
  scanf("%d",&inp);

  insert(p,inp);

  printf("\nIn-order : ");
  inOrder(p);
   

  return 0;
}

