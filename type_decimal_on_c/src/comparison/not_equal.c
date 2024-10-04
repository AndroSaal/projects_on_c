#include "../s21_decimal.h"

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  int res = 0;
  if (!s21_check(value_1) && !s21_check(value_2)) {
    if (!s21_is_equal(value_1, value_2)) res = 1;
  }
  return res;
}