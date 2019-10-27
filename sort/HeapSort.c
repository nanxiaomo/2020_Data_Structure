#include <stdio.h>
// 堆排序
/**
 * 堆的概念：
 * 1.堆是一个完全二叉树
 * 2. 堆的父节点值大于子节点
 * 3. 堆可以用一个数组储存
 * 4. 已知堆的父节点为i，那么子节点为2i+1，2i+2；
 * 5. 已知堆的子节点为n 则 父节点为（n-1）/2；
 */

void swap(int *p1, int *p2) {
  int temp;
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}
/**
 * @description:调整堆的顺序
 * @param int tree[] 堆的数组
 *        int  n 总数
 *        int i 父节点的下标
 */
void heapify(int tree[], int n, int i) {
  // 递归结束的调节
  if (i >= n) return;
  // 左节点
  int c1 = 2 * i + 1;
  // 右节点
  int c2 = 2 * i + 2;
  int max = i;
  // 找三个节点中最大
  if (c1 < n && tree[c1] > tree[max]) {
    max = c1;
  }
  if (c2 < n && tree[c2] > tree[max]) {
    max = c2;
  }
  if (i != max) {
    swap(&tree[i], &tree[max]);
    heapify(tree, n, max);
  }
}
void buildHeap(int arr[], int n) {
  int last_node = n - 1;
  int parent = (last_node - 1) / 2;
  int i;
  for (i = parent; i >= 0; i--) {
    heapify(arr, n, i);
  }
}
void HeapSort(int arr[], int n) {
  buildHeap(arr, n);
  for (int i = 0; i < 8; i++) {
    printf(" %d", arr[i]);
  }
  printf("\n");
  for (int i = n - 1; i >= 0; i--) {
    swap(&arr[i],&arr[0]);
    heapify(arr, i, 0);
  }
}
int main() {
  int arr[] = {4, 7, 6, 1, 0, 3, 2, 5};
  int temp[8] = {};
  int i;
  HeapSort(arr,8);
  for (i = 0; i < 8; i++) {
    printf(" %d", arr[i]);
  }
  return 0;
}