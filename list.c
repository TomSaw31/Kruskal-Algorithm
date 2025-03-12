#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct s_LinkedNode {
	int value;
	struct s_LinkedNode * prev;
	struct s_LinkedNode * next;
} LinkedNode;

struct s_List {
	int size;
    LinkedNode * sll;
};

typedef struct s_Sublist {
	LinkedNode * head;
	LinkedNode * tail;
} Sublist;

List list_create() {
	List l = malloc(sizeof(List) + sizeof(LinkedNode));
    if(l == NULL) {
		fprintf(stderr, "Memory allocation error while creating a list : list_create\n");
		return NULL;
	}
	l->sll = (LinkedNode *)(l + 1);
	l->sll->next = l->sll->prev = l->sll;
	l->size = 0;
	return l;
}

void list_delete(List * l) {
	LinkedNode * n = (*l)->sll->next;
	LinkedNode * tmp;
	while (n != (*l)->sll) {
		tmp = n;
		n = n->next;
		free(tmp);
	}
	free(*l);
	(*l) = NULL;
}

List list_push_front(List l, int v) {
	LinkedNode * n = malloc(sizeof(LinkedNode));
    if(n == NULL) {
		fprintf(stderr, "Memory allocation error while creating a node : list_push_front\n");
		return NULL;
	}
	n->value = v;
	n->prev = l->sll;
	n->next = l->sll->next;
	l->sll->next = n;
	n->next->prev = n;
	l->size++;
	return l;
}

List list_push_back(List l, int v) {
	LinkedNode * n = malloc(sizeof(LinkedNode));
    if(n == NULL) {
		fprintf(stderr, "Memory allocation error while creating a node : list_push_back\n");
		return NULL;
	}
	n->value = v;
	n->next = l->sll;
	n->prev = l->sll->prev;
	n->prev->next = n;
	n->next->prev = n;
	l->size++;
	return l;
}

List list_insert_at(List l, int p, int v) {
    if(p < 0 || p > l->size) {
        fprintf(stderr, "Precondition : p index must be between 0 and the size of the list (inclusive) : list_insert_at\n");
		return NULL;
    }
	LinkedNode * n = l->sll->next;
	while(p--) n = n->next;
	LinkedNode * new = malloc(sizeof(LinkedNode));
    if(new == NULL) {
		fprintf(stderr, "Memory allocation error while creating a node : list_insert_at\n");
		return NULL;
	}
	new->value = v;
	n->prev->next = new;
	new->prev = n->prev;
	n->prev = new;
	new->next = n;
	l->size++;
	return l;
}

List list_pop_front(List l) {
    if(list_is_empty(l)) {
        fprintf(stderr, "Precondition : List must not be empty : list_pop_front\n");
		return NULL;
    }
	LinkedNode * n = l->sll->next;
	l->sll->next = n->next;
	n->next->prev = l->sll;
	free(n);
	l->size--;
	return l;
}

List list_pop_back(List l){
    if(list_is_empty(l)) {
        fprintf(stderr, "Precondition : List must not be empty : list_pop_back\n");
		return NULL;
    }
	LinkedNode * n = l->sll->prev;
	l->sll->prev = n->prev;
	n->prev->next = l->sll;
	free(n);
	l->size--;
	return l;
}

List list_remove_at(List l, int p) {
    if(0 > p || p >= l->size) {
        fprintf(stderr, "Precondition : p index must be between 0 (inclusive) and the size of the list (exclusive) : list_remove_at\n");
		return NULL;
    }
	LinkedNode * n = l->sll->next;
	while(p--) n = n->next;
	n->next->prev = n->prev;
	n->prev->next = n->next;
	l->size--;
	free(n);
	return l;
}

List list_map(List l, ListFunctor f, void * environment) {
    for (LinkedNode * n = l->sll->next; n != l->sll; n = n->next)
        n->value = f(n->value, environment);
    return l;
}

int list_at(const List l, int p) {
    if(0 > p || p >= l->size) {
        fprintf(stderr, "Precondition : p index must be between 0 (inclusive) and the size of the list (exclusive) : list_at\n");
		return NULL;
    }
	LinkedNode * n = l->sll->next;
	while(p--) n = n->next;
	return n->value;
}

int list_front(const List l) {
    if(list_is_empty(l)) {
        fprintf(stderr, "Precondition : List must not be empty : list_front\n");
		return NULL;
    }
	return l->sll->next->value;
}

int list_back(const List l) {
    if(list_is_empty(l)) {
        fprintf(stderr, "Precondition : List must not be empty : list_back\n");
		return NULL;
    }
	return l->sll->prev->value;
}

int list_is_empty(const List l) {
	return l->size == 0;
}

int list_size(const List l) {
	return l->size;
}

Sublist list_split(Sublist l) {
	LinkedNode * n1 = l.head;
	LinkedNode * n2 = l.head;
	while (n2->next != NULL && n2->next->next != NULL) {
		n2 = n2->next->next;
		n1 = n1->next;
	}
	l.head = n1;
	l.tail = n1->next;
	l.head->next = NULL;
	l.tail->prev = NULL;
	return l;
}

Sublist list_merge(Sublist leftlist, Sublist rightlist, OrderFunctor f) {
	if (!leftlist.head) return rightlist;
	if (!rightlist.head) return leftlist;
	LinkedNode * nl = leftlist.head;
	LinkedNode * nr = rightlist.head;
	Sublist l;
	l.head = NULL;
	l.tail = NULL;
	if (f(nl->value,nr->value)) {
		l.head = nl;
		nl->prev = NULL;
		nl = nl->next;
	} else {
		l.head = nr;
		nr->prev = NULL;
		nr = nr->next;
	}
	LinkedNode * n = l.head;
	while(nl && nr) {
		if(f(nl->value,nr->value)) {
			nl->prev = n;
			n->next = nl;
			nl = nl->next;
		} else {
			nr->prev = n;
			n->next = nr;
			nr = nr->next;
		}
		n = n->next;
	}
	LinkedNode * n_remain = (nl ? nl : nr);
	while(n_remain) {
		n_remain->prev = n;
		n->next = n_remain;
		n_remain = n_remain->next;
		n = n->next;
	}
	l.tail = n;
	return l;
}

Sublist list_mergesort(Sublist l, OrderFunctor f) {
	if (l.head == l.tail)
		return l;
	Sublist sublist = list_split(l);
	Sublist leftlist = {l.head, sublist.head};
	Sublist rightlist = {sublist.tail, l.tail};
	leftlist.head->prev = NULL;
	leftlist.tail->next = NULL;
	rightlist.head->prev = NULL;
	rightlist.tail->next = NULL;
	return list_merge(list_mergesort(leftlist,f),list_mergesort(rightlist,f),f);
}

List list_sort(List l, OrderFunctor f) {
	Sublist sub_list = {l->sll->next, l->sll->prev};
	sub_list.head->prev = NULL;
	sub_list.tail->next = NULL;
	sub_list = list_mergesort(sub_list,f);
	sub_list.head->prev = l->sll;
	sub_list.tail->next = l->sll;
	l->sll->next = sub_list.head;
	l->sll->prev = sub_list.tail;
	return l;
}
