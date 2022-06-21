# Define compiler
CC = g++
# Define compiler flags:
CFLAGS = -c -Wall
# Define code files
CODE1 = main.cpp
CODE2 = src/instance/instance.cpp
CODE3 = src/node/node.cpp
CODE4 = src/list/list.cpp
# Define object files
OBJ1 = main.o
OBJ2 = instance.o
OBJ3 = node.o
OBJ4 = list.o
ALLOBJ = *.o
# Define executable
EXE = main.out
# To clean
RM = rm -f

# compile program
all: instance node list main executable

# compile executable
executable: $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4)
	$(CC) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) -o $(EXE)

# compile main
main: $(CODE1)
	$(CC) $(CFLAGS) $(CODE1)

# compile instance module
instance: $(CODE2)
	$(CC) $(CFLAGS) $(CODE2)

# compile node module
node: $(CODE3)
	$(CC) $(CFLAGS) $(CODE3)

# compile list module
list: $(CODE4)
	$(CC) $(CFLAGS) $(CODE4)

# run executable
run:
	./$(EXE)

# clean .o files
clean:
	$(RM) $(ALLOBJ)