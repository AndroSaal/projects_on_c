#ifndef S21_STRING_H
#define S21_STRING_H

// common part
#define s21_size_t unsigned long long
#define s21_NULL (void *)0

// betseybe 1, 2, 3, 4, 10
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strerror(int errnum);

// bespinpa 5, 6, 7, 8, 9 + c#-funcs
char *s21_strchr(const char *str, int c);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
char *s21_strcat(char *s, const char *append);
int s21_strcmp(const char *str1, const char *str2);
char *s21_strcpy(char *dest, const char *src);

// mathewal 11, 12, 13, 14, 15
s21_size_t s21_strlen(const char *string);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

// s21_sprintf
#include <math.h>    //для научной нотации
#include <stdarg.h>  //библиотека Variable Arguments - переменного числа аргументов в функци
#include <stdbool.h>  //для flse/true/bool
#include <stdlib.h>  //для динамического выделения памяти

// общий(полный) вид спецификатора:
//%[флаги][ширина].[точность][модификаторы(длина)][тип
// преобразования(спецификатор)]
typedef struct output_specs {
  // 1) флгаи
  bool minus;  // -
  bool plus;   // +
  bool space;  // (побел)
  bool sharp;  // #
  bool zero;   // 0
  // 2) ширина
  s21_size_t width;      // ширина
  bool width_from_args;  // если вместо ширины идет *
  // 3) точность
  bool has_accuracy;        // есть ли точность
  s21_size_t accuracy;      // точность
  bool accuracy_from_args;  // если вместо точности идет *
  // 4) модификаторы
  bool h;  // short (для i, d, o, u, x и X)
  bool l;  // long (для i, d, o, u, x и X) и c, s
  bool L;  // long (e, E, f, g, G)
  // 5) спецификаторы
  char spec;             // один из 16-и
  int base_of_notation;  // система счисления
  int pow_val;
  // bool upper_case; //
  // bool g_spec;
  // bool e_spec;

} output_specs;

/// @brief ползовательский sprintf
/// @param str исходный массив-источник - куда вписываем
/// @param format форматная строка - что вписываем
/// @param params изменяемое число аргументов - спецификаторы, ширина, и тд. в
/// форматную строку
/// @return возвращает кол-во действительно вписанных символов
int s21_sprintf(char *str, const char *format, ...);
/// @brief парсер форматной строки
/// @param format форматная строка
/// @param args указатель на va_list со всеми специми ширириной и тд
/// @return экземпляр структуры с указанием аргументов из форматной строки
output_specs format_string_parser(const char **format, va_list *args);
/// @brief получение флагов из форматной строки
/// @param specs указатель на структуру, куда вписываем полученные флаги
/// @param format форматная строка
void get_flags(output_specs *specs, const char **format);
/// @brief получение ширины из форматной строки
/// @param specs указатель на структуру, куда вписываем полученную ширину
/// @param format форматная строка
void get_width(output_specs *specs, const char **format);
/// @brief получение точности из форматной строки
/// @param specs указатель на структуру, куда вписываем полученную точность
/// @param format форматная строка
void get_accurency(output_specs *specs, const char **format);
/// @brief получение длины из форматной строки
/// @param specs указатель на структуру, куда вписываем полученную длину
/// @param format форматная строка
void get_lenth(output_specs *specs, const char **format);
/// @brief вписывание спецификатора и его параметров в str
/// @param str исходник, массив, куда записываем
/// @param specs структура с спекой и информацией о ней
/// @param arguments переменное кол-во аргументов
/// @param str_start указатель на начальный адресс str
/// @return адресс последнего вписанного символа в str
char *input_arg_in_str(char **str, output_specs *specs, va_list *arguments,
                       char *str_start);
/// @brief обоработка десятичных целых чисел (i, d)
/// @param str исходный массив
/// @param specs указатель на структуру со спеками и информации о них
/// @param arguments
/// @return адрес последнего вставленного в массив символа
char *input_decimal(char **str, output_specs *specs, va_list *arguments);
/// @brief получение веса в байтах целого числа
/// @param num число
/// @param specs указатель на структуру со спеками и информации о них
/// @return "вес"
s21_size_t get_weight_of_number(long int num, output_specs *specs);
/// @brief преобразование числа в символы и помещение их в str_number_buff
/// @param str_number_buff число в символах
/// @param num исходное число
/// @param specs указатель на структуру со спеками и информации о них
/// @return адресс последнего вписанного символа
char *fill_buff_with_number(char *str_number_buff, long num,
                            output_specs *specs);
char *put_char_of_sign(char *str, output_specs *specs, bool is_negative);
char *put_number(char *str, long num, output_specs *specs);
s21_size_t get_digits_quality(long num);
char *put_spaces_with_minus(char *str);
char *put_spaces_without_minus(char *str, output_specs *specs, bool minus,
                               long integer_part_of_num);
// float --> f
char *input_float(char **str, output_specs *specs, va_list *arguments);
void fill_buff_with_float_number(output_specs *specs, char *buff,
                                 long double num);
char *put_float_number(char *buff, long double num, output_specs *specs);
s21_size_t get_weight_of_float_number(long double num, output_specs *specs);
char *put_float_width_without_minus(char *str, output_specs *specs,
                                    bool is_negative, long num);
