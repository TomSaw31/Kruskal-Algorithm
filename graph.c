#include "graph.h"
#include <stdlib.h>


typedef struct s_Edge {
	struct s_Vertex * n1;
	struct s_Vertex * n2;
	float weight;
} Edge;

typedef struct tGraph {
	unsigned int size;
	unsigned int max_size;
	unsigned int vertices_count;
	int * vertices;
	Edge  ** edges;
}Graph;

/*----- Public Functions -----*/
typedef void (*GraphEdgeMapOperator)(const void* elem, void* user_param);

Graph graph_create(unsigned int max_size){}

Graph graph_create_vertex(const int n){}

Graph graph_add_vertex(Graph g, const int n){}

Graph graph_add_edge(Graph g, const int n1, const int n2, const float w){}

void graph_delete(Graph g){}

Graph graph_delete_vertex(Graph g, const int n){}

Graph graph_delete_edge(Graph g, const int n1, const int n2){}

Graph graph_get_vertex(Graph g, const int n){}

Graph graph_get_vertex(Graph g, const int n1, const int n2){}

float graph_get_edge_weight(Graph g, const int n1, const int n2){}

int * graph_get_neighbors(Graph g, const int n){}

int graph_vertex_exists(Graph g, const int n1){}

int graph_edge_exists(Graph g, const int n1, const int n2){}

int graph_empty(const Graph g){}

unsigned int graph_size(const Graph g){}

unsigned int graph_vertices_amount(const Graph g){}

int graph_overflow(const Graph g){}

void graph_map(const Graph g, GraphEdgeMapOperator f, void* user_param){}

/*----- Private Functions -----*/

