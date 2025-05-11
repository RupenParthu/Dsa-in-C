#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 5

struct Node {
    int data;
    struct Node* next;
};

struct Node* table[TABLE_SIZE] = {NULL};

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hash(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = table[index];
    table[index] = newNode;
}

struct Node* search(int key) {
    int index = hash(key);
    struct Node* current = table[index];
    while (current != NULL) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return NULL;
}

void delete(int key) {
    int index = hash(key);
    struct Node* current = table[index];
    struct Node* prev = NULL;
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) return;
    if (prev == NULL)
        table[index] = current->next;
    else
        prev->next = current->next;
    free(current);
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d: ", i);
        struct Node* current = table[i];
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    insert(23);
    insert(11);
    insert(36);
    display();
    if (search(11))
        printf("11 found\n");
    else
        printf("11 not found\n");
    delete(11);
    display();
    return 0;
}
