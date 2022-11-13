#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash_table.h"
#pragma warning(disable:4996)

ht* ht_create(void)
{
    ht* table = malloc(sizeof(ht));
    table->length = 0;
    table->capacity = 400;
    table->nodes = calloc(table->capacity, sizeof(struct linkedList*));
    for (int i = 0;i < table->capacity;i++)
        table->nodes[i] = createList();
    return table;
}

ht_entry* create_entry(char* key, int value)
{
    ht_entry* entry = malloc(sizeof(ht_entry));
    entry->key = malloc(sizeof(key) + 1);
    entry->value = value;

    strcpy(entry->key, key);
    return entry;
}

int hash_key(const char* key)
{
    int hash = 0;
    for (const char* p = key; *p; p++)
        hash += *p;
    //printf("index %d\n", hash % 400);
    return hash%400;
}

int insert(ht_entry* entry, ht* table)
{
    int index = hash_key(entry->key);
    table->length += 1;
    return insertNode(index, entry, table);
}

int* retrieve(ht* table, ht_entry* entry, int* reValues)
{
    int index = hash_key(entry->key);
    struct linkedList* temp = table->nodes[index];
    int nodes = 0;

    while (temp) {        
        reValues[nodes++] = temp->entry->value;
        temp = temp->next;
    }
    return nodes;
}

int getSize(ht* table)
{
    return table->length;
}

int delete(ht* table, ht_entry* entry, int node)
{
    int index = hash_key(entry->key);

    if (table->nodes[index]==NULL)
        return 0;
    else
        --(table->length);

    // TODO, delete node


    return 1;
}


struct linkedList* createList(void)
{
    struct linkedList* list = (struct linkedList*)malloc(sizeof(struct linkedList));

    list->entry = NULL;
    list->next = NULL;
    list->size = 0;
    return list;
}

int insertNode(int index, ht_entry* entry, ht* table)
{
    if (table->nodes[index]->entry == NULL)
        table->nodes[index]->entry = entry;    
    else {
        struct linkedList* head = createList();
        table->nodes[index]->next = head;
        head->entry = entry;
        head->next = NULL;
    }    
    return ++(table->nodes[index]->size);
}
