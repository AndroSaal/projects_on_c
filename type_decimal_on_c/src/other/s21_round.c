#include "../s21_decimal.h"

int s21_round(s21_decimal value,
              s21_decimal *result) {  // подумать над реализацией точности!!
  int error = 0, remainder = 0, scale = 0, remainder_scale = 0,
      flag_to_round = 0;

  if (s21_check(value) || !result) return 1;

  while ((scale = s21_get_scale(value))) {
    if (flag_to_round) {
      remainder = s21_div_10(&value) + 1;
      flag_to_round = 0;
    } else {
      remainder = s21_div_10(&value);
    }
    if (remainder >= 5) flag_to_round = 1;
    s21_set_scale(&value, s21_get_scale(value) - 1);
  }
  *result = value;

  s21_make_mantiss_zero(&value);
  value.bits[0] = 1;

  if (remainder >= 5) s21_simple_add(*result, value, result);

  return error;
}