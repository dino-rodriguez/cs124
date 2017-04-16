# CS 124 Prog 3

## Usage
To generate an input text file, simply run:

```bash
$ python gen.py
```

To run the KK heuristic on this file:

```bash
$ make
$ ./kk inputfile.txt
```

To run tests (and to run the 3 variants on both the standard and prepartioning representations):

```bash
$ python kk_test.py
```

## TODO
We need better test coverage for the repeated random/hill climbing/simulated annealing algorithms, especially for the standard rep as the numbers seem funky.

We need to ensure our random number generation is correct.

We might want a general code cleanup before turn-in.