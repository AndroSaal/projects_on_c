#include "s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  int var_cnt = 0;
  if (s21_strchr(format, '%') != s21_NULL) {
    va_list arg;
    va_start(arg, format);
    var_cnt = processing(str, format, arg);
    va_end(arg);
  }
  return var_cnt;
}

int processing(const char *str, const char *format, va_list arg) {
  int var_cnt = 0;
  if (str[0] == '\0')
    var_cnt = -1;
  else {
    s21_size_t str_pos = 0, format_p = 0;
    int err = 0, run = 1;
    while (run && !err && format[format_p] != '\0') {
      process_cycle(str, format, arg, &var_cnt, &str_pos, &format_p, &err,
                    &run);
    }
  }
  return var_cnt;
}

void parse_token(const char *format, s21_size_t *format_p, token *tok) {
  s21_size_t width_len = 0;
  char width[256] = "\0";
  if (format[*format_p] == '*') {
    tok->star = 1;
    (*format_p)++;
  }
  while (format[*format_p] && s21_isdigit(format[*format_p])) {
    width[width_len++] = format[(*format_p)++];
  }
  width[width_len] = '\0';
  if (width_len > 0)
    tok->width = (s21_size_t)s21_atoi(width, width_len);
  else
    tok->width = -1;

  if (format[(*format_p)] && is_length(format[(*format_p)]))
    tok->length = format[(*format_p)++];
  else
    tok->length = -1;
}

void process_cycle(const char *str, const char *format, va_list arg,
                   int *var_cnt, s21_size_t *str_pos, s21_size_t *format_p,
                   int *err, int *run) {
  token tok = {-1, -1, -1, -1};
  if (format[*format_p] == '%') {
    (*format_p)++;
    parse_token(format, format_p, &tok);

    if (*str_pos >= s21_strlen(str) || str[*str_pos] == '\0') {
      if (format[*format_p] == 'n') {
        tok.spec = format[(*format_p)++];
        init_var(str_pos, str, arg, tok, var_cnt, err, run);
      } else {
        *run = 0;
      }
    } else {
      if (format[(*format_p)] && is_spec(format[(*format_p)])) {
        tok.spec = format[(*format_p)++];
        init_var(str_pos, str, arg, tok, var_cnt, err, run);
      } else {
        *err = 1;
      }
    }
  } else if (format[*format_p] && s21_isspace(format[*format_p])) {
    while (format[*format_p] && s21_isspace(format[*format_p])) (*format_p)++;
    while (str[*str_pos] && s21_isspace(str[*str_pos])) (*str_pos)++;
  } else if (format[*format_p] == str[*str_pos]) {
    (*format_p)++;
    (*str_pos)++;
  } else {
    *run = 0;
  }
}

int s21_isspace(char c) {
  return s21_strchr(" \t\n\v\f\r", c) != s21_NULL ? 1 : 0;
}

int s21_isdigit(char c) {
  char *digits = "0123456789";
  return s21_strchr(digits, c) != s21_NULL ? 1 : 0;
}

int s21_isoct(char c) {
  char *octs = "01234567";
  return s21_strchr(octs, c) != s21_NULL ? 1 : 0;
}

int s21_ishex(char c) {
  char *hexes = "0123456789ABCDEFabcdef";
  return s21_strchr(hexes, c) != s21_NULL ? 1 : 0;
}

int is_length(char c) { return c == 'l' || c == 'L' || c == 'h' ? 1 : 0; }

int is_spec(char c) {
  char *specifs = "cdieEfgGosuxXpn%%";
  return s21_strchr(specifs, c) != s21_NULL ? 1 : 0;
}

int is_spaced_string(const char *str) {
  int res = 1;
  for (s21_size_t i = 0; str[i] != '\0' && res; i++) {
    if (!s21_isspace(str[i])) res = 0;
  }
  return res;
}

long long convert_to_dec(const char *str, s21_size_t n, int base) {
  long long res = 0;
  int mul = 1;
  s21_size_t i = 0;

  // Обработка знака
  if (str[i] == '-' || str[i] == '+') {
    if (str[i] == '-') mul = -1;
    i++;
  }

  // Пропуск ведущего нуля для восьмеричной системы
  if (base == 8 && str[i] == '0') i++;

  for (; i < n && str[i] != '\0'; i++) {
    int digit = 0;

    if (s21_isdigit(str[i])) {
      digit = str[i] - '0';
    } else if (base == 16 && (str[i] >= 'A' && str[i] <= 'F')) {
      digit = str[i] - 'A' + 10;
    } else if (base == 16 && (str[i] >= 'a' && str[i] <= 'f')) {
      digit = str[i] - 'a' + 10;
    } else {
      break;  // Некорректный символ для данной системы счисления
    }

    if (digit >= base) break;

    // Проверка на переполнение
    if (res > (LLONG_MAX - digit) / base) {
      return mul == 1 ? LLONG_MAX : LLONG_MIN;
    }

    res = res * base + digit;
  }

  return res * mul;
}

