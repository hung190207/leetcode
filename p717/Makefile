.DEFAULT_GOAL: all
all: clean main
	./1_bit_and_2_bit_character

clean:
	rm -fv 1_bit_and_2_bit_character
main:
	gcc -o 1_bit_and_2_bit_character 1_bit_and_2_bit_character.c
cover:
	gcc -fprofile-arcs -ftest-coverage -o 1_bit_and_2_bit_character 1_bit_and_2_bit_character.c
	gcov 1_bit_and_2_bit_character
remove:
	rm -fv 1_bit_and_2_bit_character.gcno
	rm -fv 1_bit_and_2_bit_character.gcov
	rm -fv stdio.h.gcov
	rm -fv 1_bit_and_2_bit_character.c.gcov
	rm -fv 1_bit_and_2_bit_character