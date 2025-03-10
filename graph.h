#ifndef __GRAPH_H__
#define __GRAPH_H__

typedef struct Graph * tGraph;

Graph graph_create(unsigned int max_size);

Graph graph_create_node(const int n);

Graph graph_add_node(Graph g, const int n);

Graph graph_add_vertex(Graph g, const int n1, const int n2, const float w);

void graph_delete(Graph g);

Graph graph_delete_node(Graph g, const int n);

Graph graph_delete_vertex(Graph g, const int n1, const int n2);

Graph graph_get_node(Graph g, const int n);

float graph_get_edge_weight(Graph g, const int n1, const int n2);

int * graph_get_neighbors(Graph g, const int n);

int graph_node_exists(Graph g, const int n1);

int graph_vertex_exists(Graph g, const int n1, const int n2);

int graph_empty(const Graph g);

unsigned int graph_size(const Graph g);

unsigned int graph_vertices_amount(const Graph g);

int graph_overflow(const Graph g);

typedef void (*GraphVertexMapOperator)(const void* elem, void* user_param);

void graph_map(const Graph g, GraphVertexMapOperator f, void* user_param);

#endif

