CC = gcc
CFLAGS = -Wall -g -std=c99

INC = -Iinc

PROJECT = folodesolver
SRC = $(wildcard src/*.c)
BIN = bin
ifeq ($(OS),Windows_NT)
		CL_BIN = del $(BIN)\*.*
		EXEC = $(BIN)\$(PROJECT).exe
		EXEC_TEST = $(BIN)\test_$(PROJECT).exe
else
		CL_BIN = rm $(BIN)/*.*
		EXEC = $(BIN)/$(PROJECT).out
		EXEC_TEST = $(BIN)/test_$(PROJECT).out
endif


$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(INC) $^ -o $@

run: $(EXEC)
	./$(EXEC)

clean:
	$(CL_BIN)
