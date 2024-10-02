#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int error_code = OK;

  if ((error_code = s21_valid_matrix(A) != OK))
    s21_print_error("detemrm_valid_a", error_code);
  else if ((error_code = !result ? INCORR_MATRIX_ERROR : OK))
    s21_print_error("determ_valid_result", error_code);
  else if ((error_code = A->columns == A->rows ? OK : MATH_ERROR))
    s21_print_error("determ_not_kvadrat", error_code);
  else {
    int sign = 1;
    *result = 0;
    if (A->columns == 1)
      *result = A->matrix[0][0];
    else {
      for (int i = 0; i < A->columns && !error_code; i++) {
        matrix_t minor_matrix;
        double buff = 0;
        error_code = s21_get_minor(A, 0, i, &minor_matrix);
        if (!error_code) {
          error_code = s21_determinant(&minor_matrix, &buff);
          *result += sign * A->matrix[0][i] * buff;
          sign *= -1;
          s21_remove_matrix(&minor_matrix);
        }
      }
    }
    error_code = isnan(*result) || isinf(*result) ? MATH_ERROR : OK;
  }
  return error_code;
}
