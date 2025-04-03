#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
typedef struct node snode;

int menu() {
    int choice;
    printf("\n===== Linked List Menu =====\n");
    printf("1. Create List\n");
    printf("2. Insert at Beginning\n");
    printf("3. Insert at End\n");
    printf("4. Insert at Position\n");
    printf("5. Delete at Beginning\n");
    printf("6. Delete at End\n");
    printf("7. Delete at Position\n");
    printf("8. Display List\n");
    printf("9. Search for Element\n");
    printf("10. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

snode* createnode(int ele) {
    snode* p = (snode*)malloc(sizeof(snode));
    p->data = ele;
    p->next = NULL;
    return p;
}

snode* createlist(snode* head) {
    snode *p, *q;
    int ele;
    char a;
    do {
        printf("Enter the element: ");
        scanf("%d", &ele);
        p = createnode(ele);
        if (head == NULL) {
            head = p;
        } else {
            q = head;
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;
        }
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &a); // Space before %c to consume newline
    } while (a == 'y' || a == 'Y');
    return head;
}

snode* insertbeg(snode* head) {
    int ele;
    printf("Enter the element: ");
    scanf("%d", &ele);
    snode* p = createnode(ele);
    p->next = head;
    return p;
}

snode* insertend(snode* head) {
    int ele;
    printf("Enter the element: ");
    scanf("%d", &ele);
    snode* p = createnode(ele);
    if (head == NULL) {
        return p;
    }
    snode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = p;
    return head;
}

snode* insertatpos(snode* head) {
    int ele, pos;
    printf("Enter the element and position: ");
    scanf("%d%d", &ele, &pos);
    snode* p = createnode(ele);
    
    if (pos < 1) {
        printf("Invalid position!\n");
        return head;
    }
    if (pos == 1) {
        p->next = head;
        return p;
    }
    snode* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(p);
        return head;
    }
    p->next = temp->next;
    temp->next = p;
    return head;
}

snode* delatbeg(snode* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }
    snode* temp = head;
    head = head->next;
    free(temp);
    return head;
}

snode* delatend(snode* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    snode* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    snode* del = temp->next;
    temp->next = NULL;
    free(del);
    return head;
}

snode* delatpos(snode* head) {
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    if (head == NULL || pos < 1) {
        printf("Invalid position!\n");
        return head;
    }
    if (pos == 1) {
        snode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    snode* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds!\n");
        return head;
    }
    snode* del = temp->next;
    temp->next = del->next;
    free(del);
    return head;
}

void search(snode* head) {
    int key, position = 1;
    printf("Enter the element to search: ");
    scanf("%d", &key);
    snode* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element found at position %d\n", position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element not found!\n");
}

void display(snode* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    snode* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    snode* head = NULL;
    int choice;
    do {
        choice = menu();
        switch (choice) {
            case 1:
                head = createlist(head);
                break;
            case 2:
                head = insertbeg(head);
                break;
            case 3:
                head = insertend(head);
                break;
            case 4:
                head = insertatpos(head);
                break;
            case 5:
                head = delatbeg(head);
                break;
            case 6:
                head = delatend(head);
                break;
            case 7:
                head = delatpos(head);
                break;
            case 8:
                display(head);
                break;
            case 9:
                search(head);
                break;
            case 10:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice >= 10);

    return 0;
}
