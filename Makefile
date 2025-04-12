CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJS = main.o transaction.o auth_engine.o logger.o

all: app

app: $(OBJS)
	$(CC) $(CFLAGS) -o app $(OBJS)

main.o: main.c transaction.h auth_engine.h logger.h
	$(CC) $(CFLAGS) -c main.c

transaction.o: transaction.c transaction.h
	$(CC) $(CFLAGS) -c transaction.c

auth_engine.o: auth_engine.c auth_engine.h transaction.h
	$(CC) $(CFLAGS) -c auth_engine.c

logger.o: logger.c logger.h transaction.h
	$(CC) $(CFLAGS) -c logger.c

clean:
	rm -f *.o app
