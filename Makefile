CFLAGS =-Wall -g -Os
CC = gcc 
OBJECTS = fibonacci.c sequence.c
OUT = fibonacci

all:
	$(CC) $(CFLAGS) $(OBJECTS) -o $(OUT)

check-syntax:
	$(CC) -o nul -S ${CHK_SOURCES}

clean:
	rm $(OUT)
