CC = gcc
CFLAGS = -std=c99
LDFLAGS = -L.
LDLIBS = -lm

all: wordlengths demo_histogram

wordlengths: wordlengths.o histogram.o readfile.o
	$(CC) $(CFLAGS) $(LDFLAGS) wordlengths.o histogram.o readfile.o -o wordlengths $(LDLIBS)

demo_histogram: demo_histogram.o histogram.o
	$(CC) $(CFLAGS) $(LDFLAGS) demo_histogram.o histogram.o -o demo_histogram $(LDLIBS)

demo_histogram.o: demo_histogram.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c demo_histogram.c

histogram.o: histogram.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c histogram.c

wordlengths.o: wordlengths.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c wordlengths.c

readfile.o: readfile.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c readfile.c

clean:
	rm -f *.o wordlengths demo_histogram
