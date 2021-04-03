#include <stdio.h>
#include <pthread.h>

#include "structure_types.h"

void Hash_Init(hash_t *H) {
    for (int i = 0; i < BUCKETS; i++) {
        List_Init(&H->lists[i]);
    }
}

// Hash function : key % BUCKETS

int Hash_Insert(hash_t *H, int key) {
    return List_Insert(&H->lists[key % BUCKETS], key);
}

int Hash_Lookup(hash_t *H, int key) {
    return List_Lookup(&H->lists[key % BUCKETS], key);
}