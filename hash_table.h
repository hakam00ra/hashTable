#pragma once
#ifndef HASH_TABLE
#define HASH_TABLE

typedef struct {
    const char* key;
    int value;
} ht_entry;

struct linkedList {
    int size;
    ht_entry* entry;
    struct linkedList* next;
};

typedef struct {
    struct linkedList** nodes;
    int capacity;
    int length;
} ht;




ht* ht_create(void);
ht_entry* create_entry(char* key, int value);
int hash_key(const char* key);
int insert(ht_entry* entry, ht* table);
int* retrieve(ht* table, ht_entry* entry, int* values);
struct linkedList* createList(void);
int insertNode(int index, ht_entry* entry, ht* table);
#endif