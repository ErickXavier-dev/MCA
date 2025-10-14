#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} *head = NULL;

// create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
 
// 1. Create Doubly Linked List
void createList(int n) {
    int data;
    struct Node *newNode, *temp;
    head = NULL;
 
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        newNode = createNode(data);
        if (head == NULL)
          head = temp = newNode;
        else {
          temp->next = newNode;
          newNode->prev = temp;
          temp = newNode;
        }
    }
    printf("\nDoubly Linked List created successfully.\n");
}
 
// 2. Display the List
void displayList() {
  struct Node* temp = head;
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }
  printf("Doubly Linked List (Forward): ");
  while (temp != NULL) {
    printf("%d <-> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}
 
// 3. Search a value
void searchValue(int key) {
  struct Node* temp = head;
  int pos = 1;
  while (temp != NULL) {
    if (temp->data == key) {
      printf("Value %d found at position %d.\n", key, pos);
      return;
    }
    temp = temp->next;
    pos++;
  }
  printf("Value %d not found in the list.\n", key);
}
 
// 4. Count nodes
int countNodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
 
// 5. Display alternate nodes
void displayAlternate() {
    struct Node* temp = head;
    printf("Alternate nodes: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next ? temp->next->next : NULL;
    }
    printf("\n");
}
 
// 6. Display even positioned nodes
void displayEvenPositioned() {
    struct Node* temp = head;
    int pos = 1;
    printf("Even positioned nodes: ");
    while (temp != NULL) {
        if (pos % 2 == 0)
            printf("%d ", temp->data);
        temp = temp->next;
        pos++;
    }
    printf("\n");
}
 
// 7. Find middle node
void findMiddleNode() {
    struct Node *slow = head, *fast = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle node value: %d\n", slow->data);
}
 
// 8. Insert at beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
    printf("Node inserted at beginning.\n");
}
 
// 9. Insert at end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        printf("Node inserted at end.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    printf("Node inserted at end.\n");
}
 
// 10. Insert after a given node
void insertAfterNode(int key, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    printf("Node inserted after %d.\n", key);
}
 
// 11. Insert before a given node
void insertBeforeNode(int key, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        head = newNode;
    temp->prev = newNode;
    printf("Node inserted before %d.\n", key);
}
 
// 12. Insert between two nodes (key1, key2)
void insertBetweenNodes(int key1, int key2, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->data == key1 && temp->next->data == key2) {
            struct Node* newNode = createNode(data);
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            printf("Node inserted between %d and %d.\n", key1, key2);
            return;
        }
        temp = temp->next;
    }
    printf("Nodes %d and %d not found consecutively.\n", key1, key2);
}
 
// 13. Insert at position
void insertAtPosition(int pos, int data) {
    int count = countNodes();
    if (pos <= 0 || pos > count + 1) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    printf("Node inserted at position %d.\n", pos);
}
 
// 14. Delete first node
void deleteFirstNode() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
    printf("First node deleted.\n");
}
 
// 15. Delete last node
void deleteLastNode() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;
    free(temp);
    printf("Last node deleted.\n");
}
 
// 16. Delete after given node
void deleteAfterNode(int key) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) {
        printf("No node exists after %d.\n", key);
        return;
    }
    struct Node* del = temp->next;
    temp->next = del->next;
    if (del->next != NULL)
        del->next->prev = temp;
    free(del);
    printf("Node deleted after %d.\n", key);
}
 
// 17. Delete before given node
void deleteBeforeNode(int key) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL || temp->prev == NULL) {
        printf("No node exists before %d.\n", key);
        return;
    }
    struct Node* del = temp->prev;
    if (del->prev != NULL)
        del->prev->next = temp;
    else
        head = temp;
    temp->prev = del->prev;
    free(del);
    printf("Node deleted before %d.\n", key);
}
 
// 18. Delete at position
void deleteAtPosition(int pos) {
    if (head == NULL || pos <= 0) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        deleteFirstNode();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    printf("Node deleted at position %d.\n", pos);
}
 
// 19. Reverse the list
void reverseList() {
    struct Node *temp = NULL, *current = head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        head = temp->prev;
    printf("List reversed successfully.\n");
}

int main() {
    int choice, n, data, key, pos, key1, key2;
    while (1) {
        printf("\n===== MENU =====\n");
        printf("1. Create list\n");
        printf("2. Display list\n");
        printf("3. Search value\n");
        printf("4. Count nodes\n");
        printf("5. Display alternate nodes\n");
        printf("6. Display even positioned nodes\n");
        printf("7. Find middle node\n");
        printf("8. Insert at beginning\n");
        printf("9. Insert at end\n");
        printf("10. Insert after node\n");
        printf("11. Insert before node\n");
        printf("12. Insert between nodes\n");
        printf("13. Insert at position\n");
        printf("14. Delete first node\n");
        printf("15. Delete last node\n");
        printf("16. Delete after node\n");
        printf("17. Delete before node\n");
        printf("18. Delete at position\n");
        printf("19. Reverse list\n");
        printf("20. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &data);
                searchValue(data);
                break;
            case 4:
                printf("Total nodes: %d\n", countNodes());
                break;
            case 5:
                displayAlternate();
                break;
            case 6:
                displayEvenPositioned();
                break;
            case 7:
                findMiddleNode();
                break;
            case 8:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 9:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 10:
                printf("Enter key and data: ");
                scanf("%d %d", &key, &data);
                insertAfterNode(key, data);
                break;
            case 11:
                printf("Enter key and data: ");
                scanf("%d %d", &key, &data);
                insertBeforeNode(key, data);
                break;
            case 12:
                printf("Enter key1, key2, and data: ");
                scanf("%d %d %d", &key1, &key2, &data);
                insertBetweenNodes(key1, key2, data);
                break;
            case 13:
                printf("Enter position and data: ");
                scanf("%d %d", &pos, &data);
                insertAtPosition(pos, data);
                break;
            case 14:
                deleteFirstNode();
                break;
            case 15:
                deleteLastNode();
                break;
            case 16:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteAfterNode(key);
                break;
            case 17:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteBeforeNode(key);
                break;
            case 18:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 19:
                reverseList();
                break;
            case 20:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
