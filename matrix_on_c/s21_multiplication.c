#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error_code = OK;

  if ((error_code = (!result ? INCORR_MATRIX_ERROR : OK)))
    s21_print_error(
        "mult_n_result_null",
        error_code);  // проверка на валидность указателя на результат
  else if ((error_code = s21_valid_matrix(A)) != OK)
    s21_print_error("mult_n_valid_param",
                    error_code);  // проверка на валидность первой матрицы
  else if ((error_code = s21_create_matrix(A->rows, A->columns, result)) != OK)
    s21_print_error("mult_n_create",
                    error_code);  // создание и проверка его успешности
  else if ((error_code = (isinf(number) || isnan(number)) ? MATH_ERROR : OK))
    s21_print_error("mult_n_number",
                    error_code);  // проверка на валидность числа
  else {  // поэлементное умножение матрицы на число
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] * number;
    }
    error_code = s21_valid_matrix(result);  // проверка результата на валидность
  }

  return error_code;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = OK;

  if ((error_code = s21_valid_matrix(A)) != OK)
    s21_print_error("mult_m_non_valid_A",
                    error_code);  // проверка на валидность первой матрицы
  else if ((error_code = s21_valid_matrix(B)) != OK)
    s21_print_error("mult_m_non_valid_A",
                    error_code);  // проверка на валидность второй матрицы
  else if (!result)
    s21_print_error(
        "mult_m_null_res",
        (error_code = INCORR_MATRIX_ERROR));  // проверка результата на null
  else if (A->columns != B->rows)
    s21_print_error(
        "mult_m_sizes",
        (error_code = MATH_ERROR));  // проверка на соответсвие размеров мариц
  else if ((error_code = s21_create_matrix(A->rows, B->columns, result)) != OK)
    s21_print_error("mult_m_creation",
                    error_code);  // создание и проверка его успешности
  else {                          // умножение матриц
    for (int i = 0; i < result->rows;
         i++) {  // столбцы в результат берём из A-матрицы
      for (int j = 0; j < result->columns;
           j++) {  // строчки в результат берём из B-матрицы
        result->matrix[i][j] = 0;
        for (int k = 0; k < A->columns; k++)
          result->matrix[i][j] +=
              A->matrix[i][k] *
              B->matrix[k][j];  // суммируем по k элементы двух матриц
      }
    }
    if ((error_code = s21_valid_matrix(result)) != OK)
      s21_print_error("mult_m_incor_res",
                      error_code);  // проверка на валидность result-матрицы
  }

  return error_code;
}
