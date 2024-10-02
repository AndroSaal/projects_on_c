#ifndef TEST_H
#define TEST_H

#include <check.h>

#include "../s21_matrix.h"

/// @brief мейн функции теста создания и удаления матрицы
/// @return кол-во ошибок
int test_create_remove_main(void);
/// @brief мейн функции теста сравнения
/// @return кол-во ошибок
int test_equel_main(void);
/// @brief мейн функции теста суммирования матриц
/// @return кол-во ошибок
int test_summa_main(void);
/// @brief мейн функции теста нахождения разницы матриц
/// @return код ошибки
int test_difference_main(void);
/// @brief мейн функции теста нахождения произведения
/// @return кол-во ошибок
int test_mult_main(void);
/// @brief тестирование транспонирования
/// @return кол-во ошибок
int test_transopse_main(void);
/// @brief тестирование вычисления матрицы алгеброических дополнений
/// @return кол-во ошибок
int test_complements_main(void);
/// @brief тестирование вычисления определителя матрицы
/// @return кол-во ошибок
int test_determinant_main(void);
/// @brief тестирование вычисления обратной матрицы
/// @return кол-во ошибок
int test_inverse_main(void);

#endif
