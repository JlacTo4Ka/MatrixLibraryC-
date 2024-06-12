CC=g++ -std=c++17 -Wall -Werror -Wextra -pedantic -g
CPP=g++
FILES=functions/*.cpp exception/*.cpp
TESTS=tests/*.cpp
CHECKFLAGS=-lgtest
REPORTDIR=gcov_report
GCOV=--coverage
IGNORE=--ignore-errors source,gcov --no-external --exclude "exception/exception.cpp"

all: clean gcov_report

s21_matrix_oop.a:
	$(CC) -c $(FILES)
	ar rcs s21_matrix_oop.a *.o
	ranlib s21_matrix_oop.a

test: clean
	$(CC) $(GCOV) -c $(FILES) 
	$(CC) -c $(TESTS) 
	$(CC) $(GCOV) -o matrix_test *.o $(CHECKFLAGS)
	./matrix_test

my_test: clean
	$(CC) -c my_test.cpp $(FILES)
	$(CC) -o my_test *.o
	./my_test

check:
	cppcheck $(FILES) && cppcheck --enable=all --suppress=missingIncludeSystem --language=c++  *.h

style: 
	cp ../materials/linters/.clang-format .
	clang-format -i *.h $(FILES) $(TESTS) exception/*.h tests/*.h
	rm .clang-format

style_check:
	cp ../materials/linters/.clang-format .
	clang-format -n *.h $(FILES) $(TESTS) exception/*.h tests/*.h
	rm .clang-format

leaks: test
	valgrind --tool=memcheck --leak-check=yes ./matrix_test

gcov_report: test
	lcov -t "Unit-tests of matrix_oop" -o s21_matrix_oop.info -c -d . $(IGNORE)
	genhtml -o $(REPORTDIR) s21_matrix_oop.info
	open ./$(REPORTDIR)/index.html

clean:
	rm -rf ./*.o ./*.a ./a.out ./*.gcno ./*.gcda ./$(REPORTDIR) *.info ./*.info report matrix_test matrix_oop my_test
