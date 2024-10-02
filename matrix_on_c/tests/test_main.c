#include "test.h"

int main(void) {
  int nf = test_create_remove_main();
  printf("\n");
  nf += test_equel_main();
  printf("\n");
  nf += test_summa_main();
  printf("\n");
  nf += test_difference_main();
  printf("\n");
  nf += test_mult_main();
  printf("\n");
  nf += test_transopse_main();
  printf("\n");
  nf += test_complements_main();
  printf("\n");
  nf += test_determinant_main();
  printf("\n");
  nf += test_inverse_main();
  return nf == 0 ? 0 : 1;
}
