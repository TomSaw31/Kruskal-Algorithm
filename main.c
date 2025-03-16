#include "graph.h"
#include "graph_serializer.h"
#include <stdio.h>

int main(void) {
    Graph g = graph_create();
    graph_add_vertex(g,1);
    graph_add_vertex(g,2);
    graph_add_vertex(g,3);
    convert_graph_to_json(g,"test.json");
    graph_delete(g);
    return 0;
}