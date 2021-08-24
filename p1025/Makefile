.DEFAULT_GOAL: all
all: clean main
	./divisor_game

clean:
	rm -fv divisor_game
main:
	gcc -o divisor_game divisor_game.c
cover:
	rm -fv divisor_game
	gcc -fprofile-arcs -ftest-coverage -o divisor_game divisor_game.c
	gcov divisor_game
remove:
	rm -fv divisor_game.gcno
	rm -fv divisor_game.gcov
	rm -fv stdio.h.gcov
	rm -fv divisor_game.c.gcov
	rm -fv divisor_game