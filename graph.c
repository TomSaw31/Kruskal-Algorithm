#include "graph.h"
#include <stdlib.h>


typedef struct s_Vertex {
	struct s_Node * n1;
	struct s_Node * n2;
	float weight;
} Vertex;

typedef struct s_Node {
	int value;
} Node;

typedef struct s_VerticesTable {
	Vertex ** vertices;
	Vertex ** fast_vertices;
	unsigned int step;
} VerticesTable;

typedef struct tGraph {
	unsigned int size;
	unsigned int max_size;
	unsigned int vertices_count;
	VerticesTable vertices;
	Node * nodes;
}Graph;
/*----- Public Functions -----*/
typedef void (*GraphVertexMapOperator)(const void* elem, void* user_param);

Graph graph_create(unsigned int max_size){}

Graph graph_create_node(const int n){}

Graph graph_add_node(Graph g, const int n){}

Graph graph_add_vertex(Graph g, const int n1, const int n2, const float w){}

void graph_delete(Graph g){}

Graph graph_delete_node(Graph g, const int n){}

Graph graph_delete_vertex(Graph g, const int n1, const int n2){}

Graph graph_get_node(Graph g, const int n){}

float graph_get_edge_weight(Graph g, const int n1, const int n2){}

int * graph_get_neighbors(Graph g, const int n){}

int graph_node_exists(Graph g, const int n1){}

int graph_edge_exists(Graph g, const int n1, const int n2){}

int graph_empty(const Graph g){}

unsigned int graph_size(const Graph g){}

unsigned int graph_vertices_amount(const Graph g){}

int graph_overflow(const Graph g){}

void graph_map(const Graph g, GraphVertexMapOperator f, void* user_param){}

/*----- Private Functions -----*/

