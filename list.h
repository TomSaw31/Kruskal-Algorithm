#ifndef __LIST_H__
#define __LIST_H__

typedef struct s_List * List;

typedef void *(*ListFunctor)(void *, void*);

typedef int(*OrderFunctor)(void *, void *);

typedef int(*IndexAccess)(void *);

List list_create(void);

void list_delete(List * l);

List list_push_front(List l, void * v);

List list_push_back(List l, void * v);

List list_insert_at(List l, int p, void * v);

List list_pop_front(List l);

List list_pop_back(List l);

List list_remove_at(List l, int p);

void * list_front(const List l);

void * list_back(const List l);

void * list_at(const List l, int p);

int list_is_empty(const List l);

int list_size(const List l);

List list_map(List l, ListFunctor f, void* environment);

List list_sort(List l, OrderFunctor f);

int list_get_index(const List l, int * v, IndexAccess f);

#endif

