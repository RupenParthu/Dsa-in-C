#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};
typedef struct node dnode;

int menu(int choice) {
    printf(" Doubly linked list\n");
    printf("1. Create list\n");
    printf("2. Insert at begin\n");
    printf("3. Insert at end\n");
    printf("4. Insert at given position\n");
    printf("5. Deletion at begin\n");
    printf("6. Deletion at end\n");
    printf("7. Deletion at given position\n");
    printf("8. Display the elements\n");
    printf("9. Search an element\n");
    printf("10. Exit\n");
    printf("Enter the number: ");
    scanf("%d", &choice);
    return choice;
}

dnode* getnode(int element) {
    dnode* p = (dnode*)malloc(sizeof(dnode));
    p->data = element;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

dnode* create(dnode* head) {
    dnode *p, *q;
    int element;
    char a;
    do {
        printf("Enter the element: ");
        scanf("%d", &element);
        p = getnode(element);
        if (!head) {
            head = p;
        } else {
            q = head;
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;
            p->prev = q;
        }
        printf("Do you want to continue? (y or n): ");
        scanf(" %c", &a);
    } while (a == 'y' || a == 'Y');
    return head;
}

dnode* insertbegin(dnode* head, int element) {
    dnode* p = getnode(element);
    if (head == NULL) {
        head = p;
    } else {
        p->next = head;
        head->prev = p;
        head = p;
    }
    return head;
}

dnode* insertionend(dnode* head, int element) {
    dnode* temp;
    dnode* p = getnode(element);
    if (head == NULL) {
        head = p;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
        p->prev = temp;
    }
    return head;
}

dnode* addelement(dnode* head, int element, int position) {
    dnode* temp;
    dnode* p = getnode(element);
    if (!head || position <= 1) {
        return insertbegin(head, element);
    }
    temp = head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    p->next = temp->next;
    p->prev = temp;
    if (temp->next) {
        temp->next->prev = p;
    }
    temp->next = p;
    return head;
}

dnode* deletionbegin(dnode* head) {
    if (!head) return NULL;
    dnode* temp = head;
    head = head->next;
    if (head) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

dnode* deletionend(dnode* head) {
    if (!head) return NULL;
    dnode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
    return head;
}

dnode* deletionelement(dnode* head, int position) {
    if (!head) return NULL;
    if (position == 1) return deletionbegin(head);
    dnode* temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (!temp) return head;
    if (temp->prev) {
        temp->prev->next = temp->next;
    }
    if (temp->next) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    return head;
}

void display(dnode* head) {
    dnode* temp;
    if (!head) {
        printf("The list is empty\n");
        return;
    }
    temp = head;
    while (temp != NULL) {
        printf("%5d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

dnode* searchelement(dnode* head, int element) {
    dnode* temp = head;
    while (temp != NULL) {
        if (temp->data == element) {
            printf("Element %d found\n", element);
            return temp;
        }
        temp = temp->next;
    }
    printf("Element %d not found\n", element);
    return NULL;
}

int main() {
    dnode* head = NULL;
    int choice = 0, element, position;
    do {
        choice = menu(choice);
        switch (choice) {
            case 1:
                head = create(head);
                break;
            case 2:
                printf("Enter the element: ");
                scanf("%d", &element);
                head = insertbegin(head, element);
                break;
            case 3:
                printf("Enter the element: ");
                scanf("%d", &element);
                head = insertionend(head, element);
                break;
            case 4:
                printf("Enter the element, position: ");
                scanf("%d%d", &element, &position);
                head = addelement(head, element, position);
                break;
            case 5:
                head = deletionbegin(head);
                break;
            case 6:
                head = deletionend(head);
                break;
            case 7:
                printf("Enter the position: ");
                scanf("%d", &position);
                head = deletionelement(head, position);
                break;
            case 8:
                display(head);
                break;
            case 9:
                printf("Enter the element: ");
                scanf("%d", &element);
                searchelement(head, element);
                break;
            case 10:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice <= 9);
    return 0;
}
