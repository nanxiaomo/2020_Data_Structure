#include <stdio.h>

void swap(int *p1, int *p2) {
  int temp;
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}
/**
 * @description: 冒泡排序优化代码
 * @param int arr[]  需要排序的数组
 *        int n 数据的总的个数
 * @return: 空
 * @注意点：
 *     1. last 是指的最后一个排序地方
 *     2.
 * 
 * @Author: wang fei
 * @Date: 2019-10-21 18:37:58
 */
void BubbleSortEX(int arr[], int n) {
  int i, j, temp, last;
  last = n;
  while (last) {
    i = last;
    last =0;
    for (j = 1; j < i; j++) {
      if (arr[j - 1] > arr[j]) {
        last = j;
        swap(&arr[j -1], &arr[j]);
      }
    }
  }
}
int main() {
  int arr[] = {4, 7, 6, 1, 0, 3, 2, 5};
  int temp[8] = {};
  int i;
  BubbleSortEX(arr,8);
  for (i = 0; i < 8; i++) {
    printf(" %d", arr[i]);
  }
  return 0;
}