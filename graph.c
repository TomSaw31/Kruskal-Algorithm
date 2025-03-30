#include "graph.h"
#include <stdio.h>
#include "list.h"
#include <assert.h>
#include <stdlib.h>



struct s_Edge {
	int n1;
	int n2;
	float weight;
};

struct s_Graph {
	List vertices;
	List edges;
};

// typedef void (*GraphEdgeMapOperator)(const void* elem, void* user_param);
int _int_functor_order(void * x, void * y);
int _edge_functor_order(void * x, void * y);
int _index_accessor_vertex(void * e);
int _search_accessor_head(void * e, void * args);
int _search_accessor_tail(void * e, void * args);

void *print_edge(void *, void *);

/*----- Header Functions -----*/

Graph graph_create() {
	Graph g = malloc(sizeof(struct s_Graph));
	if(g == NULL) {
		fprintf(stderr, "Memory allocation error while creating a graph in graph_create\n");
		return NULL;
	}
	g->vertices = list_create();
	g->edges = list_create();
	return g;
}

Graph graph_add_vertex(Graph g, const int n){
	int * n_copy = malloc(sizeof(int));
	if(n_copy == NULL) {
		fprintf(stderr, "Memory allocation error while copying value in graph_add_vertex\n");
		return NULL;
	}
	*n_copy = n;
	list_push_back(g->vertices,n_copy);
	list_sort(g->vertices,_int_functor_order);
	return g;
}

Graph graph_add_edge(Graph g, const int n1, const int n2, const float w) {
	Edge e = malloc(sizeof(struct s_Edge));
	if(e == NULL) {
		fprintf(stderr, "Memory allocation error while creating an edge in graph_add_edge\n");
		return NULL;
	}
	e->n1 = n1;
	e->n2 = n2;
	e->weight = w;
	list_push_back(g->edges,e);
	list_sort(g->edges,_edge_functor_order);
	return g;
}

void graph_delete(Graph g){
	list_delete(&g->vertices);
	g->vertices = NULL;
	list_delete(&g->edges);
	g->edges = NULL;
	free(g);
	g = NULL;
}

Graph graph_delete_vertex(Graph g, const int n) {
	int n_c = (int)n;
	int i = list_get_index(g->vertices,&n_c,_index_accessor_vertex);
	if(i == -1) {
		fprintf(stderr, "Error : Trying to delete a non existent vertex in graph_delete_vertex\n");
		return g;
	}
	list_remove_at(g->vertices,i);
	return g;
}

// Graph graph_delete_edge(Graph g, const int n1, const int n2){
// 	return NULL;
// }

List graph_get_vertices(Graph g) {
	return g->vertices;
}

List graph_get_edges(Graph g) {
	return g->edges;
}

int graph_get_edge_start(const Edge e) {
	return e->n1;
}

int graph_get_edge_end(const Edge e) {
	return e->n2;
}

float graph_get_edge_weight(const Edge e) {
	return e->weight;
}

// TODO
List graph_get_neighbors(Graph g, const int n) {
	List neighbors = list_search(g->edges,(void *)&n,_search_accessor_head);
	list_map(g->edges,print_edge,NULL);
	printf("LENGTH : %d\n",list_size(neighbors));
	return neighbors;
}

int graph_vertex_exists(Graph g, const int n) {
	int * n_copy = malloc(sizeof(int));
	*n_copy = (int)n;
	int result = list_get_index(g->vertices,n_copy,_index_accessor_vertex) != -1;
	free(n_copy);
	return result;
}

// int graph_edge_exists(Graph g, const int n1, const int n2) {
// 	return graph_get_edge(g, n1, n2);
// }

int graph_empty(const Graph g){
	return !list_size(g->vertices);
}

unsigned int graph_size(const Graph g){
	return list_size(g->vertices);
}

unsigned int graph_edges_amount(const Graph g){
	return list_size(g->edges);
}

// void graph_map(const Graph g, GraphEdgeMapOperator f, void * user_param){

// }

float graph_density(const Graph g) {
	int s = list_size(g->vertices);
	return list_size(g->edges)/(s * s);
}

/*----- Private Functions -----*/
int _int_functor_order(void * x, void * y) {
	int * x_c = (int *)x;
	int * y_c = (int *)y;
	return *x_c < *y_c;
}

int _edge_functor_order(void * x, void * y) {
	Edge x_c = (Edge)x;
	Edge y_c = (Edge)y;
	return x_c->n1 == y_c->n1 ? x_c->n2 < y_c->n2 : x_c->n1 < y_c->n1;
}

int _index_accessor_vertex(void * v) {
	int * vertex = (int *)v;
	return *vertex;
}

int _search_accessor_head(void * v, void * argv) {
	Edge e = (Edge)v;
	int * value = (int *)argv;
	return graph_get_edge_start(e) == *value;
}

int _search_accessor_tail(void * v, void * argv) {
	Edge e = (Edge)v;
	int * value = (int *)argv;
	return graph_get_edge_end(e) == *value;
}

// DEBUG
void * print_edge(void * v, void * argv) {
	Edge e = (Edge)v;
	printf("%d <-----> %d\n",graph_get_edge_start(e),graph_get_edge_end(e));
	return NULL;
}
