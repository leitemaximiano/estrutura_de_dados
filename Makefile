CC=gcc
CFLAGS=-fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow
LDLIBS=-lcrypt -lcs50 -lm

BIN = ./bin
OBJ = ./obj
SRC = ./src
INCLUDE = ./include
APP = ./src

all: libed $(BIN)/app

libed: \
	$(OBJ)/lista_ls.o

$(BIN)/%:	$(APP)/app.c
	$(CC) $(CFLAGS) -o $@ $(OBJ)/*.o $< -I $(INCLUDE) $(LDLIBS)

$(OBJ)/%.o:	$(SRC)/%.c $(INCLUDE)/%.h
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@ $(LDLIBS)

run:
	@$(BIN)/app

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/*

