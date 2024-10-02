#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error_code = OK;
  // проверки на корректность входных данных
  if ((error_code = s21_valid_matrix(A) != OK))
    s21_print_error("inverse_valid_a", error_code);
  else if ((error_code = !result ? INCORR_MATRIX_ERROR : OK))
    s21_print_error("inverse_valid_result", error_code);
  else if ((error_code = A->columns == A->rows ? OK : MATH_ERROR))
    s21_print_error("inverse_not_kvadrat", error_code);
  else {
    double determinant = 0;
    error_code = s21_determinant(A, &determinant);
    if (determinant && !isnan(determinant) &&
        !isinf(determinant)) {  // проверка на существование матрицы
      if (A->rows == 1) {
        error_code = s21_create_matrix(1, 1, result);
        if (!error_code) result->matrix[0][0] = 1.0 / fabs(determinant);
      }  // елчи матрица 1 на 1
      // error_code = s21_mult_number(A, 1.0/fabs(determinant), result);
      else {  // если не 1 на 1
        matrix_t B, C;  // матрица алгеброических дополнений
        error_code = s21_calc_complements(A, &B);
        if (error_code == OK) {
          error_code = s21_transpose(&B, &C);
          if (!error_code)
            error_code =
                s21_mult_number(&C, 1.0 / determinant,
                                result);  // вычисление обратной матрицы
          s21_remove_matrix(&C);  // очистка
        }
        s21_remove_matrix(&B);  // очистка
      }
    } else
      error_code = MATH_ERROR;
  }

  return error_code;
}
