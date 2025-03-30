// dot -Tpng graph.dot -o graph.png
#include "graph.h"
#include "graphviz_generator.h"
#include <stdlib.h>
#include <stdio.h>

void * _write_egdes(void * e, void * f);

int convert_graph_to_dot(Graph g, char * file_location) {
    FILE * f = fopen(file_location, "w+");
    if(f == NULL) {
        fprintf(stderr,"Error while opening the file : %s in convert_graph_to_json\n",file_location);
        return -1;
    }
    fprintf(f,"graph G {\n");
    List l = graph_get_edges(g);
    list_for_each(l,_write_egdes,f);
    fprintf(f,"}\n");
    return 0;
}

// TODO
int convert_dot_to_graphviz(char * dot_file, char * png_file) {
    return 0;
}

void * _write_egdes(void * e, void * f) {
    Edge edge = (Edge)e;
    FILE * file = (FILE *)f;
    fprintf(f,"\t%d -- %d [label=\"%g\"];\n",graph_get_edge_start(edge),graph_get_edge_end(edge),graph_get_edge_weight(edge));
}