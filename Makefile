# Name of the final executable
TARGET = student_management_system

# Compiler and its options
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Source files
SRCS = src/main.c src/student.c src/utils.c

# Main rule to compile the program
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to clean generated files
clean:
	rm -f $(TARGET)

.PHONY: clean
