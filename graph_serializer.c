#include "graph.h"
#include "graph_serializer.h"
#include <stdlib.h>
#include <stdio.h>

int convert_graph_to_json(Graph g, char * file_location) {
    FILE * f = fopen(file_location, "r+");
    if(f == NULL) {
        fprintf(stderr,"Error while opening the file : %s in convert_graph_to_json\n",file_location);
        return -1;
    }
    List vertices = graph_get_vertices(g);
    unsigned int vertices_count = graph_size(g);

    fprintf(f,"{\n\t\"vertices\": [\n");
    for(unsigned int i = 0; i < vertices_count - 1; i++) {
        fprintf(f, "\t\t{ \"vertex\": %d },\n",list_at(vertices,i));
    }
    fprintf(f, "\t\t{ \"vertex\": %d }\n",list_at(vertices,vertices_count - 1));
    fprintf(f,"\t]\n");
    fprintf(f,"}\n");

    fclose(f);
    return 0;
}