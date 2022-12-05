# Simple Chain Hash Table Implementation
![image](https://user-images.githubusercontent.com/50047346/201488178-37becbfb-e6a9-4e38-b7b1-95f095cf2c8e.png)

## Description

Hash table implementation with seperate chaining collision handling.
This means that when a new key maps to an already used index of the table, the new value is also stored in that index.

This is achieved by using a linked list inside the hash table structure and simply adding nodes to each index whenever a collision occurs.

The user can retrieve or delete any node on any index.

## Example

### Create new hash table
```c
ht* htable = ht_create();
```
### Create entry
```c
ht_entry* entry = create_entry(key, value);
```
### Insert entry
```c
insert(entry, htable);
```
### Retrieve entry
```c
retrieve(htable, entry, v);
```
### Delete entry
```c
delete(htable, entry);
```
Run the test example in the main file to try it out.

