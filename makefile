<<<<<<< HEAD
mycmd-debug:mycmd.c
	gcc -o $@ $^ -g
.PHONY:clean
clean:
	rm -f mycmd-debug
=======
BIN=process
CC=gcc
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

$(BIN):$(OBJ)
		$(CC) -o $@ $^
%.o:%.c
		$(CC) -c $<

.PHONY: clean
clean:
	rm -rf $(OBJ) $(BIN)
>>>>>>> bf6241217406412ca05b4e9eeb286098f72315c1
