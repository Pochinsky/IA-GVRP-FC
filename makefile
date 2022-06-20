# Define compiler
CC = g++
# Define compiler flags:
CFLAGS = -c -Wall
# Define code files
CODE1 = main.cpp
CODE2 = src/extract/extract.cpp
# Define object files
OBJ1 = main.o
OBJ2 = extract.o
# Define executable
EXE = main.out
# To clean
RM = rm -f

# compile program
all: extract main executable

# compile executable
executable: $(OBJ1) $(OBJ2)
	$(CC) $(OBJ1) $(OBJ2) -o $(EXE)

# compile main
main: $(CODE1)
	$(CC) $(CFLAGS) $(CODE1)

# compile extract module
extract: $(CODE2)
	$(CC) $(CFLAGS) $(CODE2)

# run executable
run:
	./$(EXE)

# clean .o files
clean:
	$(RM) $(OBJ1) $(OBJ2)