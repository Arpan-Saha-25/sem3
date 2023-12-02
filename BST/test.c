#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *createNodeP(int *p) {
    struct node *root = malloc(sizeof(struct node));
    root->data = *p;
    root->left = NULL;
    root->right = NULL;

    for (int i = 1; i < 10; i++) {
        p++;  // Increment the pointer to the next element in the array
        struct node *newNode;
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = *p;  // Copy the value from the array
        newNode->left = NULL;
        newNode->right = NULL;

        struct node *temp = root;

        while (1) {
            if (*p < temp->data) {
                if (temp->left == NULL) {
                    temp->left = newNode;
                    break;
                }
                temp = temp->left;
            } else /*if (*p > temp->data)*/ {
                if (temp->right == NULL) {
                    temp->right = newNode;
                    break;
                }
                temp = temp->right;
            }
        }
    }

    return root;
}

void inOrder(struct node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main(int argc, char const *argv[]) {
    printf("Creating BST : \n");
    int arr[10];
    printf("Enter the elements : \n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n");

    struct node *r = createNodeP(arr);
    inOrder(r);
    return 0;
}
