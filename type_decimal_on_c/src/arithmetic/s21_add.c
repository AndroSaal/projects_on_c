#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = ok;
  if (result != NULL) {
    s21_make_mantiss_zero(result);
    result->bits[3] = 0;  // заунляем результат
    s21_big_decimal big_value_1 = s21_convert_to_big_decimal(value_1),
                    big_value_2 = s21_convert_to_big_decimal(value_2),
                    big_result = ALL_BIG_ZERO;

    error = s21_normalize_bigs(&big_value_1, &big_value_2);

    if (!error) {
      if (big_value_1.sign == big_value_2.sign) {  // если знаки равны
        error = s21_big_simple_add(big_value_1, big_value_2, &big_result);
      } else {                 // если знаки не равны
        if (big_value_1.sign)  // первое отр
          error = s21_big_simple_sub(big_value_2, big_value_1, &big_result);
        if (big_value_2.sign)  // второе отр
          error = s21_big_simple_sub(big_value_1, big_value_2, &big_result);
      }

      big_result.scale = big_value_1.scale;
      error = s21_big_convert_to_decimal(big_result, result);
    }

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
