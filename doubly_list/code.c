#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;



void createList() {
    int value;
    printf("enter value (-999 to stop): ");
    scanf("%d",&value);
    while(value!=-999){
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }

        else{struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
        }

        printf("enter value (-999 to stop): ");
        scanf("%d",&value);
    }
}

void insertLeft(int target, int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    struct Node *temp = head;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("Target value not found.\n");
        free(newNode);
        return;
    }

    if (temp == head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

void deleteValue(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    if (temp == head) {
        head = temp->next;
        if (head) head->prev = NULL;
        free(temp);
        return;
    }

    if (temp->next == NULL) {
        temp->prev->next = NULL;
        free(temp);
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void display() {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, target;

    while (1) {
        printf("\n1.Create 2.InsertLeft 3.Delete 4.Display 5.Exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:

                createList();
                break;

            case 2:
                printf("enter target value & value to insert: ");
                scanf("%d %d", &target, &value);
                insertLeft(target, value);
                break;

            case 3:
                printf("enter value to delete: ");
                scanf("%d", &value);
                deleteValue(value);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;
        }
    }
}
