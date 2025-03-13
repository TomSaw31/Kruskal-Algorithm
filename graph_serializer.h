#ifndef __GRAPH_SERIALIZER_H__
#define __GRAPH_SERIALIZER_H__
#include "graph.h"

void convert_graph_to_json(Graph g, char * file_location);

void create_graph_from_json(Graph g, char * file_location);

#endif
