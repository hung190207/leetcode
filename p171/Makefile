.DEFAULT_GOAL: all
all: clean main
	./excel_sheet_column_number

clean:
	rm -fv excel_sheet_column_number
main:
	gcc -o excel_sheet_column_number excel_sheet_column_number.c
cover:
	gcc -fprofile-arcs -ftest-coverage -o excel_sheet_column_number excel_sheet_column_number.c
	gcov excel_sheet_column_number
remove:
	rm -fv excel_sheet_column_number.gcno
	rm -fv excel_sheet_column_number.gcov
	rm -fv stdio.h.gcov
	rm -fv excel_sheet_column_number.c.gcov
	rm -fv excel_sheet_column_number.exe