long long s21_atoi(const char *str, s21_size_t n) {
  return convert_to_dec(str, n, 10);
}

long long oct_to_dec(const char *str, s21_size_t n) {
  return convert_to_dec(str, n, 8);
}

long long hex_to_dec(const char *str, s21_size_t n) {
  return convert_to_dec(str, n, 16);
}

long double s21_atold(const char *str, s21_size_t n) {
  s21_size_t i = 0;

  // Используем convert_to_dec для получения целой части числа
  long double res = (long double)convert_to_dec(str, n, 10);

  // Пропуск знака, если он был обработан в convert_to_dec
  if (str[i] == '-' || str[i] == '+') {
    i++;
  }

  // Перемещаем указатель на конец целой части числа
  while (i < n && str[i] != '.' && str[i] != 'e' && str[i] != '\0') {
    i++;
  }

  // Обработка дробной части
  if (i < n && str[i] == '.') {
    i++;
    long double fractional_part = 0.0;
    long double divisor = 1.0;
    while (i < n && str[i] != 'e' && str[i] != '\0') {
      if (!s21_isdigit(str[i])) break;
      fractional_part = fractional_part * 10 + (str[i] - '0');
      divisor *= 10;
      i++;
    }
    res += fractional_part / divisor;
  }

  // Обработка экспоненциальной части
  if (i < n && str[i] == 'e') {
    i++;
    int exp_sign = 1;
    if (str[i] == '-' || str[i] == '+') {
      if (str[i] == '-') exp_sign = -1;
      i++;
    }

    int exponent = 0;
    while (i < n && str[i] != '\0') {
      if (!s21_isdigit(str[i])) break;
      exponent = exponent * 10 + (str[i] - '0');
      i++;
    }
    res *= pow(10, exp_sign * exponent);
  }

  return res;
}

void init_var(s21_size_t *str_pos, const char *str, va_list arg, token tok,
              int *var_cnt, int *err, int *run) {
  switch (tok.spec) {
    case 'c':
      init_c(str_pos, str, arg, tok, var_cnt, err);
      break;
    case 'd':
      init_dec(str_pos, str, arg, tok, var_cnt, err, run, tok.spec == 'd');
      break;
    case 'i':
      init_i(str_pos, str, arg, tok, var_cnt, err);
      break;
    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G':
      init_e(str_pos, str, arg, tok, var_cnt, err);
      break;
    case 'o':
      init_o(str_pos, str, arg, tok, var_cnt, err);
      break;
    case 's':
      init_s(str_pos, str, arg, tok, var_cnt, err);
      break;
    case 'u':
      init_dec(str_pos, str, arg, tok, var_cnt, err, run, 0);
      break;
    case 'x':
    case 'X':
      init_x(str_pos, str, arg, tok, var_cnt, err);
      break;
    case 'p':
      init_p(str_pos, str, arg, tok, var_cnt, err);
      break;
    case 'n':
      init_n(*str_pos, arg, tok, err);
      break;
    case '%':
      init_percent(str_pos, str, tok, err, run);
      break;
    default:
      *err = 1;
      break;
  }
}

void init_c(s21_size_t *str_pos, const char *str, va_list arg, token tok,
            int *var_cnt, int *err) {
  if (tok.width >= 0 || tok.length == 'l' || tok.length == -1) {
    if (tok.star == -1 && str[*str_pos] != '\0') {
      write_c(arg, tok, *str_pos, str, var_cnt);
    }
  } else {
    *err = 1;
  }
  (*str_pos)++;
}

