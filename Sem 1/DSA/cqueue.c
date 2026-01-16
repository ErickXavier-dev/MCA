#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
}*front = NULL, *rear = NULL;

struct node *createNode(int data) {
  struct node *new = (struct node *)malloc(sizeof(struct node));
  new->data = data;
  new->next = NULL;
  return new;
}

void enqueue(int data) {
  struct node *new = createNode(data);
  if(rear == NULL && front == NULL) {
    rear = new;
    front = new;
    rear->next = front;
  } else {
    rear->next = new;
    rear = new;
    rear->next = front;
  }
}

void dequeue(struct node *temp) {
  if(rear == NULL && front == NULL){
    printf("Queue Empty");
    return;
  }
  if (front == rear) {
    // Only one element
    printf("%d removed from queue\n", front->data);
    front = rear = NULL;
  } else {
    printf("%d removed from queue\n", front->data);
    front = front->next;
    rear->next = front; // maintain circular link
  }
  free(temp);
}

void display(struct node *temp){
  if(rear == NULL && front == NULL){
    printf("Queue Empty");
    return;
  }
  printf("Queue Elements: ");
  do {
    printf("%d -> ", temp->data);
    temp = temp->next;
  } while (temp != front);
  printf("NULL\n");
}

void main() {
  int choice, data;
  while (1) {
    printf("\n============Menu==========\n");
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter data to push: ");
        scanf("%d", &data);
        enqueue(data);
        break;
      case 2:
        dequeue(front);
        break;
      case 3:
        display(front);
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
}