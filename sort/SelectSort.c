/*
 * @描述：选择排序
 * @算法方法: 
 * 未排序序列中找到最小元素，存放到排序序列的起始位置。
 */
#include <stdio.h>
#include <stdlib.h>

void SelectSort(int *arr[], int n) {
  int temp, min;
  for (int i = 0; i < n; i++) {
    min = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) {
        temp = arr[min];
        arr[min] = arr[j];
        arr[j] = temp;
      }
    }
  }
}
int main() {
  int arr[] = {2, 1};
  int i;
  SelectSort(arr, 2);
  for (i = 0; i < 2; i++) {
    printf(" %d", arr[i]);
  }
  return 0;
}
