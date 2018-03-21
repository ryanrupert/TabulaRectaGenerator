#compiler
CC := g++
#dirs
BINDIR := bin
INCDIR := inc
LIBDIR := lib
OBJDIR := obj
SRCDIR := src
#file lists
LIB := $(shell find $(LIBDIR) -type f -name *.cpp)
#LIB := #list library files here
SRC := Source.cpp
OBJ := $(SRC:.cpp=.o)
#dir/file
OBJPATH := $(patsubst %.o,obj/%.o,$(OBJ))
LIBPATH := $(patsubst %.o,obj/%.o,$(LIB))
FINAL := $(OBJPATH) $(LIBPATH)
# https://stackoverflow.com/a/12368262/8011746
GIT_VERSION := $(shell git describe --abbrev=4 --dirty --always --tags | cut -c2-)
#flags
CFLAG := -c -std=c++11 -DVERSION=\"$(GIT_VERSION)\"
LFLAG :=

all: $(OBJPATH)
	$(CC) $(LFLAG) $(FINAL) -o $(BINDIR)/a

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAG) -I$(INCDIR) -I$(LIBDIR) $< -o $@

$(LIBDIR)/%.o: $(LIBDIR)/%.cpp
	$(CC) $(CFLAG) -I$(LIBDIR) $< -o $@

debug: CFLAG += -g
debug: all

.PHONY: clean

clean:
	rm obj/*.o