void init_s(s21_size_t *str_pos, const char *str, va_list arg, token tok,
            int *var_cnt, int *err) {
  if ((tok.width <= 0 && tok.width != -1) ||
      (tok.length != -1 && tok.length != 'l')) {
    *err = 1;
    return;
  }

  while (s21_isspace(str[*str_pos])) {
    (*str_pos)++;
  }

  // Считывание строки с учетом ширины и пробелов
  wchar_t buffer[256] = L"\0";
  s21_size_t s_len = 0;
  while (!s21_isspace(str[*str_pos]) && str[*str_pos] != '\0' &&
         (tok.width == -1 || s_len < (s21_size_t)tok.width)) {
    buffer[s_len++] = (wchar_t)str[*str_pos];
    (*str_pos)++;
  }

  if (tok.star == -1) {
    write_s(arg, tok, buffer, s_len, var_cnt);
  }
}

void init_dec(s21_size_t *str_pos, const char *str, va_list arg, token tok,
              int *var_cnt, int *err, int *run, int sign) {
  if ((tok.width <= 0 && tok.width != -1) ||
      (tok.length != -1 && tok.length != 'h' && tok.length != 'l'))
    *err = 1;
  else if (is_spaced_string(str) || str[0] == '\0')
    *var_cnt = -1;
  else {
    while (s21_isspace(str[*str_pos])) (*str_pos)++;

    s21_size_t s_len = 0;
    char s[50] = "\0";
    if (str[*str_pos] == '-' || str[*str_pos] == '+') {
      s[0] = str[*str_pos];
      s_len++;
      (*str_pos)++;
    }

    while (((s21_isdigit(str[*str_pos]) && str[*str_pos] != '\0') ||
            str[*str_pos] == 'i') &&
           (tok.width == -1 || s_len < (s21_size_t)tok.width)) {
      s_len++;
      s[s_len - 1] = str[*str_pos];
      (*str_pos)++;
    }
    s[s_len] = '\0';

    if (tok.star == -1 && s_len > 0) {
      s21_size_t i = 0;
      if (s[i] == '-' || s[i] == '+') i++;
      if (s[i] != '\0')
        write_dec(arg, tok, s, s_len, var_cnt, sign);
      else
        *run = 0;
    }
  }
}

// Вспомогательная функция для обработки знака
int process_sign(const char *str, s21_size_t *str_pos, char *s,
                 s21_size_t *s_len) {
  if (str[*str_pos] == '-' || str[*str_pos] == '+') {
    s[(*s_len)++] = str[*str_pos];
    (*str_pos)++;
    return 1;
  }
  return 0;
}

// Вспомогательная функция для обработки числа до запятой
void process_digits(const char *str, s21_size_t *str_pos, char *s,
                    s21_size_t *s_len, token tok) {
  while ((tok.width == -1 || *s_len < (s21_size_t)tok.width) && str[*str_pos] &&
         s21_isdigit(str[*str_pos])) {
    s[(*s_len)++] = str[*str_pos];
    (*str_pos)++;
  }
}

// Вспомогательная функция для обработки экспоненты
void process_exponent(const char *str, s21_size_t *str_pos, char *s,
                      s21_size_t *s_len, token tok) {
  if ((tok.width == -1 || *s_len < (s21_size_t)tok.width) &&
      str[*str_pos] == 'e') {
    s[(*s_len)++] = str[*str_pos];
    (*str_pos)++;
    if (str[*str_pos] == '-' || str[*str_pos] == '+') {
      s[(*s_len)++] = str[*str_pos];
      (*str_pos)++;
    }
    while ((tok.width == -1 || *s_len < (s21_size_t)tok.width) &&
           str[*str_pos] && s21_isdigit(str[*str_pos])) {
      s[(*s_len)++] = str[*str_pos];
      (*str_pos)++;
    }
  }
}

void init_e_num(s21_size_t *str_pos, const char *str, va_list arg, token tok,
                int *var_cnt, char *s, s21_size_t *s_len, int *sign_flag) {
  process_digits(str, str_pos, s, s_len, tok);

  // Обработка дробной части числа
  if ((tok.width == -1 || *s_len < (s21_size_t)tok.width) &&
      str[*str_pos] == '.') {
    if (!(*s_len) && str[(*str_pos) + 1] && s21_isdigit(str[(*str_pos) + 1])) {
      s[(*s_len)++] = '0';
      if (tok.width != -1) tok.width++;
    }
    do {
      s[(*s_len)++] = str[*str_pos];
      (*str_pos)++;
    } while ((tok.width == -1 || *s_len < (s21_size_t)tok.width) &&
             str[*str_pos] && s21_isdigit(str[*str_pos]));
  }

  // Обработка экспоненты
  process_exponent(str, str_pos, s, s_len, tok);

  if (tok.star == -1 && *s_len > (s21_size_t)(*sign_flag) &&
      !(s[0] == '.' || s[0] == 'e' ||
        ((s[0] == '+' || s[0] == '-') && (s[1] == '.' || s[1] == 'e')))) {
    write_float(arg, tok, s, *s_len, var_cnt);
  }
}

