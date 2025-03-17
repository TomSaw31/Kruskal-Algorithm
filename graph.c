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
	unsigned int size;
	unsigned int edges_count;
	List vertices;
	List edges;
};

// typedef void (*GraphEdgeMapOperator)(const void* elem, void* user_param);
int int_functor_order(void * x, void * y);
int edge_functor_order(void * x, void * y);
/*----- Header Functions -----*/

Graph graph_create() {
	Graph g = malloc(sizeof(struct s_Graph));
	if(g == NULL) {
		fprintf(stderr, "Memory allocation error while creating a graph in graph_create\n");
		return NULL;
	}
	g->size = 0;
	g->edges_count = 0;
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
	g->size++;
	list_sort(g->vertices,int_functor_order);
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
	g->edges_count++;
	list_sort(g->edges,edge_functor_order);
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

// Graph graph_delete_vertex(Graph g, const int n){
// 	return NULL;
// }

// Graph graph_delete_edge(Graph g, const int n1, const int n2){
// 	return NULL;
// }

List graph_get_vertices(Graph g) {
	return g->vertices;
}

List graph_get_edges(Graph g) {
	return g->edges;
}

int graph_get_edges_start(const Edge e) {
	return e->n1;
}

int graph_get_edges_end(const Edge e) {
	return e->n2;
}

float graph_get_edge_weight(const Edge e) {
	return e->weight;
}

// List graph_get_neighbors(Graph g, const int n){
// 	return NULL;
// }

int graph_vertex_exists(Graph g, const int n) {
	int * n_copy = malloc(sizeof(int));
	*n_copy = (int)n;
	int result = list_get_index(g->vertices,n_copy) != -1;
	free(n_copy);
	return result;
}

// int graph_edge_exists(Graph g, const int n1, const int n2) {
// 	return graph_get_edge(g, n1, n2);
// }

int graph_empty(const Graph g){
	return !g->size;
}

unsigned int graph_size(const Graph g){
	return g->size;
}

unsigned int graph_edges_amount(const Graph g){
	return g->edges_count;
}

// void graph_map(const Graph g, GraphEdgeMapOperator f, void * user_param){

// }

float graph_density(const Graph g) {
	return g->edges_count/(g->size * g->size);
}

/*----- Private Functions -----*/
int int_functor_order(void * x, void * y) {
	int * x_c = (int *)x;
	int * y_c = (int *)y;
	return *x_c < *y_c;
}

int edge_functor_order(void * x, void * y) {
	Edge x_c = (Edge)x;
	Edge y_c = (Edge)y;
	return x_c->n1 == y_c->n1 ? x_c->n2 < y_c->n2 : x_c->n1 < y_c->n1;
}
