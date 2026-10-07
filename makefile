CC = g++
CFLAGS = -c -Wall
TESTS_DIR = tests
TARGET_DIR = bin

all: ML

dir:
	mkdir -p $(TARGET_DIR)

ML: tensor.o
	$(CC) tensor.o $(TARGET_DIR)/ML

tests: tensor.o tests.o
	$(CC) $(TARGET_DIR)/tensor.o $(TARGET_DIR)/tests.o -o $(TARGET_DIR)/tests


########################################################################

tensor.o: tensor.cpp tensor.h
	$(CC) $(CFLAGS) tensor.cpp -o $(TARGET_DIR)/tensor.o

tests.o: $(TESTS_DIR)/tests.cpp
	$(CC) $(CFLAGS) $(TESTS_DIR)/tests.cpp -o $(TARGET_DIR)/tests.o

clean:
	rm -rf $(TARGET_DIR)