all: s21_cat s21_grep

s21_cat:
	make -C cat s21_cat

s21_grep:
	make -C grep s21_grep

rebuild: clean all

clean:
	make -C cat clean
	make -C grep clean