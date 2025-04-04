#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

void deleteAtBeginning(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    Node* last = *head;
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    while (last->next != *head)
        last = last->next;
    *head = (*head)->next;
    last->next = *head;
    free(temp);
}

void deleteNode(Node** head, int key) {
    if (*head == NULL) return;
    Node *current = *head, *prev = NULL;
    if ((*head)->data == key && (*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    while (current->next != *head && current->data != key) {
        prev = current;
        current = current->next;
    }
    if (current->data == key) {
        if (current == *head) {
            prev = *head;
            while (prev->next != *head)
                prev = prev->next;
            *head = (*head)->next;
            prev->next = *head;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
}

void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int search(Node* head, int key) {
    if (head == NULL) return 0;
    Node* temp = head;
    do {
        if (temp->data == key) return 1;
        temp = temp->next;
    } while (temp != head);
    return 0;
}

void reverse(Node** head) {
    if (*head == NULL || (*head)->next == *head) return;
    Node *prev = NULL, *current = *head, *next = NULL;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head);
    (*head)->next = prev;
    *head = prev;
}

void sort(Node** head) {
    if (*head == NULL || (*head)->next == *head) return;
    Node *i, *j;
    int temp;
    for (i = *head; i->next != *head; i = i->next) {
        for (j = i->next; j != *head; j = j->next) {
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

    insertAtEnd(&head, 3);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 2);

    printf("Original Circular List:\n");
    printList(head);

    insertAtBeginning(&head, 0);
    printf("After Inserting 0 at Beginning:\n");
    printList(head);

    deleteAtBeginning(&head);
    printf("After Deleting from Beginning:\n");
    printList(head);

    deleteNode(&head, 4);
    printf("After Deleting 4:\n");
    printList(head);

    printf("Search 2: %s\n", search(head, 2) ? "Found" : "Not Found");
    printf("Search 5: %s\n", search(head, 5) ? "Found" : "Not Found");

    reverse(&head);
    printf("Reversed Circular List:\n");
    printList(head);

    sort(&head);
    printf("Sorted Circular List:\n");
    printList(head);

    return 0;
}
