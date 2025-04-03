#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
typedef struct Node dnode;

dnode* getNode(int data){
    dnode* temp = (dnode*)malloc(sizeof(dnode));
    temp->data = data;
    temp->next = temp;
    temp->prev = temp;
    return temp;
}

dnode* createList(dnode* head){
    dnode* p;
    dnode* q;
    char a;
    int n;
    do{
        printf("Enter Element: ");
        scanf("%d", &n);
        p = getNode(n);
        if(!head){
            head = p;
        }
        else{
            q = head->prev;
            q->next = p;
            p->prev = q;
            p->next = head;
            head->prev = p;
        }
        printf("Do you want to continue? (y or n): ");
        scanf(" %c", &a);
    } while(a == 'y' || a == 'Y');
    return head;
}

dnode* insertAtBeginning(dnode* head, int data){
    dnode* p = getNode(data);
    if(!head){
        head = p;
    }
    else{
        dnode* q = head->prev;
        p->next = head;
        p->prev = q;
        q->next = p;
        head->prev = p;
        head = p;
    }
    return head;
}

dnode* insertAtLast(dnode* head, int data){
    dnode* p = getNode(data);
    if(!head){
        head = p;
    }
    else{
        dnode* q = head->prev;
        q->next = p;
        p->prev = q;
        p->next = head;
        head->prev = p;
    }
    return head;
}

dnode* insertAtPosition(dnode* head, int data, int position){
    if(!head && position > 1){
        printf("Index out of range!\n");
    }
    else{
        dnode* temp = head;
        dnode* p = getNode(data);
        for(int i = 1; i < position - 1; i++){
            temp = temp->next;
        }
        p->next = temp->next;
        temp->next->prev = p;
        temp->next = p;
        p->prev = temp;
    }
    return head;
}

dnode* deleteFirst(dnode* head){
    if(!head){
        printf("Sorry the list is empty\n");
    }
    else{
        dnode* temp = head;
        head = head->next;
        head->prev = temp->prev;
        temp->prev->next = head;
        free(temp);
    }
    return head;
}

dnode* deleteLast(dnode* head){
    if(!head){
        printf("Sorry the list is empty\n");
    }
    else{
        dnode* temp = head->prev;
        temp->prev->next = head;
        head->prev = temp->prev;
        free(temp);
    }
    return head;
}

dnode* deleteAtPosition(dnode* head){
    printf("Specify the position: \n");
    int p;
    scanf("%d", &p);
    if(!head){
        printf("Sorry the list is already empty!\n");
    }
    else{
        dnode* temp = head;
        for(int i = 1; i < p - 1; i++){
            temp = temp->next;
        }
        dnode* q = temp->next;
        temp->next = q->next;
        q->next->prev = temp;
        free(q);
    }
    return head;
}

void display(dnode* head){
    if(!head){
        printf("Sorry the list is empty\n");
    }
    else{
        dnode* temp = head;
        do{
            printf("%5d", temp->data);
            temp = temp->next;
        } while(temp != head);
        printf("\n");
    }
}

void displayRev(dnode* head){
    if(head){
        dnode* temp = head->prev;
        do{
            printf("%5d", temp->data);
            temp = temp->prev;
        } while(temp != head->prev);
        printf("\n");
    }
}

int findEle(dnode* head, int ele){
    dnode* p = head;
    do{
        if(p->data == ele) return 1;
        p = p->next;
    } while(p != head);
    return 0;
}

void lengthoflist(dnode* head){
    int count = 0;
    if(!head){
        printf("No element is available\n");
    }
    else{
        dnode* temp = head;
        do{
            count++;
            temp = temp->next;
        } while(temp != head);
    }
    printf("%d\n", count);
}

int menu(){
    printf("\nMenu: \n");
    printf("1. Create List\n");
    printf("2. Insert At Beginning\n");
    printf("3. Insert At End\n");
    printf("4. Insert At Position\n");
    printf("5. Delete First Element\n");
    printf("6. Delete Last Element\n");
    printf("7. Delete Element At A Position\n");
    printf("8. Display List\n");
    printf("9. Find Element\n");
    printf("10. Display in Reverse Order\n");
    printf("11. Length\n");
    printf("12. Exit\n");
    printf("\n Enter Your Choice: ");
    int inp;
    scanf("%d", &inp);
    return inp;
}

int main(){
    dnode* head = NULL;
    int inp, data, ele;
    do{
        inp = menu();
        switch (inp){
            case 1: head = createList(head); break;
            case 2: printf("Enter Element: "); scanf("%d", &data); head = insertAtBeginning(head, data); break;
            case 3: printf("Enter Element: "); scanf("%d", &data); head = insertAtLast(head, data); break;
            case 4: printf("Enter Position: "); int pos; scanf("%d", &pos); printf("Enter Element: "); scanf("%d", &data); head = insertAtPosition(head, data, pos); break;
            case 5: head = deleteFirst(head); break;
            case 6: head = deleteLast(head); break;
            case 7: head = deleteAtPosition(head); break;
            case 8: display(head); break;
            case 9: printf("Enter Element: "); scanf("%d", &ele); printf(findEle(head, ele) ? "Element Found\n" : "Element Not Found\n"); break;
            case 10: displayRev(head); break;
            case 11: lengthoflist(head); break;
            case 12: break;
            default: printf("Invalid Choice. Try again\n"); break;
        }
    } while(inp <= 11);
    return 0;
}
