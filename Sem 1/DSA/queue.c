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
    new->data = data;
    rear = new;
    front = new;
  } else {
    rear->next = new;
    rear = new;
  }
}

void dequeue() {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  if(rear == NULL && front == NULL){
    printf("Queue Empty");
    return;
  }
  printf("%d removed from queue", front->data);
  temp = front;
  front = front->next;
  free(temp);
}

void display(struct node *temp){
  printf("Queue Elements: ");
  while(temp!=NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL");
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
        dequeue();
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