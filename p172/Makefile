.DEFAULT_GOAL: all
all: clean main
	./factorial_trailing_zeroes

clean:
	rm -fv factorial_trailing_zeroes
main:
	gcc -o factorial_trailing_zeroes factorial_trailing_zeroes.c
cover:
	gcc -fprofile-arcs -ftest-coverage -o factorial_trailing_zeroes factorial_trailing_zeroes.c
	gcov factorial_trailing_zeroes
remove:
	rm -fv factorial_trailing_zeroes.gcno
	rm -fv factorial_trailing_zeroes.gcov
	rm -fv stdio.h.gcov
	rm -fv factorial_trailing_zeroes.c.gcov
	rm -fv factorial_trailing_zeroes.exe