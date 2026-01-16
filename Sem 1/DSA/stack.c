#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
} *top = NULL;

struct node *createNode(int data) {
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void checkEmpty() {
  if (top == NULL) {
    printf("\nStack is empty\n");
  } else {
    printf("\nStack is not empty\n");
  }
}

void push(int data) {
  struct node *new = createNode(data);
  if (top == NULL) {
    top = new;
  } else {
    new->next = top;
    top = new;
  }
}

void pop() {
  if (top == NULL) {
    printf("\nStack underflow\n");
    return;
  }
  struct node* temp = top;
  top = top->next;
  free(temp);
}

void display() {
  if (top == NULL) {
    printf("\nStack is empty\n");
    return;
  }
  struct node* temp = top;
  printf("\nStack elements: ");
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL \n");
}

void main() {
  int choice, data;
  while (1) {
    printf("\n============Menu==========\n");
    printf("1. Push\n2. Pop\n3. Display\n4. Check Empty\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter data to push: ");
        scanf("%d", &data);
        push(data);
        break;
      case 2:
        pop();
        break;
      case 3:
        display();
        break;
      case 4:
        checkEmpty();
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
}