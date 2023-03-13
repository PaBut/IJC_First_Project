CC = gcc
CFLAGS = -g -std=c11 -Wall -Wextra 

all: primes primes-i steg-decode
	./primes
	./primes-i
	./steg-decode du1-obrazek.ppm

run: primes primes-i
	./primes
	./primes-i

steg-decode: ppm.o error.o eratosthenes.c bitset.h 
	$(CC) $(CFLAGS) steg-decode.c -o steg-decode ppm.o error.o -lm
primes: error.o eratosthenes.c bitset.h
	$(CC) $(CFLAGS) primes.c -o primes error.o -lm -O2

primes-i: error.o eratosthenes.c bitset.h
	$(CC) $(CFLAGS) primes.c -DUSE_INLINE -o primes-i error.o -lm -O2

ppm.o: ppm.c ppm.h
	$(CC) $(CFLAGS) -c ppm.c

error.o: error.c error.h
	$(CC) $(CFLAGS) -c error.c