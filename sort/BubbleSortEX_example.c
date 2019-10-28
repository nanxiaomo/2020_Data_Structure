#include <stdio.h>
#define swap(x, y) \
  x = x ^ y;       \
  y = x ^ y;       \
  x = x ^ y;
/****************************************************
 * 冒泡排序优化算法                                        *
 ***************************************************/
void printarr(int a[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf(" %d", a[i]);
  }
  printf("\n");
}
// 稳定的排序
void bullble_optimize(int a[], int n) {
  int last = n;
  while (last) {
    int i = last;
    last = 0;
    for (int j = 1; j < i; j++) {
      if (a[j - 1] > a[j]) {
        last = j;
        swap(a[j - 1], a[j])
      }
    }
  }
}

int main() {
  int arr[] = {2, 1, 4, 3, 8, 7, 6, 9};
  int i;
  bullble_optimize(arr, 8);
  printarr(arr, 8);
  return 0;
}