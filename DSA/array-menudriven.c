#include <stdio.h>

#define MAX 100

int arr[MAX], n = 0;

// Function to display array
void display() {
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert element
void insert() {
    int pos, val;

    if (n == MAX) {
        printf("Array is full!\n");
        return;
    }

    printf("Enter position (1 to %d): ", n + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &val);

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = val;
    n++;

    printf("Element inserted successfully.\n");
}

// Function to delete element
void deleteElement() {
    int pos;

    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;
    printf("Element deleted successfully.\n");
}

// Function for linear search
void search() {
    int key, found = 0;

    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element not found!\n");
    }
}

// Main function (menu-driven)
int main() {
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Traverse (Display)\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Search Element\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                insert();
                break;
            case 3:
                deleteElement();
                break;
            case 4:
                search();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
