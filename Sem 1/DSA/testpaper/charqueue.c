#include <stdio.h>
#include <stdlib.h>

struct node {
  char data;
  struct node* next;
} *front = NULL, *rear = NULL;

struct node* createNode(char data) {
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void enqueue(char data) {
  struct node *new = createNode(data);
  if(front == NULL && rear == NULL) {
    rear = new;
    front = new;
  } else {
    rear->next = new;
    rear = new;
  }
}

void dequeue() {
  if(rear == NULL && front == NULL) {
    printf("\nQueue is Empty!!");
    return;
  } else {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("\n%c is dequeued", front->data);
    temp = front;
    front = front->next;
    free(temp);
  }
}

void display(struct node *temp) {
  if(rear == NULL && front == NULL) {
    printf("\nQueue is Empty!!");
    return;
  }
  printf("\nElements in Queue: ");
  do {
    printf("%c -> ", temp->data);
    temp = temp->next;
  } while(temp!=NULL);
  printf("NULL");
}

void main() {
  int choice;
  char data;
  while(1==1){
    printf("\n==========Menu==========\n");
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice) {
      case 1:
        printf("\nEnter the value to be queued: ");
        scanf(" %c", &data);
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
        printf("Invalid Choice!!");
    }
  }
}