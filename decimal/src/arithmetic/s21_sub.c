#include "../common_function/big_decimal_staff.h"
#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = ok;

  if (result != NULL) {
    s21_make_mantiss_zero(result);
    result->bits[3] = 0;

    s21_big_decimal big_value_1 = s21_convert_to_big_decimal(value_1);
    s21_big_decimal big_value_2 = s21_convert_to_big_decimal(value_2);
    s21_big_decimal big_result = ALL_BIG_ZERO;

    error = s21_normalize_bigs(&big_value_1, &big_value_2);

    if (s21_get_signed(value_1) != s21_get_signed(value_2) &&
        !error) {  // если знаки не равны
      error += s21_big_simple_add(big_value_1, big_value_2, &big_result);
      if (big_value_2.sign) big_result.sign = 0;
      if (big_value_1.sign) big_result.sign = 1;
    } else if (!error) {  // если знаки одинаковые
      big_value_2.sign = !big_value_2.sign;
      error += s21_big_simple_sub(big_value_1, big_value_2, &big_result);
    }

    big_result.scale = big_value_1.scale;

    if (!error) error = s21_big_convert_to_decimal(big_result, result);

    if (error) error = big_result.sign ? TOO_SMALl : TOO_BIG;
  } else {
    error = ERR;
  }

  if (error && result) {
    s21_make_mantiss_zero(result);
    result->bits[3] = 0;
  }

  return error;
}
