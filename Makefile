CC=gcc
CFLAGS=-std=c99 -Wextra -Wall -pedantic
LDFLAGS=-lm

ECHO = @
ifeq ($(VERBOSE),1)
	ECHO=
endif

ifeq ($(DEBUG),yes)
	CFLAGS += -g
	LDFLAGS +=
else
	CFLAGS += -O3 -DNDEBUG
	LDFLAGS +=
endif

EXEC=main
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all:
ifeq ($(DEBUG),yes)
	@echo "Generating in debug mode"
else
	@echo "Generating in release mode"
endif
	@$(MAKE) $(EXEC)

$(EXEC): $(OBJ)
	$(ECHO)$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(ECHO)$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	$(ECHO)rm -rf *.o && rm -rf main

mrproper: clean
	$(ECHO)rm -rf $(EXEC) documentation/html

doc: rng.h skiplist.h
	$(ECHO)doxygen documentation/


list.o : list.h
graph.o : graph.h list.h
kruskal.o : kruskal.h graph.h
graph_serializer.o : graph_serializer.h graph.h
graphviz_generator.o : graphviz_generator.h graph.h
main.o : graph.h kruskal.h graphviz_generator.h graph_serializer.h
doc : graph.h list.h graph_serializer.h graphviz_generator.h kruskal.h
