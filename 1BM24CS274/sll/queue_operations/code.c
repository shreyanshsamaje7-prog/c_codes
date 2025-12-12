#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = 0, rear = -1;

void insert(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        queue[++rear] = x;
        printf("%d inserted\n", x);
    }
}

void delet() {
    if (front > rear) {
        printf("Queue Empty\n");
    } else {
        printf("%d deleted\n", queue[front++]);
    }
}

void display() {
    if (front > rear) {
        printf("Queue Empty\n");
    } else {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, item;
    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                delet();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
