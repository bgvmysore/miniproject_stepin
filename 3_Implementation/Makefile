CC = gcc
CFLAGS = -Wall -g

INC = -Iinc -Ignuplot_i -Iunity
LINK = -lm

UNITY_SRC = unity/unity.c

PROJECT = folodesolver
SRC = $(wildcard src/*.c) gnuplot_i/gnuplot_i.c
MAIN = main.c

ifeq ($(OS),Windows_NT)
		RM = del /q
		EXEC = $(PROJECT).exe
		EXEC_TEST = test/test_$(PROJECT).exe
else
		RM = rm
		EXEC = $(PROJECT).out
		EXEC_TEST = test/test_$(PROJECT).out
endif


$(EXEC): $(SRC) $(MAIN)
	$(CC) $(CFLAGS) $(INC) $^ -o $@ $(LINK)

run: $(EXEC)
	./$(EXEC)

clean:
	$(RM) $(EXEC)

$(EXEC_TEST): $(UNITY_SRC) $(SRC) test/tests.c
	$(CC) $(CFLAGS) $(INC) $^ -o $@ $(LINK) -D UNITTEST

runtests: $(EXEC_TEST)
	./$(EXEC_TEST)

cleantest:
	cd test && $(RM) *.exe && cd ..

cleansol:
	$(RM) soln.csv

cleanall: clean cleantest cleansol
