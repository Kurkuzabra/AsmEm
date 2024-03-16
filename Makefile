CC := g++
CXXFLAGS = -std=c++20
BUILD_DIR := ./build
SRC_DIR := ./src
INCLUDE_DIR := ./include
TEST_DIR := ./testing
OBJS := $(BUILD_DIR)/command_creators.o $(BUILD_DIR)/command_factory.o $(BUILD_DIR)/commands.o $(BUILD_DIR)/parser.o

SRCS := $(SRC_DIR)/command_creators.cpp $(SRC_DIR)/command_factory.cpp $(SRC_DIR)/commands.cpp $(SRC_DIR)/parser.cpp

all: test parser

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/commands.o: $(BUILD_DIR) $(SRC_DIR)/commands.cpp
	$(CC) $(CXXFLAGS) -c $(SRC_DIR)/commands.cpp -o $(BUILD_DIR)/commands.o

$(BUILD_DIR)/command_creators.o: $(BUILD_DIR) $(SRC_DIR)/command_creators.cpp $(BUILD_DIR)/commands.o
	$(CC) $(CXXFLAGS) -c $(SRC_DIR)/command_creators.cpp -o $(BUILD_DIR)/command_creators.o

$(BUILD_DIR)/command_factory.o: $(BUILD_DIR) $(SRC_DIR)/command_factory.cpp $(BUILD_DIR)/command_creators.o
	$(CC) $(CXXFLAGS) -c $(SRC_DIR)/command_factory.cpp -o $(BUILD_DIR)/command_factory.o

$(BUILD_DIR)/parser.o: $(BUILD_DIR) $(SRC_DIR)/parser.cpp $(BUILD_DIR)/command_factory.o
	$(CC) $(CXXFLAGS) -c $(SRC_DIR)/parser.cpp -o $(BUILD_DIR)/parser.o

$(BUILD_DIR)/test.o: $(BUILD_DIR) $(TEST_DIR)/test.cpp $(BUILD_DIR)/command_factory.o
	$(CC) $(CXXFLAGS) -c $(TEST_DIR)/test.cpp -o $(BUILD_DIR)/test.o

test: $(BUILD_DIR)/test.o $(OBJS)
	$(CC) $(CXXFLAGS) $(BUILD_DIR)/test.o -o test -lgtest -lpthread

parser: $(BUILD_DIR)/parser.o
	$(CC) $(CXXFLAGS) $(OBJS) -o parser


run_test: test
	./test

clean:
	rm -rf $(BUILD_DIR)
	rm test
	rm parser