void init_e(s21_size_t *str_pos, const char *str, va_list arg, token tok,
            int *var_cnt, int *err) {
  int sign_flag = 0;
  if ((tok.width <= 0 && tok.width != -1) ||
      (tok.length != 'L' && tok.length != -1 && tok.length != 'l')) {
    *err = 1;
  } else if (is_spaced_string(str) || str[0] == '\0') {
    *var_cnt = -1;
  } else {
    while (str[*str_pos] && s21_isspace(str[*str_pos])) (*str_pos)++;
    s21_size_t s_len = 0;
    char s[500] = "\0";

    sign_flag = process_sign(str, str_pos, s, &s_len);

    // Проверка на специальные значения inf и nan
    if ((3 <= tok.width || tok.width == -1) && str[*str_pos] != '\0' &&
        str[*str_pos + 1] != '\0' && str[*str_pos + 2] != '\0' &&
        s21_strchr("iI", str[*str_pos]) != s21_NULL &&
        s21_strchr("nN", str[*str_pos + 1]) != s21_NULL &&
        s21_strchr("fF", str[*str_pos + 2]) != s21_NULL) {  // inf
      (*str_pos) += 3;
      if (tok.star == -1) {
        write_inf(arg, tok, var_cnt, (s[0] == '-') ? -1 : 1);
      }
    } else if ((3 <= tok.width || tok.width == -1) && str[*str_pos] != '\0' &&
               str[*str_pos + 1] != '\0' && str[*str_pos + 2] != '\0' &&
               s21_strchr("nN", str[*str_pos]) != s21_NULL &&
               s21_strchr("aA", str[*str_pos + 1]) != s21_NULL &&
               s21_strchr("nN", str[*str_pos + 2]) != s21_NULL) {  // nan
      (*str_pos) += 3;
      if (tok.star == -1) {
        write_nan(arg, tok, var_cnt);
      }
    } else {
      init_e_num(str_pos, str, arg, tok, var_cnt, s, &s_len, &sign_flag);
    }
  }
}

void init_i(s21_size_t *str_pos, const char *str, va_list arg, token tok,
            int *var_cnt, int *err) {
  int sign_flag = 0;
  if ((tok.width <= 0 && tok.width != -1) ||
      (tok.length != -1 && tok.length != 'h' && tok.length != 'l'))
    *err = 1;
  else if (is_spaced_string(str) || str[0] == '\0')
    *var_cnt = -1;
  else {
    while (s21_isspace(str[*str_pos])) (*str_pos)++;

    s21_size_t s_len = 0;
    char s[50] = "\0";
    if (str[*str_pos] == '-' || str[*str_pos] == '+') {
      s[0] = str[*str_pos];
      s_len++;
      (*str_pos)++;
      sign_flag = 1;
    }
    int ss = 10;
    if (str[*str_pos] == '0' && tok.width != 1) {  // oct or hex or zero
      (*str_pos)++;
      if (str[*str_pos] && s21_isdigit(str[*str_pos])) {
        if (tok.width != -1) tok.width--;
        ss = 8;
      } else if (str[*str_pos] &&
                 (str[*str_pos] == 'x' || str[*str_pos] == 'X')) {
        (*str_pos)++;
        if (tok.width != -1) tok.width -= 2;
        ss = 16;
      } else {
        s[s_len++] = '0';
      }
    }
    while (str[*str_pos] &&
           ((ss == 10 && s21_isdigit(str[*str_pos])) ||
            (ss == 8 && s21_isoct(str[*str_pos])) ||
            (ss == 16 && s21_ishex(str[*str_pos]))) &&
           (tok.width == -1 || s_len < (s21_size_t)tok.width)) {
      s_len++;
      s[s_len - 1] = str[*str_pos];
      (*str_pos)++;
    }
    s[s_len] = '\0';
    if (tok.star == -1 && s_len > 0) {
      if (ss == 10 && ((s_len > 0 && !sign_flag) || (s_len > 1 && sign_flag)))
        write_dec(arg, tok, s, s_len, var_cnt, 1);
      else if (ss == 8)
        write_oct(arg, tok, s, s_len, var_cnt, 1);
      else if (ss == 16)
        write_hex(arg, tok, s, s_len, var_cnt, 1);
    }
  }
}

