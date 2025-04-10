#include "graph.h"
#include "graph_serializer.h"
#include <stdlib.h>
#include <stdio.h>

int convert_graph_to_json(Graph g, char * file_location) {
    FILE * f = fopen(file_location, "w+");
    if(f == NULL) {
        fprintf(stderr,"Error while opening the file : %s in convert_graph_to_json\n",file_location);
        return -1;
    }

    List vertices = graph_get_vertices(g);
    int vertices_count = graph_size(g);
    List edges = graph_get_edges(g);
    int edges_count = graph_edges_amount(g);
    int * i_copy;

    fprintf(f,"{\n\t\"vertices\": [\n");
    for(int i = 0; i < vertices_count - 1; i++) {
        i_copy = (int *)list_at(vertices,i);
        fprintf(f, "\t\t{ \"vertex\": %d },\n",*i_copy);
    }
    if(vertices_count - 1 >= 0) {
        i_copy = (int *)list_at(vertices,vertices_count - 1);
        fprintf(f, "\t\t{ \"vertex\": %d }\n",*i_copy);
    }
    fprintf(f,"\t],\n");

    fprintf(f,"\t\"edges\": [\n");

    Edge e_copy;
    for(int i = 0; i < edges_count - 1; i++) {
        e_copy = (Edge)list_at(edges,i);
        fprintf(f, "\t\t{ \"from\": %d, \"to\": %d, \"weight\": %f },\n",graph_get_edge_start(e_copy),graph_get_edge_end(e_copy), graph_get_edge_weight(e_copy));
    }
    if(edges_count - 1 >= 0) {
        e_copy = (Edge)list_at(edges,edges_count - 1);
        fprintf(f, "\t\t{ \"from\": %d, \"to\": %d, \"weight\": %f }\n",graph_get_edge_start(e_copy),graph_get_edge_end(e_copy), graph_get_edge_weight(e_copy));
    }
    fprintf(f,"\t]\n");
    fprintf(f,"}\n");

    fclose(f);
    return 0;
}


int create_graph_from_json(Graph g, char * file_location) {
    FILE * f = fopen(file_location, "r+");
    if(f == NULL) {
        fprintf(stderr,"Error while opening the file : %s in create_graph_from_json\n",file_location);
        return -1;
    }
    List vertices = list_create();
    int vertices_count = 0;
    List edges = list_create();
    int edges_count = 0;
    // TODO





    return 0;
}