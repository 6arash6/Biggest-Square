#include <stdio.h>
void ft_sort_int_tab(int *tab, int size);
int main(void) {
  int arr[5] = {5, 2, 4, 1, 3};
  ft_sort_int_tab(arr, 5);
  for (int i = 0; i < 5; i++)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}
