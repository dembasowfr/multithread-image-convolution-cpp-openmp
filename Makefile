
CC=g++ 
CFLAGS= -std=gnu++11 -O2 -Iinclude -I/usr/include/python3.10
LDFLAGS= -lpython3.10
DEBUG=-g
SRC_DIR=src
INCLUDE_DIR=include
BIN_DIR=bin
OUTPUT_DIR=output

all: $(BIN_DIR) main

main: $(BIN_DIR)/Convolution.o $(BIN_DIR)/Filter.o $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(BIN_DIR)/Convolution.o $(BIN_DIR)/Filter.o -o $(OUTPUT_DIR)/main $(LDFLAGS)

$(BIN_DIR)/Convolution.o: $(SRC_DIR)/Convolution.cpp $(INCLUDE_DIR)/Convolution.hpp $(BIN_DIR)/Filter.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Convolution.cpp -o $(BIN_DIR)/Convolution.o

$(BIN_DIR)/Filter.o: $(SRC_DIR)/Filter.cpp $(INCLUDE_DIR)/Filter.hpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Filter.cpp -o $(BIN_DIR)/Filter.o

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean: 
	rm -rf $(BIN_DIR) $(OUTPUT_DIR)/main

