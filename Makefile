# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -O2

# Directories
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
TEST_DIR := test

# Source and object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Test source and object files
TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS := $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(TEST_SRCS))

# Target executable
TARGET := $(BIN_DIR)/ndsipe
TEST_TARGET := $(BIN_DIR)/test

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TEST_TARGET)
	$(TEST_TARGET)

$(TEST_TARGET): $(OBJS) $(TEST_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ -lgtest -lgtest_main

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BUILD_DIR) $(BIN_DIR)
