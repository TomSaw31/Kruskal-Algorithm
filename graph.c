#include "graph.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


typdef struct s_Vertex {
	int value;
	Vertex * next;
	Vertex * prev;
} Vertex;

typedef struct s_Edge {
	struct s_Vertex * n1;
	struct s_Vertex * n2;
	float weight;
} Edge;

struct tGraph {
	unsigned int size;
	unsigned int max_size;
	unsigned int vertices_count;
	int * vertices;
	Edge ** edges;
} Graph;

typedef void (*GraphEdgeMapOperator)(const void* elem, void* user_param);

/*----- Header Functions -----*/

Graph graph_create(unsigned int max_size) {
	assert(max_size > 0);
	if((Graph * g = malloc(sizeof(Graph) + sizeof(int *) + sizeof(Edge *))) == !1) {
		fprintf(stderr, "Memory allocation error while creating a graph : graph_create\n");
		return 1;
	}
	g->size = 0;
	g->max_size = max_size;
	g->vertices_count = 0;
	g->vertices = g+1;
	g->edges = (g->vertices + 1);
	return g;
}

Graph graph_create_vertex(const int n){}

Graph graph_add_vertex(Graph g, const int n){}

Graph graph_add_edge(Graph g, const int n1, const int n2, const float w){}

void graph_delete(Graph g){}

Graph graph_delete_vertex(Graph g, const int n){}

Graph graph_delete_edge(Graph g, const int n1, const int n2){}

Graph graph_get_vertex(Graph g, const int n) {
	if(graph_empty(g)) {
		return NULL;
	}
	Vertex * v;
	for(v = g->vertices[0]; v->value != n && v->value < (g->size) - 1; v = v->next);
	return v;
}


// IMPROVE LATER
Graph graph_get_edge(Graph g, const int n1, const int n2){
	if(!g->vertices_count) {
		return NULL;
	}
	Edge * e;
	for(int i = 0, e = g->vertices[i]; e->n1 <= n1; e = e->vertices[i++]) {
		if(e->n1 == n1 && e->n2 == n2) {
			return e;
		}
	}
	return NULL;
}

float graph_get_edge_weight(Graph g, const int n1, const int n2){}

int * graph_get_neighbors(Graph g, const int n){}

int graph_vertex_exists(Graph g, const int n) {
	return graph_get_vertex(g, n);
}

int graph_edge_exists(Graph g, const int n1, const int n2) {
	return graph_get_edge(g, n1, n2);
}

int graph_empty(const Graph g){
	return !g->size;
}

unsigned int graph_size(const Graph g){
	return g->size;
}

unsigned int graph_vertices_amount(const Graph g){
	return g->vertices_count;
}

int graph_overflow(const Graph g){
	return g->size == g->max_size;
}

void graph_map(const Graph g, GraphEdgeMapOperator f, void * user_param){

}

/*----- Private Functions -----*/

