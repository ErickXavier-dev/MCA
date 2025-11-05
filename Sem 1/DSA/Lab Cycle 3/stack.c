#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
  struct node *lsp;
  int data;
}*top;
int stack = -1;

struct node* createNode(int data){
  struct node *new = (struct node *)malloc(sizeof(struct node));
  new->data = data;
  new->lsp = NULL;
  return new;
}

bool stackEmpty(){
  return stack == -1;
}

void push(int val) {
  struct node *new = createNode(val);
  new->lsp = top;
  stack++;
  top = new;
}

void pop() {
  if(stackEmpty()) {
    printf("Stack is empty\n");
    return;
  } else {
    top = top->lsp;
    stack--;
    printf("Top element popped\n");
  }
}

void display(struct node *temp, int size){
  if(stackEmpty()) {
    printf("Stack is empty\n");
    return;
  }
  while(temp != NULL ) {
    printf(" %d : %d\n", size--, temp->data);
    temp = temp->lsp;
  }
  printf("-1 : NULL\n");
}

int main() {
  int value, opt;
  while(1==1) {
    printf("--------Menu--------\n");
    printf("1. Push to Stack\n");
    printf("2. Pop Stack\n");
    printf("3. Display Stack\n");
    printf("4. Exit\n\n");
    printf("Enter Your Choice: ");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
      printf("Enter value to be pushed: ");
      scanf("%d", &value);
      push(value);
      break;
    case 2:
      pop();
      break;
    case 3:
      display(top, stack);
      break;
    case 4:
      exit(0);
      break;
    default:
      break;
    }
  }
}