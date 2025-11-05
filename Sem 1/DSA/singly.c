#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
  for (int i = 0; i < size; i++) {
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

bool checkempty() {
  if(head == NULL){
    printf("\nThe List is Empty!!\n");
    return false;
  } else {
    return true;
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

void countNodes(struct node *temp) {
  int count = 0;
  while(temp != NULL) {
    count++;
    temp = temp->next;
  }
  printf("The number of nodes in the list is: %d\n", count);
}

void displayAltNodes(struct node *temp) {
  int pos = 1;
  while(temp != NULL) {
    if(pos % 2 != 0) {
      printf("%d->", temp->data);
    }
    pos++;
    temp = temp->next;
  }
  printf("NULL\n");
}

void findMiddleNode(struct node *temp) {
  struct node *slow = temp, *fast = temp;
  while(fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  printf("The middle node value is: %d\n", slow->data);
}

void displayEvenPosNodes(struct node *temp) {
  int pos = 1;
  while(temp != NULL) {
    if(pos % 2 == 0) {
      printf("%d->", temp->data);
    }
    pos++;
    temp = temp->next;
  }
  printf("NULL\n");
}

void insertFirst(struct node *temp, int val) {
  struct node *new = createNode(val);
  new->next = head;
  head = new;
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

void insertatPos(struct node *temp, int val, int pos, int size) {
  struct node *new = createNode(val);
  if(pos == 1) {
    new->next = head;
    head = new;
    printf("Value inserted at position 1\n");
  } else if(pos <= size) {
    for(int i = 1; i<pos-1; i++) {
      temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
    printf("Value inserted at position %d\n", pos);
  } else {
    printf("Position out of bounds!\n");
  }
}

void insertbewteen(struct node *temp, int val, int val1, int val2) {
  struct node *new = createNode(val);
  while(temp->next != NULL && temp->data != val1 && temp->next->data != val2) {
    temp = temp->next;
  }
  if(temp->next == NULL) {
    printf("Values not found!\n");
  } else {
    new->next = temp->next;
    temp->next = new;
    printf("Value inserted between %d and %d\n", val1, val2);
  }
}

void deletefirst(struct node *temp) {
  struct node *del = head;
  head = head->next;
  free(del);
  printf("Node Deleted from first\n");
}

void deletlast(struct node *temp) {
  struct node *del;
  while(temp->next->next != NULL) {
    temp = temp->next;
  }
  del = temp->next;
  temp->next = NULL;
  free(del);
  printf("Node Deleted from last\n");
}

void deleteafter(struct node *temp, int val) {
  struct node *del;
  while(temp->next != NULL && temp->data == val){
    temp = temp->next;
  }
  if(temp->next == NULL){
    printf("The value was not found or no node to delete\n");
  } else {
    del = temp->next;
    temp->next = temp->next->next;
    free(del);
    printf("The node after value %d was deleted successfully.\n", val);
  }
}

void deletebefore(struct node *temp, int val) {
  struct node *del;
  if(temp->data == val){
    printf("No Node to delete before %d\n", val);
  }
  while(temp->next->next != NULL && temp->next->data != val) {
    temp = temp->next;
  }
  if(temp->next->next == NULL && temp->next->data == val){
    del = temp->next;
    temp->next == temp->next->next;
    free(del);
    printf("The node before value %d was deleted successfully.\n", val);
  } else {
    printf("The value was not found or no node to delete\n");
  }
}

void deletespecific(struct node *temp, int pos, int size) {
  struct node *del;
  if(pos == 1) {
    del = head;
    head = head->next;
    free(del);
    printf("Node Deleted from position 1\n");
  } else if(pos <= size) {
    for(int i = 1; i<pos-1; i++) {
      temp = temp->next;
    }
    del = temp->next;
    temp->next = temp->next->next;
    free(del);
    printf("Node Deleted from position %d\n", pos);
  } else {
    printf("Position out of bounds!\n");
  }
}

void deletebetween(struct node *temp, int val1, int val2) {
  struct node *del;
  while(temp->next != NULL && temp->data != val1 && temp->next->data != val2) {
    temp = temp->next;
  }
  if(temp->next == NULL) {
    printf("Values not found!\n");
  } else {
    del = temp->next;
    temp->next = temp->next->next;
    free(del);
    printf("Node between %d and %d deleted successfully\n", val1, val2);
  }
}

void reverseList(struct node *temp) {
  struct node *prev = NULL, *next = NULL;
  while(temp != NULL) {
    next = temp->next;
    temp->next = prev;
    prev = temp;
    temp = next;
  }
  head = prev;
  printf("List Reversed Successfully\n");
}

void main() {
  int choice, size, value, pos, after, before;
  while(1==1) {
    printf("\n-----------------------------\n");
    printf("\tMenu\n");
    printf("-----------------------------\n");
    printf("1. Create List.\n");
    printf("2. Display List.\n");
    printf("3. Search List.\n");
    printf("4. Count number of nodes.\n");
    printf("5. Display alternative node value from first node.\n");
    printf("6. Find the middle node value in the list.\n");
    printf("7. Display all the even positioned nodes.\n");
    printf("8. Insert at First.\n");
    printf("9. Insert at last.\n");
    printf("10. Insert after a value.\n");
    printf("11. Insert before a value.\n");
    printf("12. Insert at specific position.\n");
    printf("13. Insert between 2 values.\n");
    printf("14. Delete at First.\n");
    printf("15. Delete at last.\n");
    printf("16. Delete after a value.\n");
    printf("17. Delete before a value.\n");
    printf("18. Delete at specific position.\n");
    printf("19. Delete between 2 values.\n");
    printf("20. Reverse the list.\n");
    printf("21. Quit.\n\n");
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
      if (checkempty()) {
        printf("\nCurrent List\n");
        displayList(head);
      }
      break;
    case 3:
      if (checkempty()) {
        printf("\nEnter a number to search: ");
        scanf("%d", &value);
        searchList(head, value);
      }
      break;
    case 4:
      if (checkempty()) {
        countNodes(head);
      }
      break;
    case 5:
      if (checkempty()) {
        printf("\nAlternative Nodes: ");
        displayAltNodes(head);
      }
      break;
    case 6:
      if (checkempty()) {
        findMiddleNode(head);
      }
      break;
    case 7:
      if (checkempty()) {
        printf("\nEven Positioned Nodes: ");
        displayEvenPosNodes(head);
      }
      break;
    case 8:
      if (checkempty()) {
        printf("\nEnter the value to be inserted: ");
        scanf("%d", &value);
        insertFirst(head, value);
        size++;
      }
      break;
    case 9:
      if (checkempty()) {
        printf("\nEnter the value to be inserted: ");
        scanf("%d", &value);
        insertLast(head, value);
        size++;
      }
      break;
    case 10:
      if (checkempty()) {
        printf("\nEnter the value to be inserted: ");
        scanf("%d", &value);
        printf("Enter the value after which to insert: ");
        scanf("%d", &after);
        insertAfter(head, value, after);
        size++;
      }
      break;
    case 11:
      if (checkempty()) {
        printf("\nEnter the value to be inserted: ");
        scanf("%d", &value);
        printf("Enter the value before which to insert: ");
        scanf("%d", &before);
        insertbefore(head, value, before);
        size++;
      }
      break;
    case 12:
      if (checkempty()) {
        printf("\nEnter the value to be inserted: ");
        scanf("%d", &value);
        printf("Enter the position at which value is to be inserted: ");
        scanf("%d", &pos);
        size = size++;
      }
      break;
    case 13:
      if (checkempty()) {
        printf("\nEnter the value to be inserted: ");
        scanf("%d", &value);
        int val1, val2;
        printf("Enter the 2 values between which to insert: ");
        scanf("%d %d", &val1, &val2);
        insertbewteen(head, value, val1, val2);
        size++;
      }
      break;
    case 14:
      if (checkempty()) {
        deletefirst(head);
        size--;
      }
      break;
    case 15:
      if (checkempty()) {
        deletlast(head);
        size--;
      }
      break;
    case 16:
      if (checkempty()) {
        printf("\nEnter the value after which to delete: ");
        scanf("%d", &value);
        deleteafter(head, value);
        size--;
      }
      break;
    case 17:
      if (checkempty()) {
        printf("\nEnter the value before which to delete: ");
        scanf("%d", &value);
        deletebefore(head, value);
        size--;
      }
      break;
    case 18:
      if (checkempty()) {
        printf("\nEnter the position at which node is to be deleted: ");
        scanf("%d", &pos);
        deletespecific(head, pos, size);
        size--;
      }
      break;
    case 19:
      if (checkempty()) {
        int val1, val2;
        printf("\nEnter the 2 values between which to delete: ");
        scanf("%d %d", &val1, &val2);
        deletebetween(head, val1, val2);
        size--;
      }
      break;
    case 20:
      if (checkempty()) {
        reverseList(head);
      }
      break;
    case 21:
      printf("\nThank You!\n");
      exit(0);
    default:
      printf("Wrong Choice!\n");
      break;
    }
  }
}