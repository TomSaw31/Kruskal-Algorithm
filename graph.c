#include "graph.h"
#include <stdio.h>
#include "list.h"
#include <assert.h>
#include <stdlib.h>



struct s_Edge {
	struct s_Vertex * n1;
	struct s_Vertex * n2;
	float weight;
};

struct s_Graph {
	unsigned int size;
	unsigned int edges_count;
	List vertices;
	struct s_Edge * edges;
};

typedef struct s_Edge * Edge;

// typedef void (*GraphEdgeMapOperator)(const void* elem, void* user_param);
int order(int x, int y);

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
	g->edges = NULL;
	return g;
}

Graph graph_add_vertex(Graph g, const int n){
	list_push_front(g->vertices,n);
	g->size++;
	list_sort(g->vertices,order);
	return g;
}

// Graph graph_add_edge(Graph g, const int n1, const int n2, const float w){
// 	return NULL;
// }

// TODO remove edges
void graph_delete(Graph g){
	list_delete(&g->vertices);
	g->vertices = NULL;
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

// Graph graph_get_edge(Graph g, const int n1, const int n2){
// 	return NULL;
// }

// float graph_get_edge_weight(Graph g, const int n1, const int n2){
// 	return -1;
// }

// List graph_get_neighbors(Graph g, const int n){
// 	return NULL;
// }

int graph_vertex_exists(Graph g, const int n) {
	return list_get_index(g->vertices,n) != -1;
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
int order(int x, int y) {
	return x < y;
}