void init_o(s21_size_t *str_pos, const char *str, va_list arg, token tok,
            int *var_cnt,
            int *err) {  // Беззнаковое восьмеричное число
  int prefix_flag = 0;
  int sign_flag = 0;
  if ((tok.width <= 0 && tok.width != -1) ||
      (tok.length != -1 && tok.length != 'h' && tok.length != 'l'))
    *err = 1;
  else if (is_spaced_string(str) || str[0] == '\0')
    *var_cnt = -1;
  else {
    while (s21_isspace(str[*str_pos])) (*str_pos)++;

    s21_size_t s_len = 0;
    char s[50] = "\0";
    if (str[*str_pos] == '-' || str[*str_pos] == '+') {
      s[s_len++] = str[(*str_pos)++];
      sign_flag = 1;
    }
    if (str[*str_pos] == '0' &&
        (tok.width == -1 || s_len < (s21_size_t)tok.width)) {
      prefix_flag = 1;
    }
    while (str[*str_pos] && s21_isoct(str[*str_pos]) &&
           (tok.width == -1 || s_len < (s21_size_t)tok.width)) {
      s_len++;
      s[s_len - 1] = str[*str_pos];
      (*str_pos)++;
    }
    s[s_len] = '\0';
    if (tok.star == -1 && (s_len > (s21_size_t)sign_flag) &&
        (tok.width > prefix_flag || tok.width == -1)) {
      write_oct(arg, tok, s, s_len, var_cnt, 0);
    }
  }
}

void init_x(s21_size_t *str_pos, const char *str, va_list arg, token tok,
            int *var_cnt,
            int *err) {  // Беззнаковое шестнадцатеричное целое число
                         // (заглавные либо строчные буквы, без разницы)
  int prefix_flag = 0;
  int sign_flag = 0;
  if ((tok.width <= 0 && tok.width != -1) ||
      (tok.length != -1 && tok.length != 'h' && tok.length != 'l'))
    *err = 1;
  else if (is_spaced_string(str) || str[0] == '\0')
    *var_cnt = -1;
  else {
    while (s21_isspace(str[*str_pos])) (*str_pos)++;

    s21_size_t s_len = 0;
    char s[50] = "\0";
    if (str[*str_pos] == '-' || str[*str_pos] == '+') {
      s[0] = str[*str_pos];
      s_len++;
      (*str_pos)++;
      sign_flag = 1;
    }

    if (str[*str_pos] == '0' &&
        (str[*str_pos + 1] == 'x' || str[*str_pos + 1] == 'X')) {
      tok.width -= 2;
      (*str_pos) += 2;
      prefix_flag = 1;
    }

    while ((tok.width == -1 || s_len < (s21_size_t)tok.width) &&
           str[*str_pos] && s21_ishex(str[*str_pos])) {
      s_len++;
      s[s_len - 1] = str[*str_pos];
      (*str_pos)++;
    }
    s[s_len] = '\0';

    if (tok.star == -1 && (s_len > (s21_size_t)sign_flag || prefix_flag)) {
      write_hex(arg, tok, s, s_len, var_cnt, 0);
    }
  }
}

void init_p(s21_size_t *str_pos, const char *str, va_list arg, token tok,
            int *var_cnt, int *err) {  // Адрес указателя
  if ((tok.width <= 0 && tok.width != -1) || tok.length != -1)
    *err = 1;
  else if (is_spaced_string(str) || str[0] == '\0')
    *var_cnt = -1;
  else {
    while (s21_isspace(str[*str_pos])) (*str_pos)++;

    s21_size_t s_len = 0;
    char s[MAX_PTR_LENGTH] = "\0";

    if (str[*str_pos] == '0' &&
        (str[*str_pos + 1] == 'x' || str[*str_pos + 1] == 'X')) {
      if (tok.width != -1) tok.width -= 2;
      (*str_pos) += 2;
    }
    while (str[*str_pos] && s21_ishex(str[*str_pos]) &&
           (tok.width == -1 || s_len < (s21_size_t)tok.width) &&
           s_len < MAX_PTR_LENGTH - 1) {
      s[s_len++] = str[(*str_pos)++];
    }
    s[s_len] = '\0';

    if (tok.star == -1 && s_len > 0) {
      write_ptr(arg, s, s_len);
    }
    (*var_cnt)++;
  }
}

