# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Source files
SOURCES = example1.c example2.c example3.c example4.c example5.c

# Object files
OBJECTS = example1.o example2.o example3.o example4.o example5.o

# Default target
all: $(OBJECTS)

# Targets for each file
example1.o: example1.c
	$(CC) $(CFLAGS) -o $@ $<

example2.o: example2.c
	$(CC) $(CFLAGS) -o $@ $<

example3.o: example3.c
	$(CC) $(CFLAGS) -o $@ $<

example4.o: example4.c
	$(CC) $(CFLAGS) -o $@ $<

example5.o: example5.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean target to remove compiled files
clean:
	rm -f $(OBJECTS)
