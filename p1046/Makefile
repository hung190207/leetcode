.DEFAULT_GOAL: all
all: clean main
	./last_stone_weight

clean:
	rm -fv last_stone_weight
main:
	gcc -o last_stone_weight last_stone_weight.c
cover:
	rm -fv last_stone_weight
	gcc -fprofile-arcs -ftest-coverage -o last_stone_weight last_stone_weight.c
	gcov last_stone_weight
remove:
	rm -fv last_stone_weight.gcno
	rm -fv last_stone_weight.gcov
	rm -fv stdio.h.gcov
	rm -fv last_stone_weight.c.gcov
	rm -fv last_stone_weight