CFLAGS = -O -g -Wall
CC=gcc
CXX=g++
RM=rm -f

SDIR = src


all: mtree

mtree: main.o merkle_tree.o
	$(CXX) $(CFLAGS) -o mtree main.o merkle_tree.o $(OBJ) $(LDLIBS)

%.o: src/%.cpp
	${CXX} ${CFLAGS} -c $< -o $@

clean:
	$(RM) *.o

distclean: clean
	$(RM) mtree