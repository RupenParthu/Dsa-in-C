#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 15
#define EMPTY -1
#define DELETED -2

int hash(int key) {
    return key % TABLE_SIZE;
}

typedef struct {
    int key;
    int isOccupied;
} HashEntry;

typedef struct {
    HashEntry* table;
} HashTable;

HashTable* createHashTable() {
    HashTable* ht = malloc(sizeof(HashTable));
    ht->table = malloc(TABLE_SIZE * sizeof(HashEntry));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i].key = EMPTY;
        ht->table[i].isOccupied = 0;
    }
    return ht;
}

void insert(HashTable* ht, int key) {
    int index = hash(key);
    int orig = index;
    while (ht->table[index].isOccupied && ht->table[index].isOccupied != DELETED) {
        index = (index + 1) % TABLE_SIZE;
        if (index == orig) {
            printf("Hash table is full. Cannot insert key %d.\n", key);
            return;
        }
    }
    ht->table[index].key = key;
    ht->table[index].isOccupied = 1;
}

int search(HashTable* ht, int key) {
    int index = hash(key);
    int orig = index;
    while (ht->table[index].isOccupied) {
        if (ht->table[index].isOccupied == 1 && ht->table[index].key == key)
            return index;
        index = (index + 1) % TABLE_SIZE;
        if (index == orig)
            break;
    }
    return -1;
}

void deleteKey(HashTable* ht, int key) {
    int index = search(ht, key);
    if (index != -1) {
        ht->table[index].isOccupied = DELETED;
        printf("Key %d deleted from index %d.\n", key, index);
    } else {
        printf("Key %d not found for deletion.\n", key);
    }
}

void display(HashTable* ht) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i].isOccupied == 1)
            printf("Index %d: %d\n", i, ht->table[i].key);
        else
            printf("Index %d: EMPTY\n", i);
    }
}

int main() {
    HashTable* ht = createHashTable();
    insert(ht, 8);
    insert(ht, 23);
    insert(ht, 38);
    insert(ht, 53);
    insert(ht, 68);
    insert(ht, 83);
    insert(ht, 98);
    insert(ht, 113);

    display(ht);

    printf("\nDeleting key 53...\n");
    deleteKey(ht, 53);
    display(ht);

    printf("\nDeleting key 200 (non-existent)...\n");
    deleteKey(ht, 200);

    int index = search(ht, 53);
    if (index == -1)
        printf("Key 53 not found (as expected after deletion).\n");
    else
        printf("Key 53 found at index %d (error).\n", index);

    printf("\nInserting key 77 (should reuse DELETED slot)...\n");
    insert(ht, 77);
    display(ht);

    free(ht->table);
    free(ht);
    return 0;
}
