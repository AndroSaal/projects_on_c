CC = gcc 
CFLAGS = -Wextra -Werror -Wall -std=c11
FILES_TO_COMPILE = parser output main
C_FILES_TO_COMPILE = $(addsuffix .c, $(FILES_TO_COMPILE))
O_FILES_TO_COMPILE = $(addsuffix .o, $(FILES_TO_COMPILE))
EXECUTABLE_FILE_NAME = s21_grep

all : s21_grep

s21_grep : get_objective_files
	$(CC) $(O_FILES_TO_COMPILE) -o $(EXECUTABLE_FILE_NAME)

get_objective_files :
	$(CC) $(CFLAGS) -std=c11 -g -O0 -c $(C_FILES_TO_COMPILE)

fclean : 
	rm -rf *.o $(EXECUTABLE_FILE_NAME) ./test/$(EXECUTABLE_FILE_NAME) *.txt ./test/1 ./test/2 ./test/log.txt
clean :
	rm *.o

rebuild : clean all

save_at_git : 
	git add .
	git commit
	git push
	git status

output_test_for_macos :
	sh ../tests/grep_test_combinations_1.sh

standart_output_test_for_macos :
	sh ../tests/grep_test_for_verter.sh