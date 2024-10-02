
OS = $(shell uname)
ifeq ("$(OS)","Linux")
	CC = gcc
	LEAKS_RUN_TEST=valgrind --tool=memcheck --leak-check=yes --log-file=1.txt ./unit_tests
	CHECK_FLAGS=-pthread -lcheck_pic -pthread -lrt -lm -lsubunit
else
	CC=gcc
	LEAKS_RUN_TEST=leaks -atExit -- ./unit_tests
	CHECK_FLAGS=-lcheck
endif

CFLAGS = -std=c11 -Wall -Werror -Wextra

FILES_NAMES = create remove equel summa difference multiplication transpose complements determinant inverse
SRC = $(addprefix s21_, $(addsuffix .c, $(FILES_NAMES) common))
OBJ = $(addprefix obj/s21_, $(addsuffix .o, $(FILES_NAMES) common))
TEST_SRC = $(addprefix tests/test_, $(addsuffix .c, $(FILES_NAMES:remove=main)))
OBJ_TESTS = $(addprefix obj_tests/test_, $(addsuffix .o, $(FILES_NAMES:remove=main)))
GCOV_FLAGS =--coverage

.PHONY: all clean rebuild

all : clean s21_matrix.a

s21_matrix.a : create_obj
	ar rc $@ ./obj/*.o
	ranlib $@

create_obj : $(SRC)
	$(CC) -c $(CFLAGS) $(SRC)
	mkdir obj
	mv *.o obj

create_obj_test : $(TEST_SRC)
	mkdir obj_tests
	$(CC) -c $(CFLAGS) $(TEST_SRC)
	mv *.o ./obj_tests

test : clean 
	$(CC) $(CFLAGS) $(SRC) $(TEST_SRC) -o ./unit_tests $(CHECK_FLAGS)
	./unit_tests 2> errors_log.txt

leak_for_linux : clean test
	$(LEAKS_RUN_TEST)

gcov_report : clean create_obj_test
	$(CC) -c $(CFLAGS) $(GCOV_FLAGS) $(SRC)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) *.o $(OBJ_TESTS) -o ./gcov_unit_tests $(CHECK_FLAGS)
	./gcov_unit_tests 2> errors_log.txt
	mv *.gcda *.gcno obj_tests
	lcov --directory obj_tests --capture -o obj_tests/coverage.info
	genhtml --output-directory report --legend obj_tests/coverage.info
	open report/index.html
# $(CC) $(CFLAGS) $(GCOV_FLAGS) $(SRC) $(TEST_SRC) -o ./gcov_unit_tests $(CHECK_FLAGS)
clang : clang_copy
	clang-format -n *.h $(SRC) $(TEST_SRC) tests/*.c tests/*.h
	clang-format -i *.h $(SRC) $(TEST_SRC) tests/*.c tests/*.h

clang_copy : 
	cp ../materials/linters/.clang-format .

rebuild : clean all

clean :
	rm -rf obj obj_tests *.a errors_log.txt unit_tests gcov_unit_tests .clang-format *.o report