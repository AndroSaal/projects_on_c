#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error_code = OK;

  if ((error_code = s21_valid_matrix(A) != OK))
    s21_print_error("transpone_valid_a", error_code);
  else if ((error_code = !result ? INCORR_MATRIX_ERROR : OK))
    s21_print_error("transpone_valid_result", error_code);
  else if ((error_code = s21_create_matrix(A->columns, A->rows, result)) != OK)
    s21_print_error("transpone_create_res", error_code);
  else {
    int rows = A->rows;
    int columns = A->columns;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
    result->rows = columns;
    result->columns = rows;
  }

  return error_code;
}
