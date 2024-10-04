#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int error = 0, flag = 0;
  unsigned int rev = 0;
  if (s21_check(value) || !result) return 1;

  while (s21_get_scale(value)) {
    rev = s21_div_10(&value);
    if (rev) flag = 1;
    s21_set_scale(&value, s21_get_scale(value) - 1);
  }

  if (s21_get_signed(value) && flag) {
    error = s21_simple_add(value, s21_get_rounded(1, 0), &value);
    if (error) error = 1;
  }

  *result = value;

  return error;
}