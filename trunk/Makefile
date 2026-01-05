all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b

	@echo "TEST 1: Macierz jednostkowa (2x2)"
	bin/gauss dane/test1_A dane/test1_b
	@echo "----------------------------------------"

	@echo "TEST 2: Macierz z zerem na diagonali"
	bin/gauss dane/test2_A dane/test2_b
	@echo "----------------------------------------"

	@echo "TEST 3: Uklad 3x3"
	bin/gauss dane/test3_A dane/test3_b
	@echo "----------------------------------------"

	@echo "TEST 4: Macierz gornotrojkatna"
	bin/gauss dane/test4_A dane/test4_b
	@echo "----------------------------------------"