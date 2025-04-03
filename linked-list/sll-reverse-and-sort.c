#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverse(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void sort(Node** head) {
    if (*head == NULL || (*head)->next == NULL) return;

    Node* i, * j;
    int temp;
    for (i = *head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int main() {
    Node* head = NULL;

    insert(&head, 3);
    insert(&head, 1);
    insert(&head, 4);
    insert(&head, 2);
    
    printf("Original List:\n");
    printList(head);

    reverse(&head);
    printf("Reversed List:\n");
    printList(head);

    sort(&head);
    printf("Sorted List:\n");
    printList(head);

    return 0;
}
