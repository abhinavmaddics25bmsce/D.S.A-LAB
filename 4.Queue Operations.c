#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert(int item) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = rear + 1;
        queue[rear] = item;
        printf("Inserted %d into Linear Queue\n", item);
    }
}

int delete() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        int item = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = front + 1;
        }
        return item;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, item, deletedItem;

    while (1) {
        printf("\n Linear Queue Operations\n");
        printf("1. Insert 2. Delete 3. Display 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter integer to insert: ");
                scanf("%d", &item);
                insert(item);
                break;

            case 2:
                deletedItem = delete();
                if (deletedItem != -1) {
                    printf("Deleted value: %d\n", deletedItem);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting Program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please select valid options.\n");
        }
    }
    return 0;
}
