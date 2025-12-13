#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void display(struct node* root) {
    if (root == NULL) {
        printf("Tree is empty");
        return;
    }
    inorder(root);
}

int main() {
    struct node* root = NULL;
    int choice, value;

    do {
        printf("\n1.Construct BST");
        printf("\n2.Inorder Traversal");
        printf("\n3.Preorder Traversal");
        printf("\n4.Postorder Traversal");
        printf("\n5.Display");
        printf("\n6.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Tree Elements: ");
                display(root);
                printf("\n");
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}
