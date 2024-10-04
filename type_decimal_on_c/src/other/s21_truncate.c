#include "../s21_decimal.h"

// отбрасывание всех дрробных цифер (без округления)
int s21_truncate(s21_decimal value, s21_decimal *result) {
  int result_ = ok, scale = s21_get_scale(value);

  if (s21_check(value) || !result) return result_ = 1;

  while (scale) {
    s21_div_10(&value);
    scale--;
  }

  s21_set_scale(&value, scale);
  if (s21_is_zero_mantiss(value)) s21_set_signed(&value, 0);

  *result = value;

  return result_;
}