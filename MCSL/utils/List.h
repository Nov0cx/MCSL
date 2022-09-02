#ifndef MCSL_LIST_H
#define MCSL_LIST_H

#ifndef LIST_INITIAL_CAPACITY
#define LIST_INITIAL_CAPACITY 64
#endif

typedef struct {
    void** data;
    int size;
    int capacity;
} List;

List* list_new();
void list_free(List* list);
void list_add(List* list, void* item);
void list_set(List* list, int index, void* item);
void* list_get(List* list, int index);
void list_remove(List* list, int index);


#endif //MCSL_LIST_H
