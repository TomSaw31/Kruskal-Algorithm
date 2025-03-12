#ifndef __LIST_H__
#define __LIST_H__

typedef struct s_List * List;

typedef int(*ListFunctor)(int, void*);

typedef int(*OrderFunctor)(int, int);

List list_create(void);

void list_delete(List * l);

List list_push_front(List l, int v);

List list_push_back(List l, int v);

List list_insert_at(List l, int p, int v);

List list_pop_front(List l);

List list_pop_back(List l);

List list_remove_at(List l, int p);

int list_front(const List l);

int list_back(const List l);

int list_at(const List l, int p);

int list_is_empty(const List l);

int list_size(const List l);

List list_map(List l, ListFunctor f, void* environment);

List list_sort(List l, OrderFunctor f);

#endif

