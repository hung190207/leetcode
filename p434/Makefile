.DEFAULT_GOAL: all
all: clean main
	./number_of_segments_in_a_string

clean:
	rm -fv number_of_segments_in_a_string
main:
	gcc -o number_of_segments_in_a_string number_of_segments_in_a_string.c
cover:
	gcc -fprofile-arcs -ftest-coverage -o number_of_segments_in_a_string number_of_segments_in_a_string.c
	gcov number_of_segments_in_a_string
remove:
	rm -fv number_of_segments_in_a_string.gcno
	rm -fv number_of_segments_in_a_string.gcov
	rm -fv stdio.h.gcov
	rm -fv number_of_segments_in_a_string.c.gcov
	rm -fv number_of_segments_in_a_string