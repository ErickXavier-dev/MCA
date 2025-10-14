#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
}*head = NULL, *last = NULL;

struct node* createNode(int val) {
  struct node *new = (struct node *)malloc(sizeof(struct node));
  new->data = val;
  new->next = NULL;
  return new;
}

void createList(int size) {
  int value;
  for (int i = 0; i < size; i++)
  {
    printf("Enter the value for the node: ");
    scanf("%d", &value);
    struct node *new = createNode(value);

    if(head == NULL) {
      head = new;
    } else {
      last->next = new;
    }
    last = new;
  }
}

void displayList(struct node *temp) {
  while(temp != NULL) {
    printf("%d->", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

void searchList(struct node *temp, int val) {
  while(temp->next != NULL && temp->data != val) {
    temp = temp->next;
  }
  if(temp->data == val) {
    printf("Value was found!\n");
  } else {
    printf("Value was not found\n");
  }
}

void insertFirst(struct node *temp, int val) {
  struct node *new = createNode(val);
  new->next = head;
  head = new;
}

void insertMiddle(struct node *temp, int val, int size) {
  int mid = size/2;
  for(int i = 0; i<mid; i++) {
    temp = temp->next;
  }
  struct node *new = createNode(val);
  if(temp->next != NULL)  {
    new->next = temp->next;
    temp->next = new;
  } else {
    temp->next = new;
  }
}

void insertLast(struct node *temp, int val) {
  while(temp->next != NULL) {
    temp = temp->next;
  }
  struct node *new = createNode(val);
  temp->next = new;
}

void insertAfter(struct node *temp, int val, int after) {
  while(temp->next != NULL && temp->data !=after) {
    temp = temp->next;
  }
  struct node *new = createNode(val);
  if(temp->next == NULL) {
    temp->next = new;
  } else {
    new->next = temp->next;
    temp->next = new;
  }
}

void insertbefore(struct node *temp, int val, int before) {
  struct node *new = createNode(val);
  if(temp->data == before && temp == head) {
    new->next = head;
    head = new;
    return;
  }
  while(temp->next->next != NULL && temp->next->data != before) {
    temp = temp->next;
  }
  if(temp->next == NULL) {
    temp->next = new;
  } else {
    new->next = temp->next;
    temp->next = new;
  }
}

int insertatPos(struct node *temp, int val, int pos, int size) {
  struct node *new = createNode(val);
  if(pos == 1) {
    new->next = head;
    head = new;
    return 1;
  } else if(pos <= size) {
    for(int i = 1; i<pos-1; i++) {
      temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
    return 1;
  } else {
    printf("Position out of bounds!\n");
    return 0;
  }
}

int insertbewteen

void main() {
  int choice, size, value, pos, after, before;
  while(1==1) {
    printf("\n-----------------------------\n");
    printf("\tMenu\n");
    printf("-----------------------------\n");
    printf("1. Create List.\n");
    printf("2. Display List.\n");
    printf("3. Search List.\n");
    printf("4. Insert at First.\n");
    printf("5. Insert at middle.\n");
    printf("6. Insert at last.\n");
    printf("7. Insert after a value.\n");
    printf("8. Insert before a value.\n");
    printf("9. Insert at specific position.\n");
    printf("10. Insert between 2 values.\n");
    printf("11. Delete at First.\n");
    printf("12. Delete at middle.\n");
    printf("13. Delete at last.\n");
    printf("14. Delete after a value.\n");
    printf("15. Delete before a value.\n");
    printf("16. Delete at specific position.\n");
    printf("17. Delete between 2 values.\n");
    printf("18. Quit.\n\n");
    printf("Enter your Choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("\nEnter the size of list: ");
      scanf("%d", &size);
      createList(size);
      break;
    case 2:
      if (head != NULL) {
        printf("\nCurrent List\n");
        displayList(head);
      } else {
        printf("\nThe List is Empty!!\n");
      }
      break;
    case 3:
      if (head != NULL) {
        printf("\nEnter a number to search: ");
        scanf("%d", &value);
        searchList(head, value);
      } else {
        printf("\nThe List is Empty!!\n");
      }
      break;
    case 4:
      if (head != NULL) {
        printf("\nEnter the value to be inserted: ");
        scanf("%d", &value);
        insertFirst(head, value);
        size++;
      } else {
        printf("\nThe List is Empty!!\n");
      }
      break;
    case 5:
      if (head != NULL) {
        printf("\nEnter the value to be inserted: ");
        scanf("%d", &value);
        insertMiddle(head, value, size);
        size++;
      } else {
        printf("\nThe List is Empty!!\n");
      }
      break;
    case 6:
      if (head != NULL) {
        printf("\nEnter the value to be inserted: ");
        scanf("%d", &value);
        insertLast(head, value);
        size++;
      } else {
        printf("\nThe List is Empty!!\n");
      }
      break;
    case 7:
      if (head != NULL) {
        printf("\nEnter the value to be inserted: ");
        scanf("%d", &value);
        printf("Enter the value after which to insert: ");
        scanf("%d", &after);
        insertAfter(head, value, after);
        size++;
      } else {
        printf("\nThe List is Empty!!\n");
      }
      break;
    case 8:
      if (head != NULL) {
        printf("\nEnter the value to be inserted: ");
        scanf("%d", &value);
        printf("Enter the value before which to insert: ");
        scanf("%d", &before);
        insertbefore(head, value, before);
        size++;
      } else {
        printf("\nThe List is Empty!!\n");
      }
      break;
    case 9:
      if (head != NULL) {
        printf("\nEnter the value to be inserted: ");
        scanf("%d", &value);
        printf("Enter the position at which value is to be inserted: ");
        scanf("%d", &pos);
        size = size + insertatPos(head, value, pos, size);
      } else {
        printf("\nThe List is Empty!!\n");
      }
      break;
    case 18:
      printf("\nThank You!\n");
      exit(0);
    default:
      printf("Wrong Choice!\n");
      break;
    }
  }
}