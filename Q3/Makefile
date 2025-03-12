CC = gcc
CFLAGS = -std=c99
LDFLAGS = -L.
LDLIBS = -lm -lgsl -lgslcblas

all: patience pstatistics

patience: patience.o patience_game.o shuffle.o
	$(CC) $(CFLAGS) $(LDFLAGS) patience.o patience_game.o shuffle.o -o patience $(LDLIBS)

pstatistics: pstatistics.o patience_game.o shuffle.o histogram.o
	$(CC) $(CFLAGS) $(LDFLAGS) pstatistics.o patience_game.o shuffle.o histogram.o -o pstatistics $(LDLIBS)

pstatistics.o: pstatistics.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c pstatistics.c

histogram.o: ../Q1/histogram.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c ../Q1/histogram.c

patience.o: patience.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c patience.c

patience_game.o: patience_game.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c patience_game.c


shuffle.o: ../shuffle/shuffle.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c ../shuffle/shuffle.c


clean:
	rm -rf *.o patience pstatistics
