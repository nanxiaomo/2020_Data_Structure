#include <stdio.h>
#include <stdlib.h>

/**
 * @description: 希尔排序
 *  算法思想：分组插入排序
 */
void swap(int *p1, int *p2) {
  int temp;
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}
void ShellSort_Swap(int *arr[], int n) {
  // 实现分组的度量
  int gap;
  int i, j, k;
  // 最小分组量的循环
  for (gap = n / 2; gap > 0; gap /= 2) {
    // 小组内部的循环
    for (k = 0; k < gap; k++) {
      // 和插入排序一样的算法
      for (i = k + gap; i < n; i += gap) {
        // 当下一个元素小的时候，进行交换
        if (arr[i] < arr[i - gap]) {
          for (j = i; j > 0; j -= gap) {
            if (arr[j] < arr[j - gap]) {
              swap(&arr[j], &arr[j - gap]);
            }
          }
        }
      }
    }
  }
}
// 根据insert 而来的希尔排序
void ShellSort_Shift(int *arr[], int n) {
  int temp;
  int gap;
  int i, j, k;
  // 最小分组量的循环
  for (gap = n / 2; gap > 0; gap /= 2) {
    // 小组内部的循环
    for (k = 0; k < gap; k++) {
      for (i = gap; i < n; i += gap) {
        if (arr[i] < arr[i - gap]) {
          temp = arr[i];
          // 找位置
          for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap) {
            arr[j + gap] = arr[j];
          }
          //放在合适的位置
          arr[j + gap] = temp;
        }
      }
    }
  }
}
// 别人写的希尔排序 学习
// https://blog.csdn.net/MoreWindows/article/details/6668714
// 和我写的滑动排序类似
void shellsort1(int a[], int n) {
  int i, j, gap;
  for (gap = n / 2; gap > 0; gap /= 2)  //步长
    for (i = 0; i < gap; i++)           //直接插入排序
    {
      for (j = i + gap; j < n; j += gap)
        if (a[j] < a[j - gap]) {
          int temp = a[j];
          int k = j - gap;
          while (k >= 0 && a[k] > temp) {
            a[k + gap] = a[k];
            k -= gap;
          }
          a[k + gap] = temp;
        }
    }
}
void shellsort2(int a[], int n) {
  int j, gap;

  for (gap = n / 2; gap > 0; gap /= 2)
    for (j = gap; j < n; j++)  //从数组第gap个元素开始
      if (a[j] < a[j - gap])  //每个元素与自己组内的数据进行直接插入排序
      {
        int temp = a[j];
        int k = j - gap;
        while (k >= 0 && a[k] > temp) {
          a[k + gap] = a[k];
          k -= gap;
        }
        a[k + gap] = temp;
      }
}
int main() {
  int arr[] = {2, 1, 3, 4, 7, 5};
  int i;
  ShellSort_Shift(arr, 6);
  for (i = 0; i < 6; i++) {
    printf(" %d", arr[i]);
  }
  return 0;
}