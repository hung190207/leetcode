.DEFAULT_GOAL: all
all: clean main
	./length_of_last_word

clean:
	rm -fv length_of_last_word
main:
	gcc -o length_of_last_word length_of_last_word.c
cover:
	gcc -fprofile-arcs -ftest-coverage -o length_of_last_word length_of_last_word.c
	gcov length_of_last_word
remove:
	rm -fv length_of_last_word.gcno
	rm -fv length_of_last_word.gcov
	rm -fv stdio.h.gcov
	rm -fv length_of_last_word.c.gcov
	rm -fv length_of_last_word.exe