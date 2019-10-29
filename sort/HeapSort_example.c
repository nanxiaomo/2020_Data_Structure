#include <malloc.h>
#include <stdio.h>
#define swap(x, y) \
  x = x ^ y;       \
  y = x ^ y;       \
  x = x ^ y;

/*********************************************************
 * heap1 借助额外数组实现排序
 * *******************************************************/
// 建堆的过程
void head_up(int p[], int add) {
  // p[0] 存储着有几个数
  int i = ++p[0];
  // p[i] 为叶节点
  // p[i/2] 为父节点
  /* 比较插入排序
  for (i = 1; i < n; i++) {
      if (arr[i] < arr[i - 1]) {
          temp = arr[i];
          // 找位置
          for (j = i - 1; j >= 0 && arr[j] > temp; j--){
              arr[j + 1] = arr[j];
          }
          //放在合适的位置
          arr[j + 1] = temp;
      }
  }*/
  for (; i > 1 && p[i / 2] > add; i /= 2) {
    p[i] = p[i / 2];
  }
  p[i] = add;
}
//  调整堆，和返回最大值的过程
int head_down(int p[]) {
  // 堆中目前最小值
  int ret = p[1];
  // 最后一个节点元素
  int last = p[p[0] - 1];
  // child 堆的叶节点
  // i 为堆的 父节点
  // i = child * 2
  int child, i;
  for (i = 1; i * 2 < p[0]; i = child) {
    child = i * 2;
    if (child + 1 < p[0] && p[child + 1] < p[child]) {
      child++;
    }
    if (last < p[child]) {
      break;
    } else {
      p[i] = p[child];
    }
  }
  p[i] = last;
  return ret;
}
void heap1(int a[], int n) {
  int *p = malloc(sizeof(int) * (n + 1));
  int p[0] = 0;
  int i;
  for (i = 0; i < n; i++) {
    head_up(p, a[i]);
  }
  for (i = 0; i < n; i++) {
    a[i] = head_dowm(p);
  }
}
int main() {
  int arr[] = {4, 7, 6, 1, 0, 3, 2, 5};
  int temp[8] = {};
  int i;
  heap1(arr, 8);
  for (i = 0; i < 8; i++) {
    printf(" %d", arr[i]);
  }
  return 0;
}