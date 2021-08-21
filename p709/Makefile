.DEFAULT_GOAL: all
all: clean main
	./to_lower_case

clean:
	rm -fv to_lower_case
main:
	gcc -o to_lower_case to_lower_case.c
cover:
	gcc -fprofile-arcs -ftest-coverage -o to_lower_case to_lower_case.c
	gcov to_lower_case
remove:
	rm -fv to_lower_case.gcno
	rm -fv to_lower_case.gcov
	rm -fv stdio.h.gcov
	rm -fv to_lower_case.c.gcov
	rm -fv to_lower_case