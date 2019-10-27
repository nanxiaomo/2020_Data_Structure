#include <stdio.h>
#include <stdlib.h>

/**
 * @description: 快速排序
 */
int midfind(int arr[], int left, int right) {
  // 低坐标,下坐标
  int mid_value;
  int low = left;
  int high = right;
  mid_value = arr[low];
  while (low < high) {
    while (low < high && arr[high] >= mid_value) high--;
    if (low < high) {
      arr[low] = arr[high];
      low++;
    }
    while (low < high && arr[low] < mid_value) low++;
    if (low < high) {
      arr[high] = arr[low];
      high--;
    }
  }
  arr[low] = mid_value;
  return low;
}

void QuickSort(int arr[], int low, int high) {
  while (low < high) {
    int mid = midfind(arr, low, high);
    QuickSort(arr, low, mid - 1);  // 递归调用
    QuickSort(arr, mid + 1, high);
  }
}

int main() {
  int arr[] = {2, 1, 3, 4, 7, 5};
  int i;
  QuickSort(arr, 0, 5);
  for (i = 0; i < 6; i++) {
    printf(" %d", arr[i]);
  }
  return 0;
}