#ifndef S21_DECIMAL
#define S21_DECIMAL

#include <math.h>
#include <stdio.h>

#include "./common_function/big_decimal_staff.h"

typedef struct {
  unsigned int bits[4];
} s21_decimal;

#define NULL_POINTER -1

// big decimal
s21_big_decimal s21_convert_to_big_decimal(s21_decimal value);
int s21_abs_scales_diff(s21_decimal a, s21_decimal b);
int s21_big_convert_to_decimal(s21_big_decimal big_value, s21_decimal *value);

// операции с битами
void s21_set_bit(s21_decimal *value, int index, int bit_value);
int s21_get_bit(s21_decimal value, int index);
int s21_to_left_shift(s21_decimal *value, int shift);
int s21_to_right_shift(s21_decimal *value, int shift);
int s21_norma(s21_decimal *value_1, s21_decimal *value_2);
int s21_check(s21_decimal value_1);
int s21_check_bit3(s21_decimal value_1, int min_index, int max_index);
int s21_search_the_biggest(s21_decimal value);
s21_big_decimal s21_del_mantiss(s21_big_decimal big_value_1,
                                s21_big_decimal big_value_2,
                                s21_big_decimal *result);

// знак
int s21_get_signed(s21_decimal value);
void s21_set_signed(s21_decimal *value, int signed_value);

// операции со степенью
int s21_get_scale(s21_decimal value);
void s21_set_scale(s21_decimal *value, int scale);
int s21_scales_diff(s21_decimal a, s21_decimal b);

// simple_арифметика
int s21_simple_add(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result);
int s21_mult_10(s21_decimal *value);
unsigned int s21_div_10(s21_decimal *value_1);
void s21_make_mantiss_zero(s21_decimal *value_1);
int s21_simple_sub(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result);
void s21_zaem(s21_decimal *value, int index);
int s21_simple_who_is_bigger(s21_decimal value_1, s21_decimal value_2);
int s21_is_zero_mantiss(s21_decimal a);
s21_decimal s21_get_rounded(int n, int scale);
// int s21_add_remainder(s21_decimal remainder, s21_decimal* result);
// int return_sign (s21_decimal value_1, s21_decimal value_2);

// s21_arithmetic
enum arithmetic_err_code {
  ok,       // 0— OK;
  TOO_BIG,  // 1 — число слишком велико или равно бесконечности;
  TOO_SMALl,  // 2 — число слишком мало или равно отрицательной бесконечности;
  divide_by_zero,  // 3 — деление на 0.
  ERR = 0
};
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_make_sub_with_big_decimal(s21_decimal value_1, s21_decimal value_2,
                                  s21_decimal *result);

// s21_compression
enum comprassion_res_code { first_bigger, second_bigger };

int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

// s21_covertation
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);

// other
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);

#include "./common_function/big_decimal_staff.h"

#endif  // S21_DECIMAL