#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash_table.h"


int main(void)
{
    const char key[] = "why";
    int value = 131;
    const char key2[] = "wyh";
    int value2 = 121;
    const char key3[] = "sss";
    int value3 = 531;
    int v[10];
    ht_entry* entry = create_entry(key, value);
    ht_entry* entry2 = create_entry(key2, value2);
    ht_entry* entry3 = create_entry(key3, value3);
    ht* htable = ht_create();

    printf("%d nodes in this index\n", insert(entry, htable));
    printf("%d nodes in this index\n", insert(entry2, htable));
    printf("%d nodes in this index\n", insert(entry3, htable));

    for (int i = 0;i< retrieve(htable, entry, v);i++)
        printf("key %s holds %d\n", key, v[i]);

    for (int i = 0;i < retrieve(htable, entry2, v);i++)
        printf("key %s holds %d\n", key2,  v[i]);

    for (int i = 0;i < retrieve(htable, entry3, v);i++)
        printf("key %s holds %d\n", key3, v[i]);

    return 1;
}