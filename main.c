#include "graph.h"
#include "graph_serializer.h"
#include "graphviz_generator.h"
#include <stdio.h>

#define FILE_NAME "test.json"

int main(void) {
    Graph g = graph_create();
    graph_add_vertex(g,1);
    graph_add_vertex(g,2);
    graph_add_vertex(g,3);
    graph_add_edge(g,1,2,0.5);
    graph_add_edge(g,2,3,0.64);
    graph_add_edge(g,1,3,0.1);
    graph_add_edge(g,3,2,0.1);
    convert_graph_to_dot(g,"test.dot");
    convert_dot_to_graphviz("test.dot","test.png");
    convert_graph_to_json(g,FILE_NAME);
    graph_delete(g);
    return 0;
}