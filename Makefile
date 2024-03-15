CC := g++
CXXFLAGS = -std=c++20
BUILD_DIR := ./build
SRC_DIR := ./src
INCLUDE_DIR := ./include
OBJS := $(BUILD_DIR)/test.o
SRCS := $(SRC_DIR)/test.cpp

all: $(BUILD_DIR) test

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

test: $(BUILD_DIR) $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o test -lgtest -lpthread

run_test: test
	./test

clean:
	rm -rf $(BUILD_DIR)
	rm test