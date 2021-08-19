.DEFAULT_GOAL: all
all: clean main
	./ugly_number

clean:
	rm -fv ugly_number
main:
	gcc -o ugly_number ugly_number.c
cover:
	gcc -fprofile-arcs -ftest-coverage -o ugly_number ugly_number.c
	gcov ugly_number
remove:
	rm -fv ugly_number.gcno
	rm -fv ugly_number.gcov
	rm -fv stdio.h.gcov
	rm -fv ugly_number.c.gcov
	rm -fv ugly_number