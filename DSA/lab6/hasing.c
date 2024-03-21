#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10


// Hash function using division hashing
int hash_function(int key) {
    return key % TABLE_SIZE;
}

int main() {
    // Initialize hash table with empty slots
    int hash_table[TABLE_SIZE] = {0};

    // Array of keys to be inserted into the hash table
    int keys[] = {12, 28, 17, 33, 7};
    int n = sizeof(keys) / sizeof(keys[0]);

    // Insert keys into the hash table
    for (int i = 0; i < n; i++) {
        int index = hash_function(keys[i]);
        printf("Key: %d, Hashed Index: %d\n", keys[i], index);
        // Handling collisions by linear probing
        while (hash_table[index] != 0) {
            index = (index + 1) % TABLE_SIZE;
            printf("Collision occurred. Trying index: %d\n", index);
        }
        hash_table[index] = keys[i];
    }

    // Display the hash table
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d] -> %d\n", i, hash_table[i]);
    }

    return 0;
}
