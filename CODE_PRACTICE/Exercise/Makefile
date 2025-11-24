# Makefile for C Project
# Compiler and flags
CC = clang
CFLAGS = -Wall -Wextra -std=c11 -g -fcolor-diagnostics -fansi-escape-codes
LDFLAGS = 

# Directories
SRCDIR = src
BUILDDIR = build
OBJDIR = $(BUILDDIR)/obj

# Source files
SOURCES = $(SRCDIR)/main.c
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
TARGET = $(BUILDDIR)/main

# Default target
all: $(TARGET)

# Create build directories
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Build the executable
$(TARGET): $(OBJECTS) | $(BUILDDIR)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)
	@echo "Build complete! Executable: $(TARGET)"

# Compile source files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	@echo "Running program..."
	@echo "test input" | $(TARGET)

# Clean build files
clean:
	rm -rf $(BUILDDIR)
	@echo "Cleaned build files"
	
# Debug build
debug: CFLAGS += -DDEBUG -O0
debug: $(TARGET)

# Release build
release: CFLAGS += -O2 -DNDEBUG
release: clean $(TARGET)

# Show help
help:
	@echo "Available targets:"
	@echo "  all      - Build the project (default)"
	@echo "  run      - Build and run the program"
	@echo "  clean    - Remove build files"
	@echo "  clean-all- Remove all generated files"
	@echo "  debug    - Build with debug flags"
	@echo "  release  - Build optimized release"
	@echo "  help     - Show this help"

# Phony targets
.PHONY: all run clean clean-all debug release help

# Include dependency files if they exist
-include $(OBJECTS:.o=.d)
