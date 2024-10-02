lsCC = gcc
COMPILE_FLAGS = -std=c11 -Werror -Wextra -Wall

SRC_DIRS = arithmetic common_function comparison convertation other

ARITHMETIC = $(addprefix arithmetic/, $(addprefix s21_, add div mul sub))
COMMON_FUNC = $(addprefix common_function/, big_decimal_staff bits_operations scale_operations simple_logic_finc str_decimal_convertor error)
COMPRASION = $(addprefix comparison/, equal greater_or_equal greater less_or_equal less not_equal)
CONVERTATION = $(addprefix convertation/, from_decimal_to_float from_decimal_to_int from_float_to_decimal from_int_to_decimal)
OTHER = $(addprefix other/, $(addprefix s21_, floor negate round truncate))

FILES_TO_COMPILE = $(COMMON_FUNC) $(ARITHMETIC) $(COMPRASION) $(CONVERTATION) $(OTHER)
SRC_TEST_TO_COPILE = arithmetic_tests other_tests comparison_tests convertation_tests main_tests
TEST_FILES_TO_COMPILE = $(addprefix tests/, $(SRC_TEST_TO_COPILE))

SRC = $(addsuffix .c, $(FILES_TO_COMPILE))
TEST_SRC = $(addsuffix .c, $(TEST_FILES_TO_COMPILE))
# OBJ = $(addsuffix .o, $(FILES_TO_COMPILE))
GCOV_FLAGS = --coverage

OS := $(shell uname -s)
ifeq ($(OS), Darwin)
    CHECK_FLAGS=-lcheck
else
	CHECK_FLAGS=-pthread -lcheck_pic -pthread -lrt -lm -lsubunit
endif

GCOV_FLAGS = --coverage

.PHONY: all clean rebuild

all: clean s21_decimal.a gcov_report

s21_decimal.a : create_obj
	ar rc $@ ./obj/*.o
	ranlib $@

create_obj :
	mkdir obj
	$(CC) -c $(FLAGS) $(SRC)
	mv *.o ./obj

create_obj_test :
	mkdir obj_tests
	$(CC) -c $(FLAGS) $(TEST_SRC)
	mv *.o ./obj_tests

test : clean
	$(CC) $(FLAGS) $(SRC) $(TEST_SRC) -o ./unit_tests $(CHECK_FLAGS)
	./unit_tests

gcov_report : clean create_obj create_obj_test
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(SRC) $(TEST_SRC) -o ./gcov_unit_tests $(CHECK_FLAGS)
	./gcov_unit_tests
	mv *.gcda *.gcno obj_tests
	lcov --directory obj_tests --capture -o obj_tests/coverage.info
	genhtml --output-directory report --legend obj_tests/coverage.info
	open report/index.html

clang : clang_copy
	clang-format -n *.h $(SRC) $(TEST_SRC) tests/*.c common_function/*.h
	clang-format -i *.h $(SRC) $(TEST_SRC) tests/*.c common_function/*.h

clang_copy : 
	cp ../materials/linters/.clang-format .
	
clean:
	rm -rf obj obj_tests ./tests/*.o unit_tests s21_decimal.a gcov_unit_tests unit_tests report .clang-format obj/ \2 running_test_2 running_test_1 *.gcda *.gcno *.a
