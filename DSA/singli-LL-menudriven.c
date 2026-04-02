#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create linked list
void createList() {
    int n, val;
    struct Node *temp, *newNode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter value: ");
        scanf("%d", &val);

        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    printf("Linked list created successfully.\n");
}

// Insert at beginning
void insertBeginning() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &newNode->data);

    newNode->next = head;
    head = newNode;

    printf("Inserted at beginning.\n");
}

// Insert at end
void insertEnd() {
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Inserted at end.\n");
}

// Insert at position
void insertPosition() {
    int pos, i;
    struct Node *newNode, *temp;

    printf("Enter position: ");
    scanf("%d", &pos);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &newNode->data);

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted at position %d.\n", pos);
}

// Delete by value
void deleteByValue() {
    int val;
    struct Node *temp = head, *prev = NULL;

    printf("Enter value to delete: ");
    scanf("%d", &val);

    if (temp != NULL && temp->data == val) {
        head = temp->next;
        free(temp);
        printf("Node deleted.\n");
        return;
    }

    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Node deleted.\n");
}

// Delete by position
void deleteByPosition() {
    int pos, i;
    struct Node *temp = head, *prev = NULL;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1 && temp != NULL) {
        head = temp->next;
        free(temp);
        printf("Node deleted.\n");
        return;
    }

    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Node deleted.\n");
}

// Traverse and display
void display() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete by Value\n");
        printf("6. Delete by Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createList(); break;
            case 2: insertBeginning(); break;
            case 3: insertEnd(); break;
            case 4: insertPosition(); break;
            case 5: deleteByValue(); break;
            case 6: deleteByPosition(); break;
            case 7: display(); break;
            case 8: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 8);

    return 0;
}
