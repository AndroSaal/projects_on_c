#include "s21_matrix.h"

// поэлементное суммирование матриц (безопасное)
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = OK;

  if ((error_code = s21_valid_matrix(A)) != OK)
    s21_print_error("sum", error_code);  // проверка на валидность первой
                                         // матрицы
  else if ((error_code = s21_valid_matrix(B)) != OK)
    s21_print_error("sum", error_code);  // проверка на валидность второй
                                         // матрицы
  else if (!result)
    s21_print_error("sum", (error_code = INCORR_MATRIX_ERROR));
  else if (A->columns != B->columns || A->rows != B->rows)
    s21_print_error(
        "sum",
        (error_code = MATH_ERROR));  // проверка на соответсвие размеров мариц
  else if ((error_code = s21_create_matrix(A->rows, A->columns, result)) != OK)
    s21_print_error("sum", error_code);  // создание и проверка его успешности
  else {  // поэлементное суммирование матриц
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
    error_code = s21_valid_matrix(result);  // проверка результата на валидность
  }

  return error_code;
}
