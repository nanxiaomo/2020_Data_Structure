#include <malloc.h>
#include <stdio.h>
#define swap(x, y) \
  x = x ^ y;       \
  y = x ^ y;       \
  x = x ^ y;

void printarr(int a[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf(" %d", a[i]);
  }
  printf("\n");
}

/*********************************************************
 * heap1 借助额外数组实现排序
 * *******************************************************/
// 建堆的过程
void heap1_up(int p[], int add) {
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
int heap1_down(int p[]) {
  // 堆中目前最小值
  int ret = p[1];
  // 最后一个节点元素
  int last = p[p[0]--];
  // child 堆的叶节点
  // i 为堆的 父节点
  // i = child * 2
  int child, i;
  for (i = 1; i * 2 < p[0]; i = child) {
    child = i * 2;
    if (child + 1 <= p[0] && p[child + 1] < p[child]) {
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
  int *p = (int *)malloc(sizeof(int) * (n + 1));
  p[0] = 0;
  int i;
  for (i = 0; i < n; i++) {
    heap1_up(p, a[i]);
    printarr(p, i+1);
  }
  for (i = 0; i < n; i++) {
    a[i] = heap1_down(p);
    printarr(a, n);
  }
}
/***********************************************************************
 * 借助自身数组完成推排序
 * ********************************************************************/
// 建堆
void heap2_up(int a[], int idx) {
  int i = idx;
  int add = a[idx];
  for (; i&& add>a[(i-1)/2] ; i= (i-1)/2) {
    a[i]= a[(i-1)/2];
  }
  a[i] = add;
}
// 堆调整
int heap2_down(int a[], int last) {
  int curr = a[last];
  swap(a[0], a[last]);
  int i,child;
  for (i = 0; i*2 + 1 < last; i = child) {
    child = i*2 + 1;  // 左节点
    if (child + 1 < last && a[child] < a[child + 1]) {
      child++;
    }
    if (curr > a[child]) {
      break;
    } else {
      a[i] = a[child];
    }
  }
  a[i] = curr;
}
// 堆排序
int heap2(int a[], int n) {
  int i;
  for (i = 1; i < n; i++) {
    heap2_up(a, i);
    printarr(a, n);
  }
  for (i = n; i > 0; i--) {
    heap2_down(a, i - 1);
  }
}
int main() {
  int arr[] = {4, 7, 6, 1, 0, 3, 2, 5};
  int i;
  heap2(arr, 8);
  printarr(arr, 8);
  return 0;
}