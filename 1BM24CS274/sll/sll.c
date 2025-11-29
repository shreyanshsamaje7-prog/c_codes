#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void createList() {
    int item;
    struct Node *newNode, *temp;

    printf("Enter elements to create list (-999 to stop): ");
    scanf("%d", &item);

    while (item != -999) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = item;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }

        scanf("%d", &item);
    }
}

void insertAtFirst(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int item) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp;

    newNode->data = item;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void insertAtPosition(int item, int pos) {
    struct Node *newNode, *temp;
    int i;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid Position!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFirst() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

void deleteLast() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    if (head->next == NULL) {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    printf("Deleted: %d\n", temp->data);
    prev->next = NULL;
    free(temp);
}

void deleteElement(int item) {
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->data == item) {
        printf("Deleted: %d\n", temp->data);
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != item) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found!\n", item);
        return;
    }

    prev->next = temp->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}


void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, item, pos;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Insert  at First\n");
        printf("3. Insert at Any Position\n");
        printf("4. Insert at End\n");
        printf("5. Delete First Element\n");
        printf("6. Delete Last Element\n");
        printf("7. Delete Specific Element\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList();
                break;

            case 2:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                insertAtFirst(item);
                break;

            case 3:
                printf("Enter item and position: ");
                scanf("%d %d", &item, &pos);
                insertAtPosition(item, pos);
                break;

            case 4:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                insertAtEnd(item);
                break;

            case 5:
                deleteFirst();
                break;

            case 6:
                deleteLast();
                break;

            case 7:
                printf("Enter element to delete: ");
                scanf("%d", &item);
                deleteElement(item);
                break;

            case 8:
                display();
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
