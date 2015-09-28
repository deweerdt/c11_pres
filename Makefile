CFLAGS=-O3 -std=c11 -Wall -pedantic

EXES=unicode generics1 generics2 generics3 generics3.i generics3.c.004t.gimple integer_overflow integer_overflow_ubsan concurrency_c11atomics concurrency_c11atomics_relaxed concurrency_in_house_atomics concurrency_incorrect concurrency_mutex

all: $(EXES)

unicode: unicode.c
	gcc $(CFLAGS) -o $@ $<

generics1: generics1.c
	gcc $(CFLAGS) -o $@ $<

generics2: generics2.c
	gcc $(CFLAGS) -o $@ $<

generics3: generics3.c
	gcc $(CFLAGS) -o $@ $< -lm

generics3.i: generics3.c
	gcc -E $(CFLAGS) -o $@ $<

generics3.c.004t.gimple: generics3.c
	gcc -o /dev/null -c -fdump-tree-gimple -std=c11 -Wall -pedantic $<

integer_overflow: integer_overflow.c
	gcc $(CFLAGS) -o $@ $<

integer_overflow_ubsan: integer_overflow.c
	gcc $(CFLAGS) -o $@ $< -fsanitize=undefined

concurrency_c11atomics: concurrency_c11atomics.c
	gcc $(CFLAGS) -o $@ $< -lpthread

concurrency_c11atomics_relaxed: concurrency_c11atomics_relaxed.c
	gcc $(CFLAGS) -o $@ $< -lpthread

concurrency_in_house_atomics: concurrency_in_house_atomics.c
	gcc $(CFLAGS) -o $@ $< -lpthread

concurrency_incorrect: concurrency_incorrect.c
	gcc $(CFLAGS) -o $@ $< -lpthread

concurrency_mutex: concurrency_mutex.c
	gcc $(CFLAGS) -o $@ $< -lpthread


clean:
	rm $(EXES)
