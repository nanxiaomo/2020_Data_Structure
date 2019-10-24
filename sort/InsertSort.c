/*
 * @描述：插入排序
 * @算法方法:
 * 类似摸牌，放到合适的位置
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * @description: 插入排序的交换方法
 * @param int *arr[] 等待排序的数组
 *        int n
 * @return:
 * @Author: wang fei
 * @Date: 2019-10-24 16:53:52
 */

void InsertSort_Swap(int *arr[], int n) {
  int temp;
  int i, j;
  for (i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1]) {
      for (j = i; j > 0; j--) {
        if (arr[j] < arr[j - 1]) {
          temp = arr[j];
          arr[j] = arr[j - 1];
          arr[j - 1] = temp;
        }
      }
    }
  }
}
void InsertSort_Shift(int *arr[], int n) {
  int temp;
  int i, j;
  for (i = 1; i < n; i++) {
    temp = arr[i];
    if (arr[i] < arr[i - 1]) {
      temp = arr[i];
      // 找位置
      for (j = i - 1; j >= 0 && arr[j] > temp; j--){
        arr[j + 1] = arr[j];
      } 
      //放在合适的位置
      arr[j + 1] = temp;
    }
  }
}
int main() {
  int arr[] = {2, 1, 3, 4, 7, 5};
  int i;
  InsertSort_Swap(arr, 6);
  for (i = 0; i < 6; i++) {
    printf(" %d", arr[i]);
  }
  return 0;
}