#include "graph.h"
#include "graph_serializer.h"
#include <stdio.h>

int main(int argc, char * argv[]) {
    Graph g = graph_create();
    graph_add_vertex(g,1);
    graph_add_vertex(g,2);
    graph_add_vertex(g,3);
    graph_add_edge(g,1,2,0.5);
    graph_add_edge(g,2,3,0.64);
    graph_add_edge(g,1,3,0.1);
    graph_delete_vertex(g,1);
    graph_delete_vertex(g,2);
    graph_delete_vertex(g,3);
    convert_graph_to_json(g,"test.json");
    graph_delete(g);
    return 0;
}