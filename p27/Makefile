.DEFAULT_GOAL: all
all: clean main
	./remove_element

clean:
	rm -fv remove_element
main:
	gcc -o remove_element remove_element.c
cover:
	gcc -fprofile-arcs -ftest-coverage -o remove_element remove_element.c
	gcov remove_element
remove:
	rm -fv remove_element.gcno
	rm -fv remove_element.gcov
	rm -fv stdio.h.gcov
	rm -fv remove_element.c.gcov
	rm -fv remove_element.exe