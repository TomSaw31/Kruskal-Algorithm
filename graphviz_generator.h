#ifndef __GRAPHVIZ_GENERATOR_H__
#define __GRAPHVIZ_GENERATOR_H__
#include "graph.h"

int convert_graph_to_dot(Graph g, char * file_location);

int convert_dot_to_graphviz(char * dot_file, char * png_file);

#endif
