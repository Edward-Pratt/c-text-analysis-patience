CC = gcc
CFLAGS = -std=c99
LDLIBS = -lm  -lgsl -lgslcblas



all: wordlengths demo_histogram anagram anaquery patience pstatistics

wordlengths: ./Q1/wordlengths.o ./Q1/histogram.o ./Q1/readfile.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

demo_histogram: ./Q1/demo_histogram.o ./Q1/histogram.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

anagram: ./Q2/anagram.o ./Q2/anagram_linked_list.o ./Q1/readfile.o ./Q1/histogram.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

anaquery: ./Q2/anaquery.o ./Q2/anagram_linked_list.o ./Q1/readfile.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

patience: ./Q3/patience.o ./Q3/patience_game.o ./shuffle/shuffle.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

pstatistics: ./Q3/pstatistics.o ./Q3/patience_game.o ./shuffle/shuffle.o ./Q1/histogram.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)



./Q1/%.o: ./Q1/%.c
	$(CC) $(CFLAGS) -c $< -o $@


./Q2/%.o: ./Q2/%.c
	$(CC) $(CFLAGS) -c $< -o $@


./Q3/%.o: ./Q3/%.c
	$(CC) $(CFLAGS) -c $< -o $@


./shuffle/%.o: ./shuffle/%.c
	$(CC) $(CFLAGS) -c $< -o $@




clean:
	rm -f wordlengths demo_histogram anagram anaquery patience pstatistics ./Q1/*.o ./Q2/*.o ./Q3/*.o ./shuffle/*.o

