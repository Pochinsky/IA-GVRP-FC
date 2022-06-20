# define compiler
CC = g++

# define compiler flags:
CFLAGS = -g -Wall -o

# define the main build target
TARGET = main

RM = rm -f

# compile target
all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) $(TARGET).out $(TARGET).cpp

# execute target
run:
	./$(TARGET).out

# clean .o files
clean:
	$(RM) $(TARGET).out