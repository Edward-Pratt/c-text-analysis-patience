CC = gcc
CFLAGS = -std=c99
LDFLAGS = -L.
LDLIBS = -lm



all: anagram anaquery

anagram: anagram.o anagram_linked_list.o readfile.o histogram.o
	$(CC) $(CFLAGS) $(LDFLAGS) anagram.o anagram_linked_list.o readfile.o histogram.o -o anagram $(LDLIBS)


anaquery: anaquery.o anagram_linked_list.o readfile.o
	$(CC) $(CFLAGS) $(LDFLAGS) anaquery.o anagram_linked_list.o readfile.o -o anaquery 

anaquery.o: anaquery.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c anaquery.c 


readfile.o: ../Q1/readfile.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c ../Q1/readfile.c

histogram.o: ../Q1/histogram.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c ../Q1/histogram.c $(LDLIBS)

anagram.o: anagram.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c anagram.c

anagram_linked_list.o: anagram_linked_list.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c anagram_linked_list.c

clean:
	rm -f *.o anagram anaquery
