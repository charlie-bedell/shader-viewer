# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -Iexternal
LDFLAGS = -Llibs -lraylib
PROGRAM_NAME = shader-viewer

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
EXTERNAL_DIR = external
LIB_DIR = libs

# Files
SRCS = $(wildcard $(SRC_DIR)/*.c)       # All .c files in src/
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS)) # Object files
TARGET = $(BUILD_DIR)/$(PROGRAM_NAME)          # Output binary

# Default Rule
all: $(TARGET)

# Link the Target Binary
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Compile Source Files into Object Files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean Build Artifacts
clean:
	rm -rf $(BUILD_DIR)

# PHONY Targets
.PHONY: all clean
