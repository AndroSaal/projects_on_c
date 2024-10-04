#include "../s21_decimal.h"

int print_binary(int dec);

s21_big_decimal s21_convert_to_big_decimal(s21_decimal value) {
  s21_big_decimal value_copy = ALL_BIG_ZERO;
  value_copy.bits[0] = value.bits[0];
  value_copy.bits[1] = value.bits[1];
  value_copy.bits[2] = value.bits[2];
  value_copy.scale = s21_get_scale(value);
  if (s21_get_signed(value))
    value_copy.sign = 1;
  else
    value_copy.sign = 0;
  return value_copy;
}

int s21_normalize_bigs(s21_big_decimal* big_value_1,
                       s21_big_decimal* big_value_2) {
  int err = 0;
  if (big_value_1->scale == -1 || big_value_1->scale == -1)
    err = 1;
  else {
    while (big_value_1->scale != big_value_2->scale) {
      if (err) break;
      if (big_value_1->scale > big_value_2->scale) {
        err = s21_big_mult_ten(big_value_2);
        big_value_2->scale++;
      } else if (big_value_1->scale < big_value_2->scale) {
        err = s21_big_mult_ten(big_value_1);
        big_value_1->scale++;
      }
    }
  }
  return err;
}

int s21_big_mult_ten(s21_big_decimal* big_value) {
  int err = 0;
  s21_big_decimal value_copy_shift_3 = *big_value;
  s21_big_decimal value_copy_shift_1 = *big_value;
  s21_make_big_mantiss_zero(big_value);
  err += s21_big_to_left_shift(&value_copy_shift_3, 3);
  err += s21_big_to_left_shift(&value_copy_shift_1, 1);
  err += s21_big_simple_add(value_copy_shift_3, value_copy_shift_1, big_value);

  return err;
}

int s21_big_to_left_shift(s21_big_decimal* value,
                          int shift) {  // подумать над обработкой переполнения
  int val_1 = 0, err = 0, val_2 = 0;

  for (int j = 0; j < shift; j++) {
    for (int i = 0; i < MAX_BIG_INDEX + 1; i++) {
      val_1 = s21_big_get_bit(*value, i);
      s21_big_set_bit(value, i, val_2);
      val_2 = val_1;
    }
    // err = s21_big_get_bit(*value, MAX_BIG_INDEX+1);
    // if (err) break;
  }
  return err;
}

int s21_big_simple_add(s21_big_decimal value_1, s21_big_decimal value_2,
                       s21_big_decimal* result) {
  int sum = 0, error = 0, stock = 0;
  s21_make_big_mantiss_zero(result);

  for (int i = 0; i < MAX_BIG_INDEX + 1; i++) {
    int cur_bit_1 = s21_big_get_bit(value_1, i);
    int cur_bit_2 = s21_big_get_bit(value_2, i);
    sum = stock + cur_bit_1 + cur_bit_2;

    switch (sum) {
      case 1:
        stock = 0;
        break;
      case 2:
        stock = 1;
        sum = 0;
        break;
      case 3:
        stock = 1;
        sum = 1;
        break;
      default:
        stock = 0;
        break;
    }

    s21_big_set_bit(result, i, sum ? 1 : 0);
  }
  if (stock) error = 1;

  result->sign = value_1.sign + value_2.sign == 2 ? 1 : 0;

  return error;
}

// установка заданного бита по индексу
void s21_big_set_bit(
    s21_big_decimal* value, int index,
    int bit_value) {  // подумать над обработкой некорректного бита
  if (value != NULL && index >= 0 && index <= MAX_BIG_INDEX) {
    int mask = 0;
    mask = 0b1 << index % 32;
    int cur_bit = s21_big_get_bit(*value, index);
    if (bit_value &&
        !cur_bit) {  // если пришедший бит == 1, тот что уже установлен == 0
      value->bits[index / 32] |= mask;
    } else if (!bit_value && cur_bit) {  // если пришедший бит == 0, тот что уже
                                         // установлен == 1
      value->bits[index / 32] &= ~mask;
    }
  }
}

int s21_big_simple_sub(s21_big_decimal value_1, s21_big_decimal value_2,
                       s21_big_decimal* result) {
  s21_make_big_mantiss_zero(result);

  if (s21_big_is_equal(value_1, value_2)) return 0;

  s21_big_decimal bigger_value = ALL_BIG_ZERO;
  s21_big_decimal smaller_value = ALL_BIG_ZERO;

  if (s21_big_simple_is_greater(
          value_1, value_2)) {  // некая расстановка больших/меньших значений
    bigger_value = value_1;  // определение знака результата
    smaller_value = value_2;
    result->sign = 0;
  } else {
    bigger_value = value_2;
    smaller_value = value_1;
    result->sign = 1;
  }

  int sub = 0, error = 0;

  for (int i = 0; i < MAX_BIG_INDEX + 1; i++) {
    int cur_bit_1 = s21_big_get_bit(bigger_value, i);
    int cur_bit_2 = s21_big_get_bit(smaller_value, i);

    sub = cur_bit_1 - cur_bit_2;
    if (sub == -1) {
      s21_big_zaem(&bigger_value, i);
      sub = 1;
    }
    s21_big_set_bit(result, i, sub);
  }

  result->scale = value_1.scale;

  if (bigger_value.sign) result->sign = 1;
  return error;
}

void s21_big_zaem(s21_big_decimal* value, int index) {
  for (int i = index; i < MAX_BIG_INDEX + 1; i++) {
    if (s21_big_get_bit(*value, i)) {
      s21_big_set_bit(value, i, 0);
      break;
    } else {
      s21_big_set_bit(value, i, 1);
    }
  }
}

