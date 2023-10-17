#include <stdio.h>
#include<stdlib.h>

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

struct node *newNode(int data)
{
  struct node *createdNode = (struct node *)malloc(sizeof(struct node));

  createdNode->data = data;
  createdNode->left = NULL;
  createdNode->right = NULL;

  return createdNode;
}

int main()
{
  printf("Enter the number of elements : ");
  int no;
  scanf("%d", &no);

  for (int i = 1; i < no; i++)
  {
    printf("Enter the data : ");
    int data;
    scanf("%d", &data);
  }

  return 0;
}
