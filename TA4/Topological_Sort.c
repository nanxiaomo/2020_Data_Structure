#include <stdio.h>
/**
 * @description: ta4 8-9页的内容
 * @注意点：
 *        1.此题相当与栈实现存储
 *        2. 计算入度的时候，统计一数列的值，写的时候注意下标
 * @Author: wang fei
 * @Date: 2019-10-22 16:14:10
 */
#define N 5
int a[N][N] = {
    {0,0,0,1,0},
    {1,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {1,0,1,0,0}
};
int sorted[N], indegree[N], nodestack[N], stackp = 0;
/**
 * @description: 打印数组
 * @param {}} 
 */
void printArr(int arr[], int n ,char name[]){
    int i;
    printf("%s\n", name);
    for(i=0;i<n;i++){
        printf("%d, ", arr[i]);
    }
    printf("\n");
}
void count_indegree() {
  int tail, head;
  for (head = 0; head < N; head++) {
    indegree[head] = 0;
    for (tail = 0; tail < N; tail++) {
      if (a[tail][head]) {
        indegree[head]++;
      }
    }
  }
}
void remove_node(int node) {
  int head;
  for (head = 0; head < N; head++) {
    if (a[node][head] == 1) {
      indegree[head]--;
      if (indegree[head] == 0) {
        nodestack[stackp] = head;
        stackp++;
      }
    }
  }
}
int sort(int sorted[]) {
  int count = 0, node;
  count_indegree();
  printArr(indegree,N,"节点的入度");
  for (node = 0; node < N; node++) {
    if (indegree[node] == 0) {
      nodestack[stackp] = node;
      stackp++;
    }
  }
  printArr(nodestack,stackp,"初始为0的节点");
  while (stackp > 0) {
    stackp--;
    node = nodestack[stackp];
    sorted[count] = node;
    count++;
    remove_node(node);
  }
  printArr(sorted, count,"排序后的序列");
  return count;
}
int main()
{
    int arr[N];
    int i; 
    sort(arr);
    return 0;

}
