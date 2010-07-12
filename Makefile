DEBUG=yes

ifeq ($(DEBUG),yes)
	CFLAGS=-Wall -W -ansi -g -D DEBUG
else
	CFLAGS=-Wall -W -ansi
endif

CC=gcc
LDFLAGS=-lpthread -lm
EXEC=SuperPremier

all: $(EXEC)

$(EXEC): thread.o io.o superpremier.o
		@echo Link des fichiers
		@$(CC) $(LDFLAGS) -o $(EXEC) $^

superpremier.o: superpremier.c
		@echo Compilation de superpremier.c
		@$(CC) $(CFLAGS) -o $@ -c $<

io.o: io.c io.h
		@echo Compilation de io.c
		@$(CC) $(CFLAGS) -o $@ -c $<

thread.o: thread.c thread.h
		@echo Compilation de thread.c
		@$(CC) $(CFLAGS) -o $@ -c $<

clean: 
		rm -rf *.o

mrproper: clean
		rm $(EXEC) 
		




