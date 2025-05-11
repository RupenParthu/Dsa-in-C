#include <stdio.h>

#define SIZE 5

int deque[SIZE], front = -1, rear = -1;

// Check if deque is full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Check if deque is empty
int isEmpty() {
    return (front == -1);
}

// Insert element at the front of the deque
void insertFront(int value) {
    if (isFull()) {
        printf("Deque is Full!\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + SIZE) % SIZE;
    }
    deque[front] = value;
}

// Insert element at the rear of the deque
void insertRear(int value) {
    if (isFull()) {
        printf("Deque is Full!\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    deque[rear] = value;
}

// Delete element from the front of the deque
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is Empty!\n");
        return;
    }
    printf("Deleted: %d\n", deque[front]);
    if (front == rear) {
        front = rear = -1;  // Reset the deque if only one element was present
    } else {
        front = (front + 1) % SIZE;
    }
}

// Delete element from the rear of the deque
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is Empty!\n");
        return;
    }
    printf("Deleted: %d\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;  // Reset the deque if only one element was present
    } else {
        rear = (rear - 1 + SIZE) % SIZE;
    }
}

// Display elements of the deque
void display() {
    if (isEmpty()) {
        printf("Deque is Empty!\n");
        return;
    }
    printf("Deque Elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    insertFront(10);
    insertRear(20);
    insertRear(30);
    insertFront(40);
    display();

    deleteFront();
    deleteRear();
    display();
    
    return 0;
}
