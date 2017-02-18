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
_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# Binary executable and object files
BDIR = bin
ODIR = obj

# Libraries
LDIR = ../lib
LIBS = -lm

# Compilation
CC = gcc
CFLAGS = -I $(IDIR)


### Settings

# Targets not associated with files
.PHONY: clean all


### Rules

# Build object files from c files depending on header
$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Clean files from object and source
clean: rm -f $(ODIR)/*.o $(BDIR)/*

# Make all
all: randmst

# Make individual files
randmst: $(ODIR)/randmst.o
	$(CC) -o $(BDIR)/$@ $^ $(CFLAGS) $(LIBS)
