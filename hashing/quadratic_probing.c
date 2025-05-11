#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 15

// Status definitions for a slot in the hash table
#define EMPTY 0
#define OCCUPIED 1
#define DELETED 2

// Hash function: simple modulo operation
int hash(int key) {
    return key % TABLE_SIZE;
}

// Structure for a hash table entry
typedef struct {
    int key;
    int status; // EMPTY, OCCUPIED, or DELETED
} HashEntry;

// Structure for the hash table
typedef struct {
    HashEntry* table;
} HashTable;

// Create a new hash table and initialize all slots as EMPTY
HashTable* createHashTable() {
    HashTable* ht = malloc(sizeof(HashTable));
    if (!ht) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    ht->table = malloc(TABLE_SIZE * sizeof(HashEntry));
    if (!ht->table) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i].status = EMPTY;
    }

    return ht;
}

// Insert a key using quadratic probing
void insert(HashTable* ht, int key) {
    int h = hash(key);
    int index;

    for (int i = 0; i < TABLE_SIZE; i++) {
        index = (h + i * i) % TABLE_SIZE;

        if (ht->table[index].status != OCCUPIED) {
            ht->table[index].key = key;
            ht->table[index].status = OCCUPIED;
            return;
        }
    }

    printf("Hash table is full. Cannot insert key %d.\n", key);
}

// Search for a key using quadratic probing
int search(HashTable* ht, int key) {
    int h = hash(key);
    int index;

    for (int i = 0; i < TABLE_SIZE; i++) {
        index = (h + i * i) % TABLE_SIZE;

        if (ht->table[index].status == EMPTY)
            return -1; // Key not present

        if (ht->table[index].status == OCCUPIED && ht->table[index].key == key)
            return index;
    }

    return -1;
}

// Delete a key using quadratic probing by marking its slot as DELETED
void deleteKey(HashTable* ht, int key) {
    int index = search(ht, key);

    if (index != -1) {
        ht->table[index].status = DELETED;
        printf("Key %d deleted from index %d.\n", key, index);
    } else {
        printf("Key %d not found for deletion.\n", key);
    }
}

// Display the contents of the hash table
void display(HashTable* ht) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i].status == OCCUPIED)
            printf("Index %d: %d\n", i, ht->table[i].key);
        else if (ht->table[i].status == DELETED)
            printf("Index %d: DELETED\n", i);
        else
            printf("Index %d: EMPTY\n", i);
    }
}

int main() {
    // Create the hash table
    HashTable* ht = createHashTable();

    // Insert keys (demonstrating quadratic probing)
    insert(ht, 8);
    insert(ht, 23);
    insert(ht, 38);
    insert(ht, 53);
    insert(ht, 68);
    insert(ht, 83);
    insert(ht, 98);
    insert(ht, 113);

    // Display the hash table
    display(ht);

    // Test deletion: Delete an existing key
    printf("\nDeleting key 53...\n");
    deleteKey(ht, 53);
    display(ht);

    // Attempt to delete a non-existent key
    printf("\nDeleting key 200 (non-existent)...\n");
    deleteKey(ht, 200);

    // Search for the deleted key
    int index = search(ht, 53);
    if (index == -1)
        printf("Key 53 not found (as expected after deletion).\n");
    else
        printf("Key 53 found at index %d (error).\n", index);

    // Insert a new key that should reuse the DELETED slot
    printf("\nInserting key 77 (should reuse DELETED slot)...\n");
    insert(ht, 77);
    display(ht);

    // Free memory
    free(ht->table);
    free(ht);

    return 0;
}
