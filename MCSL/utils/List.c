#include "List.h"
#include <stdlib.h>

List* list_new()
{
    List* list = malloc(sizeof(List));
    list->data = malloc(sizeof(void*) * LIST_INITIAL_CAPACITY);
    list->size = 0;
    list->capacity = LIST_INITIAL_CAPACITY;
    return list;
}

void list_free(List* list)
{
    free(list->data);
    free(list);
}

void list_add(List* list, void* item)
{
    if (list->size >= list->capacity)
    {
        list->capacity *= 2;
        list->data = realloc(list->data, sizeof(void*) * list->capacity);
    }
    list->data[list->size] = item;
    list->size++;
}

void list_set(List* list, int index, void* item)
{
    if (index < 0 || index >= list->size)
    {
        return;
    }
    list->data[index] = item;
}

void* list_get(List* list, int index)
{
    if (index < 0 || index >= list->size)
    {
        return NULL;
    }
    return list->data[index];
}

void list_remove(List* list, int index)
{
    if (index < 0 || index >= list->size)
    {
        return;
    }
    for (int i = index; i < list->size - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
}