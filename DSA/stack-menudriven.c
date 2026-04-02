#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push() {
    int val;

    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }

    printf("Enter value to push: ");
    scanf("%d", &val);

    top++;
    stack[top] = val;

    printf("Element pushed successfully.\n");
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", stack[top]);
    top--;
}

// Peek operation
void peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Top element is: %d\n", stack[top]);
}

// Display operation
void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements are:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

// Main function (menu-driven)
int main() {
    int choice;

    do {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
