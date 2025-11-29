#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create initial list
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
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}



// Display the linked list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Sort the linked list (Bubble Sort)
void sortList(struct Node* head) {
    struct Node *i, *j;
    int temp;

    if (head == NULL)
        return;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

// Concatenate two linked lists
struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

int main() {
    int choice;
    struct Node *list2 = NULL;

    while (1) {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Sort List\n");
        printf("4. Reverse List\n");
        printf("5. Concatenate Two Lists\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = NULL;
                createList();
                break;

            case 2:
                printf("Linked List: ");
                display(head);
                break;

            case 3:
                sortList(head);
                printf("List After Sorting: ");
                display(head);
                break;

            case 4:
                reverseList(&head);
                printf("List After Reversing: ");
                display(head);
                break;

            case 5:
                printf("Create second list for concatenation:\n");
                list2 = NULL;
                head = head;
                createList();


                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
