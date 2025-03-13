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
    



    fclose(f);
    return 0;
}