#ifndef BIG_DECIMAL_H
#define BIG_DECIMAL_H

#define ALL_BIG_ZERO {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define BIG_TEN {0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0}
#define MAX_BIG_INDEX 32 * 9 - 1

typedef struct s21_big_decimal {
  int scale;
  int sign;
  unsigned int bits[9];
} s21_big_decimal;

int s21_normalize_bigs(s21_big_decimal* big_value_1,
                       s21_big_decimal* big_value_2);
int s21_big_mult_ten(s21_big_decimal* big_value);
int s21_big_to_left_shift(s21_big_decimal* value, int shift);
int s21_big_to_right_shift(s21_big_decimal* value, int shift);
int s21_big_simple_add(s21_big_decimal value_1, s21_big_decimal value_2,
                       s21_big_decimal* result);
int s21_big_get_bit(s21_big_decimal value, int index);
void s21_big_set_bit(s21_big_decimal* value, int index, int bit_value);
int s21_big_simple_sub(s21_big_decimal value_1, s21_big_decimal value_2,
                       s21_big_decimal* result);
int s21_big_search_the_biggest(s21_big_decimal value);
void s21_big_zaem(s21_big_decimal* value, int index);
// void big_math_and_bank_round(s21_big_decimal* big_value, s21_big_decimal
// copy);
int s21_big_is_equal(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_big_simple_is_greater(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_big_simple_is_greater_or_equel(s21_big_decimal value_1,
                                       s21_big_decimal value_2);
int s21_big_div_10(s21_big_decimal* value_1);
void s21_make_big_mantiss_zero(s21_big_decimal* value);
void s21_big_copy(s21_big_decimal src, s21_big_decimal* dest);

int s21_check_is_greater_max(s21_big_decimal val);

int s21_big_is_zero_mantissa(s21_big_decimal value);
int s21_add_remainder(s21_big_decimal remainder, s21_big_decimal* result,
                      s21_big_decimal del);

#endif  // BIG_DECIMAL_H