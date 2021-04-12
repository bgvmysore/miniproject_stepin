CC = gcc
CFLAGS = -Wall -g

INC = -Iinc -Ignuplot_i
LINK = -lm

PROJECT = folodesolver
SRC = $(wildcard src/*.c) gnuplot_i/gnuplot_i.c

ifeq ($(OS),Windows_NT)
		RM = del /q
		EXEC = $(PROJECT).exe
		EXEC_TEST = test_$(PROJECT).exe
else
		RM = rm
		EXEC = $(PROJECT).out
		EXEC_TEST = test_$(PROJECT).out
endif


$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(INC) $^ -o $@ $(LINK)

run: $(EXEC)
	./$(EXEC)

clean:
	$(RM) $(EXEC)