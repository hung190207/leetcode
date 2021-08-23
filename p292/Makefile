.DEFAULT_GOAL: all
all: clean main
	./nim_game

clean:
	rm -fv nim_game
main:
	gcc -o nim_game nim_game.c
cover:
	rm -fv nim_game
	gcc -fprofile-arcs -ftest-coverage -o nim_game nim_game.c
	gcov nim_game
remove:
	rm -fv nim_game.gcno
	rm -fv nim_game.gcov
	rm -fv stdio.h.gcov
	rm -fv nim_game.c.gcov
	rm -fv nim_game