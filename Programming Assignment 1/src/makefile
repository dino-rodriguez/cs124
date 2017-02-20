#
# Makefile
#
# Dino Rodriguez
#


### Constants

# Directories to search
VPATH =

# Header files
IDIR = ../include
_DEPS = graph.h heap.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# Binary executable and object files
BDIR = bin
ODIR = obj

# Libraries
LDIR = ../lib
LIBS = -lm

# Compilation
CC = g++
CFLAGS = -I $(IDIR)


### Settings

# Targets not associated with files
.PHONY: clean all


### Rules

# Build object files from c files depending on header
$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Clean files from object and source
clean:
	rm -f $(ODIR)/*.o $(BDIR)/*

# Make all
all: clean randmst graph_tests heap_tests

# Make individual files
randmst: $(ODIR)/randmst.o
	$(CC) -o $(BDIR)/$@ $^ $(CFLAGS) $(LIBS)

graph_tests: $(ODIR)/graph_tests.o
	$(CC) -o $(BDIR)/$@ $^ $(CFLAGS) $(LIBS)

heap_tests: $(ODIR)/heap_tests.o
	$(CC) -o $(BDIR)/$@ $^ $(CFLAGS) $(LIBS)
