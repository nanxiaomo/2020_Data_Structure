#include <stdio.h>
/**
 * @description: 查找数组中个数过半的元素
 * @param  int *arr 待查找的数组；
 *         int arr_size 数组元素的个数，从1开始
 * @return: 个数过半的元素的值
 * @note：
 * 先设各个元素个数为1,循环过程中元素与当前元素相同，个数加1，否则个数减1；
 *         计算复杂度  o(n)
 *         空间复杂度  o(2)
 * @Author: wang fei
 * @Date: 2019-10-23 22:05:55
 */
int marityElmennt(int *arr, int arr_size) {
  int marityIndex;
  int count = 0;
  for (int i = 0; i < arr_size; i++) {
    if (count == 0) {
      marityIndex = i;
      count = 1;
    } else {
      if (arr[marityIndex] == arr[i]) {
        count++;
      } else {
        count--;
      }
    }
  }
  if (count > 0) {
    return arr[marityIndex];
  } else {
    return -1;
  }
}

int main(void) {
  int arr[9] = {1, 2, 4, 3, 4, 6, 6, 5, 4};
  printf("%d\n", marityElmennt(arr, 9));
  return 1;
}