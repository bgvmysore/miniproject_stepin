CC = gcc
CFLAGS = -Wall -g

INC = -Iinc -Ignuplot_i
LINK = -lm

PROJECT = folodesolver
SRC = $(wildcard src/*.c) gnuplot_i/gnuplot_i.c
BIN = bin
ifeq ($(OS),Windows_NT)
		CL_BIN = del /q $(BIN)\*.*
		EXEC = $(BIN)\$(PROJECT).exe
		EXEC_TEST = $(BIN)\test_$(PROJECT).exe
else
		CL_BIN = rm $(BIN)/*.*
		EXEC = $(BIN)/$(PROJECT).out
		EXEC_TEST = $(BIN)/test_$(PROJECT).out
endif


$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(INC) $^ -o $@ $(LINK)

run: $(EXEC)
	./$(EXEC)

clean:
	$(CL_BIN)
