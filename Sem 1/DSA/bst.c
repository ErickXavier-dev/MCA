#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
}*head = NULL;

struct node *createNode(int value) {
  struct node *temp = (struct node *)malloc(sizeof(struct Node));
  temp->data = value;
  temp->left = NULL;
  temp->right = NULL;
}

void createTree(int size) {
  int value;
  for(int i = size; i < size; i++) {
    printf("Enter the value for node: ");
    scanf("%d", &value);
    struct node *new = createNode(value);
    if(head == NULL) {
      head = new;
    } else {
      struct node *temp = NULL;
      while(temp->left != NULL && temp->right != NULL) {
        if(temp->data >= value) {
          temp = temp->right;
        } else {
          temp = temp->left;
        }
      }
      if(temp->data >= value && temp->left != NULL && temp->right != NULL) {
          temp->right = new;
        } else {
          temp->left = new;
        }
    }
  }
}

void displayPre(struct node *temp) {
  if (root != NULL) {
    printf("%d ", root->data); // Print root data
    displayPre(root->left);     // Traverse left subtree
    displayPre(root->right);    // Traverse right subtree
  }
}

void displayIn(struct node *temp) {
  if (root != NULL) {
    displayIn(root->left);      // Traverse left subtree
    printf("%d ", root->data);  // Print root data
    displayIn(root->right);     // Traverse right subtree
  }
}

void displayPost(struct node *temp) {
  if (root != NULL) {
    displayPost(root->left);    // Traverse left subtree
    displayPost(root->right);   // Traverse right subtree
    printf("%d ", root->data);  // Print root data
  }
}

void main() {
  int size;
  printf("Enter the number of nodes: ");
  scanf("%d", &size);
  createTree(size);
  printf("Preorder Traversal: ");
  displayPre(head);
  printf("\nInorder Traversal: ");
  displayIn(head);
  printf("\nPostorder Traversal: ");
  displayPost(head);
}