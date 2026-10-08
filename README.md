# C Text Analysis and Patience Simulator

Three C99 programs covering file I/O, dynamic memory, linked lists and simulation, plus a
shared text-histogram library.

> Built for the **ECM2433** C programming module at the University of Exeter
> (individual coursework, 2025).

| Program | What it does |
|---|---|
| `wordlengths` | Reads a text file and prints a histogram of word lengths |
| `anagram` / `anaquery` | Groups a dictionary into anagram classes in a linked-list structure keyed by sorted letters. Reports the largest classes and looks up anagrams of a word. |
| `patience` | Plays one game of an "elevens" patience: remove visible pairs that sum to 11 until you win or get stuck. Takes an optional seed. |
| `pstatistics` | Runs many patience games and prints a histogram of cards left at the end |

Sample output from `pstatistics` (percentage of games by cards left in the deck):

```
 0: **********************************************  10.59
 ...
15: ***   0.79
17: ****   0.85
```

## Building

Needs `gcc` and the GNU Scientific Library (`libgsl-dev`), which the shuffle uses.

```bash
make all        # builds every program into the repo root
make clean
```

Each `Q1/`, `Q2/` and `Q3/` folder also has its own Makefile.

## Running

```bash
./wordlengths dracula.txt
./anagram words.txt
./anaquery
./patience 42
./pstatistics
```

## Credits

The module provided the shuffle routine in `shuffle/`.
