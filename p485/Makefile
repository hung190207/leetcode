.DEFAULT_GOAL: all
all: clean main
	./max_consecutive_ones

clean:
	rm -fv max_consecutive_ones
main:
	gcc -o max_consecutive_ones max_consecutive_ones.c
cover:
	gcc -fprofile-arcs -ftest-coverage -o max_consecutive_ones max_consecutive_ones.c
	gcov max_consecutive_ones
remove:
	rm -fv max_consecutive_ones.gcno
	rm -fv max_consecutive_ones.gcov
	rm -fv stdio.h.gcov
	rm -fv max_consecutive_ones.c.gcov
	rm -fv max_consecutive_ones