#include "str_decimal_convertors.h"

int s21_from_str_to_decimal(char* str,
                            s21_decimal* dec) {  // из строки в децимал
  int err = 0, scale = 0, lenth = 0, index = 0;

  if (!dec || !str)  // обработка корявостей (добавить корявость на слишком
                     // большую строчку)
    return err = 1;
  if (*str == '-') {
    s21_set_signed(dec, 1);  // установка знака
    str++;
  }
  char* str_copy = str;
  lenth = strlen(str);
  str_copy += lenth - 1;
  index = lenth;

  while (str_copy >= str) {
    if ((*str_copy < '0' || *str_copy > '9') && *str_copy != '.')
      return err = 2;
    if (*str_copy == '.') {
      scale = lenth - index;
      lenth--;
      index--;
      str_copy--;
    }
    s21_add_digit_to_decimal(*str_copy, dec, lenth - index);
    index--;
    str_copy--;
  }

  if (scale) s21_set_scale(dec, scale);
  return 0;
}

void s21_add_digit_to_decimal(char str, s21_decimal* dec, int index) {
  s21_decimal dec_plus = {0};
  dec_plus.bits[0] = str - '0';
  s21_decimal dec_copy = *dec;

  for (int i = 0; i < index; i++) s21_mult_10(&dec_plus);

  int err = s21_simple_add(dec_plus, dec_copy, dec);
  if (err) {
    fprintf(stderr, "OVERFLOW\n");
  }
}

// 79,228,162,514,264,337,593,543,950,335 c минусом и '.' 31 символ максимум

int s21_from_decimal_to_str(char* str,
                            s21_decimal value) {  // из децимала в строчку
  if (!str) return 1;
  static char* power_of_2[POWER_OF_TWO_ELEMENTS_QUAL] = POWER_OF_TWO;
  int lenth = 0, scale = 0;
  char str_term[MAX_CHARS_IN_STR + 1] = {'0'};
  s21_set_zero(str);
  s21_set_zero(str_term);

  for (int i = 95; i >= 0; i--) {
    if (s21_get_bit(value, i)) {
      s21_add_to_the_term(str_term, power_of_2[i]);
      s21_sum_string(str, str_term);
    }
  }
  if ((scale = s21_get_scale(value))) s21_set_point(str, scale);
  if (s21_get_signed(value)) str[0] = '-';
  s21_delete_extra_zeros(str);
  return 0;
}

void s21_set_zero(char* str) {
  int i = 0;
  while (i < MAX_CHARS_IN_STR) str[i++] = '0';
  str[MAX_CHARS_IN_STR] = '\0';
}

void s21_add_to_the_term(
    char* str_term,
    char* str_power) {  // из массива строк вставляем в слагаемое(строчку
                        // установленной формы)
  int index = strlen(str_term) - strlen(str_power);

  for (int i = 0; i < MAX_CHARS_IN_STR; i++) {
    if (i >= index)
      str_term[i] = str_power[i - index];
    else
      str_term[i] = '0';
  }
}

void s21_sum_string(
    char* str,
    char* str_term) {  // реализация сложения в столбик в 10-ой СС
  int stock = 0;
  int sum = 0;
  for (int i = MAX_CHARS_IN_STR - 1; i >= 0; i--) {  // логика суммы
    sum = (str[i] - '0') + (str_term[i] - '0') + stock;
    stock = sum >= 10 ? 1 : 0;
    str[i] = sum % 10 + '0';
  }

  if (stock)  // проверка на оверфлоу
    fprintf(stderr, "overflow!\n");
}

void s21_set_point(char* str, int scale) {
  int lenth = strlen(str);
  char buff = 0;
  for (int i = 1; i < lenth - scale; i++) str[i] = str[i + 1];
  str[lenth - scale - 1] = '.';
}

void s21_delete_extra_zeros(char* str) {
  bool is_negative = str[0] == '-' ? true : false;
  int first_before_digits_index = 0;
  for (int i = 0; i <= MAX_CHARS_IN_STR - 1; i++) {  // убираем лишние нули
    if ((str[i] == '0' || str[i] == '-') && str[i + 1] != '.' &&
        i != strlen(str) - 1)
      str[i] = ' ';
    else
      break;
    first_before_digits_index = i;
  }
  if (is_negative) str[first_before_digits_index] = '-';
}