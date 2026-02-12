#include <stdio.h>
void ft_div_mod(int a, int b, int *div, int *mod);
int main(void) {
  int div = 0, mod = 0;
  ft_div_mod(10, 3, &div, &mod);
  printf("%d %d\n", div, mod);
  return 0;
}
