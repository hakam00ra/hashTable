#pragma once
#ifndef HASH_TABLE
#define HASH_TABLE

typedef struct {
    char* key;
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
ht_entry* create_entry(const char* key, int value);
int hash_key(const char* key);
int getSize(ht* table);
int insert(ht_entry* entry, ht* table);
int delete(ht* table, ht_entry* entry);
int retrieve(ht* table, ht_entry* entry, int* values);
struct linkedList* createList(void);
int insertNode(int index, ht_entry* entry, ht* table);
#endif