int s21_big_search_the_biggest(s21_big_decimal value) {
  int result = 0;

  for (int i = MAX_BIG_INDEX; i >= 0; i--) {
    if (s21_big_get_bit(value, i)) {
      result = i;
      break;
    }
  }
  return result;
}

int s21_big_convert_to_decimal(s21_big_decimal big_value, s21_decimal* value) {
  int overflow = 0, biggest_index = s21_big_search_the_biggest(big_value),
      remainder = 0, remainder_scale = 0,
      flag_to_round = 0 /*, flag_to_bank = 1*/;

  if (value != NULL) {
    s21_make_mantiss_zero(value);
    value->bits[3] = 0;
  }

  overflow = s21_check_is_greater_max(big_value);

  if (!overflow) {
    while (biggest_index > 95 || big_value.scale > 28) {
      if (big_value.scale <= 0 || overflow) {
        overflow = 1;
        break;
      }
      if (flag_to_round) {
        remainder = s21_big_div_10(&big_value) + 1;
        flag_to_round = 0;
      } else {
        remainder = s21_big_div_10(&big_value);
      }
      if (remainder > 5) flag_to_round = 1;
      big_value.scale--;
      biggest_index = s21_big_search_the_biggest(big_value);
    }

    value->bits[0] = big_value.bits[0];
    value->bits[1] = big_value.bits[1];
    value->bits[2] = big_value.bits[2];

    if (big_value.bits[3] != 0) overflow = 1;

    s21_decimal odin = {1, 0, 0, 0};
    if (remainder == 5) {
      if (s21_big_get_bit(big_value, 0) == 1 && value->bits[0] % 2 != 0)
        overflow = s21_simple_add(*value, odin, value);
    } else if (remainder > 5)
      overflow = s21_simple_add(*value, odin, value);

    s21_set_scale(value, big_value.scale);
  }

  if (!s21_is_zero_mantiss(*value)) s21_set_signed(value, big_value.sign);

  if (overflow && value) s21_make_mantiss_zero(value);

  return overflow;
}

int s21_check_is_greater_max(s21_big_decimal val) {
  int overflow = 0;
  val.sign = 0;
  s21_big_decimal max = ALL_BIG_ZERO;
  max.bits[0] = 0b11111111111111111111111111111111;
  max.bits[1] = 0b11111111111111111111111111111111;
  max.bits[2] = 0b11111111111111111111111111111111;
  s21_normalize_bigs(&max, &val);
  if (s21_big_simple_is_greater(val, max)) overflow = 1;
  return overflow;
}

int s21_big_div_10(s21_big_decimal* value_1) {
  int remainder_ = 0, err = 0;
  s21_big_decimal value_1_copy = ALL_BIG_ZERO;

  if (value_1 != NULL) {
    value_1_copy = *value_1;
    s21_make_big_mantiss_zero(value_1);
  }

  s21_big_decimal remainder = ALL_BIG_ZERO;
  s21_big_decimal divider = BIG_TEN;

  for (int i = MAX_BIG_INDEX; i >= 0; i--) {
    err = s21_big_to_left_shift(&remainder, 1);
    s21_big_set_bit(&remainder, 0, s21_big_get_bit(value_1_copy, i));
    if (s21_big_simple_is_greater_or_equel(remainder, divider)) {
      s21_big_simple_sub(remainder, divider, &remainder);
      s21_big_set_bit(value_1, i, 1);
    }
  }
  remainder_ = remainder.bits[0];
  if (err) remainder_ = 666;
  return remainder_;
}

int s21_big_simple_is_greater_or_equel(s21_big_decimal value_1,
                                       s21_big_decimal value_2) {
  return s21_big_simple_is_greater(value_1, value_2) ||
         s21_big_is_equal(value_1, value_2);
}

int s21_big_simple_is_greater(s21_big_decimal value_1,
                              s21_big_decimal value_2) {
  int res = 0;
  for (int i = MAX_BIG_INDEX; i >= 0; i--) {
    int cur_1 = s21_big_get_bit(value_1, i);
    int cur_2 = s21_big_get_bit(value_2, i);
    if (cur_1 && !cur_2) {  // если мантисса первого больше
      if (value_1.sign && value_2.sign)  // если числа отрицательные
        res = 0;  // первое меньше второго
      else        // если положительные
        res = 1;  // первое больше
      break;
    } else if (!cur_1 && cur_2) {  // если мантисса второго больше
      if (value_1.sign && value_2.sign)  // если числа отрицательные
        res = 1;                         // первое больше
      else                               // если положительные
        res = 0;                         // первое меньше
      break;
    }
  }
  return res;
}

int s21_big_is_equal(s21_big_decimal value_1, s21_big_decimal value_2) {
  int res = 1;
  for (int i = MAX_BIG_INDEX; i >= 0; i--) {
    if (s21_big_get_bit(value_1, i) != s21_big_get_bit(value_2, i)) {
      res = 0;
      break;
    }
  }
  return res;
}

void s21_make_big_mantiss_zero(s21_big_decimal* value) {
  for (int i = 0; i < 9; i++) {
    value->bits[i] = 0;
  }
}

int s21_big_get_bit(
    s21_big_decimal value,
    int index) {  // подуамть над обработкой некорректного индекса
  int mask = 0, res = 0;  // двигаем единичку в маске в нужную позицию
  if (index >= 0 && index <= MAX_BIG_INDEX) mask = 0b1 << index % 32;
  res = (int)((value.bits[index / 32] & mask) != 0 ? 1 : 0);
  return res;  // побитовое умножение. Результат какое-то число / 0
}

int s21_big_is_zero_mantissa(s21_big_decimal value) {
  int res = 1;

  for (int i = 0; i < 9; i++) {
    if (value.bits[i] != 0) {
      res = 0;
      break;
    }
  }
  return res;
}
