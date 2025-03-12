#include "graph.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


struct s_Vertex {
	int value;
	struct s_Vertex * next;
	struct s_Vertex * prev;
};
struct s_Edge {
	struct s_Vertex * n1;
	struct s_Vertex * n2;
	float weight;
};

struct s_Graph {
	unsigned int size;
	unsigned int vertices_count;
	struct s_Vertex ** vertices;
	Edge * edges;
};

typedef struct s_Vertex * Vertex;
typedef struct s_Edge * Edge;

typedef void (*GraphEdgeMapOperator)(const void* elem, void* user_param);

/*----- Header Functions -----*/

Graph graph_create(unsigned int max_size) {
	assert(max_size > 0);
	Graph g = malloc(sizeof(Graph));
	if(g == NULL) {
		fprintf(stderr, "Memory allocation error while creating a graph : graph_create\n");
		return 1;
	}
	g->size = 0;
	g->vertices_count = 0;
	g->vertices = NULL;
	g->edges = NULL;
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
	Vertex v;
	for(v = g->vertices[0]; v->value != n && v->value < (g->size) - 1; v = v->next);
	return v->value == n ? v : NULL;
}


// IMPROVE LATER
Graph graph_get_edge(Graph g, const int n1, const int n2){
	if(!g->vertices_count) {
		return NULL;
	}
	for(int i = 0; g->vertices[i] <= n1; i++) {
		if(g->vertices[i] == n1 && g->vertices[i] == n2) {
			return g->vertices[i];
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

void graph_map(const Graph g, GraphEdgeMapOperator f, void * user_param){

}

float graph_density(const Graph g) {
	return g->vertices_count/(g->size * g->size);
}

/*----- Private Functions -----*/

