CC := g++
CXXFLAGS = -std=c++20
BUILD_DIR := ./build
SRC_DIR := ./src
INCLUDE_DIR := ./include
TEST_DIR := ./testing

OBJS := $(BUILD_DIR)/command_creators.o $(BUILD_DIR)/command_factory.o $(BUILD_DIR)/commands.o $(BUILD_DIR)/token_parser.o\
	$(BUILD_DIR)/asm_parser.o $(BUILD_DIR)/executor.o $(BUILD_DIR)/serialization.o $(BUILD_DIR)/main_test.o

all: test main_test

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/commands.o: $(SRC_DIR)/commands/commands.cpp
	$(CC) $(CXXFLAGS) -c $(SRC_DIR)/commands/commands.cpp -o $(BUILD_DIR)/commands.o

$(BUILD_DIR)/command_creators.o: $(BUILD_DIR) $(SRC_DIR)/commands/command_creators.cpp $(BUILD_DIR)/commands.o
	$(CC) $(CXXFLAGS) -c $(SRC_DIR)/commands/command_creators.cpp -o $(BUILD_DIR)/command_creators.o

$(BUILD_DIR)/command_factory.o: $(BUILD_DIR) $(SRC_DIR)/commands/command_factory.cpp $(BUILD_DIR)/command_creators.o
	$(CC) $(CXXFLAGS) -c $(SRC_DIR)/commands/command_factory.cpp -o $(BUILD_DIR)/command_factory.o

$(BUILD_DIR)/token_parser.o: $(BUILD_DIR) $(SRC_DIR)/compiling/token_parser.cpp $(BUILD_DIR)/commands.o
	$(CC) $(CXXFLAGS) -c $(SRC_DIR)/compiling/token_parser.cpp -o $(BUILD_DIR)/token_parser.o

$(BUILD_DIR)/asm_parser.o: $(BUILD_DIR) $(SRC_DIR)/compiling/asm_parser.cpp $(BUILD_DIR)/command_factory.o $(BUILD_DIR)/token_parser.o
	$(CC) $(CXXFLAGS) -c $(SRC_DIR)/compiling/asm_parser.cpp -o $(BUILD_DIR)/asm_parser.o

$(BUILD_DIR)/serialization.o: $(BUILD_DIR) $(SRC_DIR)/compiling/serialization.cpp $(BUILD_DIR)/commands.o
	$(CC) $(CXXFLAGS) -c $(SRC_DIR)/compiling/serialization.cpp -o $(BUILD_DIR)/serialization.o

$(BUILD_DIR)/executor.o: $(BUILD_DIR) $(SRC_DIR)/compiling/executor.cpp $(BUILD_DIR)/commands.o
	$(CC) $(CXXFLAGS) -c $(SRC_DIR)/compiling/executor.cpp -o $(BUILD_DIR)/executor.o


$(BUILD_DIR)/main_test.o: $(BUILD_DIR) $(TEST_DIR)/main_test.cpp $(BUILD_DIR)/asm_parser.o $(BUILD_DIR)/executor.o
	$(CC) $(CXXFLAGS) -c $(TEST_DIR)/main_test.cpp -o $(BUILD_DIR)/main_test.o

$(BUILD_DIR)/test.o: $(BUILD_DIR) $(TEST_DIR)/test.cpp $(BUILD_DIR)/command_factory.o
	$(CC) $(CXXFLAGS) -c $(TEST_DIR)/test.cpp -o $(BUILD_DIR)/test.o

test: $(BUILD_DIR)/test.o $(OBJS)
	$(CC) $(CXXFLAGS) $(BUILD_DIR)/test.o -o test -lgtest -lpthread

main_test: $(BUILD_DIR)/main_test.o
	$(CC) $(CXXFLAGS) $(OBJS) -o main_test


run_test: test
	./test

clean:
	rm -rf $(BUILD_DIR)
	rm test
	rm main_test