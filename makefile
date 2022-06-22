# Define compiler
CC = g++
# Define compiler flags:
CFLAGS = -c -Wall
# Define code files
CODE1 = main.cpp
CODE2 = src/instance/instance.cpp
CODE3 = src/node/node.cpp
CODE4 = src/nodes/nodes.cpp
CODE5 = src/filter/filter.cpp
CODE6 = src/fc/fc.cpp
# Define object files
OBJ1 = main.o
OBJ2 = instance.o
OBJ3 = node.o
OBJ4 = nodes.o
OBJ5 = filter.o
OBJ6 = fc.o
ALLOBJ = $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6)
# Define executable
EXE = main.out
# To clean
RM = rm -f

# compile program
all: instance node nodes filter fc main executable

# compile executable
executable: $(ALLOBJ)
	$(CC) $(ALLOBJ) -o $(EXE)

# compile main
main: $(CODE1)
	$(CC) $(CFLAGS) $(CODE1)

# compile instance module
instance: $(CODE2)
	$(CC) $(CFLAGS) $(CODE2)

# compile node module
node: $(CODE3)
	$(CC) $(CFLAGS) $(CODE3)

# compile nodes module
nodes: $(CODE4)
	$(CC) $(CFLAGS) $(CODE4)

# compile filter module
filter: $(CODE6)
	$(CC) $(CFLAGS) $(CODE5)

# compile fc module
fc: $(CODE6)
	$(CC) $(CFLAGS) $(CODE6)

# run executable
run:
	./$(EXE)

# clean .o files
clean:
	$(RM) $(ALLOBJ)