// char  --> c
char *input_char(char **str, output_specs *specs, va_list *arguments);
char *put_symbol(char **str, int symbol);
char *fill_the_width_for_char(char **str, output_specs *specs);
// u, o, X, x
char *input_unsigned(char **str, output_specs *specs, va_list *arguments);
s21_size_t get_weight_of_unsigned_number(unsigned long int num,
                                         output_specs *specs);
s21_size_t get_dif_notation_digits_quality(unsigned long int num, int base);
void fill_buff_with_unsigned_number(output_specs *specs, char *buff,
                                    unsigned long num);
char *put_unsigned_number(char *buff, unsigned long num, output_specs *specs);
// string --> s
char *input_string(char *str, output_specs *specs, va_list *arguments);
char *put_string_to_str(char *str, char *str_to_input, output_specs *specs);
char *put_width_with_string(char *str, char *str_to_string,
                            output_specs *specs);
// science notation --> e, E
char *input_scientific_notation(char **str, output_specs *specs,
                                va_list *arguments);
s21_size_t get_weight_of_e_number(output_specs *specs, long double num);
char *put_linter(char *buff, output_specs *specs);
long double get_power_and_mantissa(long double num, output_specs *specs);
// shortest notation --> g, G
char *input_shortest_record(char **str, output_specs *specs,
                            va_list *arguments);
s21_size_t get_weight_from_shortest(output_specs *specs, s21_size_t acc,
                                    bool is_negative, long double num,
                                    long double num_cpy);

// real printed symbols --> n
void input_quality(va_list *arguments, char *str_start);

// noonmago sscanf scope
#include <limits.h>
#include <stdint.h>
#define MAX_PTR_LENGTH 50

typedef struct token {
  int star, length, spec;
  long int width;
} token;

int s21_sscanf(const char *str, const char *format, ...);
int processing(const char *str, const char *format, va_list arg);
void parse_token(const char *format, s21_size_t *format_p, token *tok);
void process_cycle(const char *str, const char *format, va_list arg,
                   int *var_cnt, s21_size_t *str_pos, s21_size_t *format_p,
                   int *err, int *run);

int s21_isspace(char c);
int s21_isdigit(char c);
int s21_isoct(char c);
int s21_ishex(char c);
int is_length(char c);
int is_spec(char c);
int is_spaced_string(const char *str);

void init_var(s21_size_t *str_p, const char *str, va_list arg, token tok,
              int *var_cnt, int *err, int *run);

long long convert_to_dec(const char *str, s21_size_t n, int base);
long long s21_atoi(const char *str, s21_size_t n);
long double s21_atold(const char *str, s21_size_t n);
long long oct_to_dec(const char *str, s21_size_t n);
long long hex_to_dec(const char *str, s21_size_t n);

void init_c(s21_size_t *str_p, const char *str, va_list arg, token tok,
            int *var_cnt, int *err);
void init_s(s21_size_t *str_p, const char *str, va_list arg, token tok,
            int *var_cnt, int *err);
void init_dec(s21_size_t *str_p, const char *str, va_list arg, token tok,
              int *var_cnt, int *err, int *run, int sign);
void init_e_num(s21_size_t *str_p, const char *str, va_list arg, token tok,
                int *var_cnt, char *s, s21_size_t *s_len, int *sign_flag);
void init_e(s21_size_t *str_p, const char *str, va_list arg, token tok,
            int *var_cnt, int *err);
void init_i(s21_size_t *str_p, const char *str, va_list arg, token tok,
            int *var_cnt, int *err);
void init_o(s21_size_t *str_p, const char *str, va_list arg, token tok,
            int *var_cnt, int *err);
void init_x(s21_size_t *str_p, const char *str, va_list arg, token tok,
            int *var_cnt, int *err);
void init_p(s21_size_t *str_p, const char *str, va_list arg, token tok,
            int *var_cnt, int *err);
void init_n(int str_p, va_list arg, token tok, int *err);
void init_percent(s21_size_t *str_p, const char *str, token tok, int *err,
                  int *run);

void set_float_value(void *var, token tok, long double value);
void write_number(void *var, token tok, long long res, int sign);
void write_c(va_list arg, token tok, int str_p, const char *str, int *var_cnt);
void write_inf(va_list arg, token tok, int *var_cnt, int sign);
void write_nan(va_list arg, token tok, int *var_cnt);
void write_float(va_list arg, token tok, char *s, s21_size_t s_len,
                 int *var_cnt);
void write_s(va_list arg, token tok, wchar_t *s, s21_size_t s_len,
             int *var_cnt);
void write_dec(va_list arg, token tok, char *s, s21_size_t s_len, int *var_cnt,
               int sign);
void write_oct(va_list arg, token tok, char *s, s21_size_t s_len, int *var_cnt,
               int sign);
void write_hex(va_list arg, token tok, char *s, s21_size_t s_len, int *var_cnt,
               int sign);
void write_ptr(va_list arg, char *s, s21_size_t s_len);
void write_n(va_list arg, token tok, const int str_p);

#endif