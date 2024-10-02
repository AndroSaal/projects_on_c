#include "s21_matrix.h"

int s21_calc_complements(matrix_t* A, matrix_t* result) {
  int error_code = OK;

  if ((error_code = s21_valid_matrix(A) != OK))
    s21_print_error("compl_valid_a", error_code);
  else if ((error_code = !result ? INCORR_MATRIX_ERROR : OK))
    s21_print_error("compl_valid_result", error_code);
  else if ((error_code =
                A->columns == A->rows && A->columns >= 2 ? OK : MATH_ERROR))
    s21_print_error("compl_not_kvadrat", error_code);
  else if ((error_code = s21_create_matrix(A->rows, A->columns, result)) != OK)
    s21_print_error("compl_create_res", error_code);
  else {
    matrix_t minor_matrix;
    for (int i = 0; i < A->rows && !error_code; i++) {
      for (int j = 0; j < A->columns && !error_code; j++) {
        error_code =
            s21_get_minor(A, i, j, &minor_matrix);  // вычесление минора матрицы
        if (!error_code) {
          error_code = s21_determinant(&minor_matrix, &result->matrix[i][j]);
          result->matrix[i][j] *=
              pow((double)-1,
                  (double)(i + j + 2));  // домножение его на -1 в степени
          s21_remove_matrix(&minor_matrix);
        }
      }
    }
    if ((error_code = s21_valid_matrix(result)) != OK)
      s21_print_error("compl_res_after_calc",
                      error_code);  // провверка результата
  }

  return error_code;
}
int s21_get_minor(matrix_t* A, int i, int j, matrix_t* minor_matrix) {
  int error_code = OK;

  error_code = !minor_matrix
                   ? INCORR_MATRIX_ERROR
                   : OK;  // проверка на корректность указателя на результат
  if ((error_code = !minor_matrix ? INCORR_MATRIX_ERROR : OK))
    return error_code;
  else if ((error_code = s21_valid_matrix(A)))
    return error_code;
  else if ((error_code =
                s21_create_matrix(A->rows - 1, A->columns - 1, minor_matrix)))
    return error_code;
  else {
    for (int i1 = 0; i1 < minor_matrix->rows; i1++) {
      int plus_buff_i = (i1 >= i) ? 1 : 0;
      for (int j1 = 0; j1 < minor_matrix->columns; j1++) {
        int plus_buff_j = (j1 >= j) ? 1 : 0;
        minor_matrix->matrix[i1][j1] =
            A->matrix[i1 + plus_buff_i][j1 + plus_buff_j];
      }
    }
  }
  // s21_remove_matrix(&minor_matrix);

  return error_code;
}

// void s21_calc_abs_minor(matrix_t minor_matrix, double* result) { //здесь
// приходит минор и мы считаем его определитель

//     if (minor_matrix.columns == 1 || minor_matrix.rows == 1)
//         *result = minor_matrix.matrix[0][0];
//     else {
//         int i = 1;
//         int j = 1;
//         double main_diagonal = minor_matrix.matrix[0][0];
//         double sub_diagonal = minor_matrix.matrix[minor_matrix.rows-1][0];

//         while (i < minor_matrix.rows && j < minor_matrix.columns)
//             main_diagonal *= minor_matrix.matrix[i++][j++];
//         i = minor_matrix.rows-2;
//         j = 1;
//         while (i >= 0 && j < minor_matrix.columns)
//             sub_diagonal *= minor_matrix.matrix[i--][j++];
//         *result = main_diagonal - sub_diagonal;
//     }
// }
