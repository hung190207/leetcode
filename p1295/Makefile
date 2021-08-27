.DEFAULT_GOAL: all
all: clean main
	./find_numbers_with_even_number_of_digits

clean:
	rm -fv find_numbers_with_even_number_of_digits
main:
	gcc -o find_numbers_with_even_number_of_digits find_numbers_with_even_number_of_digits.c
cover:
	gcc -fprofile-arcs -ftest-coverage -o find_numbers_with_even_number_of_digits find_numbers_with_even_number_of_digits.c
	gcov find_numbers_with_even_number_of_digits
remove:
	rm -fv find_numbers_with_even_number_of_digits.gcno
	rm -fv find_numbers_with_even_number_of_digits.gcov
	rm -fv stdio.h.gcov
	rm -fv find_numbers_with_even_number_of_digits.c.gcov
	rm -fv find_numbers_with_even_number_of_digits