void init_n(int str_pos, va_list arg, token tok,
            int *err) {  // Количество символов до %n
  if (tok.width != -1 ||
      (tok.length != 'l' && tok.length != 'h' && tok.length != -1))
    *err = 1;
  else {
    if (tok.star == -1) {
      write_n(arg, tok, str_pos);
    }
  }
}

void init_percent(s21_size_t *str_pos, const char *str, token tok, int *err,
                  int *run) {  // Символ %
  if (tok.star != -1 || tok.width != -1 || tok.length != -1) {
    *err = 1;
  } else {
    while (s21_isspace(str[*str_pos])) {
      (*str_pos)++;
    }
    if (str[*str_pos] == '%') {
      (*str_pos)++;
    } else {
      *run = 1;
    }
  }
}

void write_number(void *var, token tok, long long res, int sign) {
  if (sign) {
    switch (tok.length) {
      case 'h':
        *((short int *)var) = (short int)res;
        break;
      case 'l':
        *((long long *)var) = (long long)res;
        break;
      default:
        *((int *)var) = (int)res;
        break;
    }
  } else {
    switch (tok.length) {
      case 'h':
        *((unsigned short int *)var) = (unsigned short int)res;
        break;
      case 'l':
        *((unsigned long long *)var) = (unsigned long long)res;
        break;
      default:
        *((unsigned int *)var) = (unsigned int)res;
        break;
    }
  }
}

void set_float_value(void *var, token tok, long double value) {
  if (tok.length == 'L') {  // long double
    *((long double *)var) = value;
  } else if (tok.length == 'l') {  // double
    *((double *)var) = (double)value;
  } else {  // float
    *((float *)var) = (float)value;
  }
}

void write_c(va_list arg, token tok, int str_pos, const char *str,
             int *var_cnt) {
  void *var = va_arg(arg, void *);

  if (tok.length == 'l') {
    *((wchar_t *)var) = (wchar_t)str[str_pos];
  } else if (tok.length == -1) {
    *((char *)var) = (char)str[str_pos];
  }

  (*var_cnt)++;
}

void write_s(va_list arg, token tok, wchar_t *s, s21_size_t s_len,
             int *var_cnt) {
  void *var = va_arg(arg, void *);

  if (tok.length == 'l') {
    for (s21_size_t i = 0; i < s_len; i++) {
      ((wchar_t *)var)[i] = s[i];
    }
    ((wchar_t *)var)[s_len] = L'\0';
  } else {
    for (s21_size_t i = 0; i < s_len; i++) {
      ((char *)var)[i] = (char)s[i];
    }
    ((char *)var)[s_len] = '\0';
  }

  (*var_cnt)++;
}

void write_dec(va_list arg, token tok, char *s, s21_size_t s_len, int *var_cnt,
               int sign) {
  void *var = va_arg(arg, void *);
  long long res = s21_atoi(s, s_len);
  write_number(var, tok, res, sign);
  (*var_cnt)++;
}

void write_inf(va_list arg, token tok, int *var_cnt, int sign) {
  void *var = va_arg(arg, void *);
  set_float_value(var, tok, (long double)INFINITY * sign);
  (*var_cnt)++;
}

void write_nan(va_list arg, token tok, int *var_cnt) {
  void *var = va_arg(arg, void *);
  set_float_value(var, tok, (long double)nan(""));
  (*var_cnt)++;
}

void write_float(va_list arg, token tok, char *s, s21_size_t s_len,
                 int *var_cnt) {
  void *var = va_arg(arg, void *);
  set_float_value(var, tok, s21_atold(s, s_len));
  (*var_cnt)++;
}

void write_oct(va_list arg, token tok, char *s, s21_size_t s_len, int *var_cnt,
               int sign) {
  void *var = va_arg(arg, void *);
  long long res = oct_to_dec(s, s_len);
  write_number(var, tok, res, sign);
  (*var_cnt)++;
}

void write_hex(va_list arg, token tok, char *s, s21_size_t s_len, int *var_cnt,
               int sign) {
  void *var = va_arg(arg, void *);
  long long res = hex_to_dec(s, s_len);
  write_number(var, tok, res, sign);
  (*var_cnt)++;
}

void write_ptr(va_list arg, char *s, s21_size_t s_len) {
  void **var = va_arg(arg, void **);
  long long res = hex_to_dec(s, s_len);
  *var = (void *)(res);
}

void write_n(va_list arg, token tok, int str_pos) {
  void *var = va_arg(arg, void *);
  write_number(var, tok, (long long)str_pos, 1);
}