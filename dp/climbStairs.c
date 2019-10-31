#include <stdio.h>
/****************************************************************************
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
****************************************************************************/
/**
 * 1.定义问题
 *   第n阶台阶是由第n-2 台阶 爬 2阶台阶上去的
 *   第n阶台阶是由第n-1 台阶 爬1阶台阶
 * 2. 划分子问题
 *   所以 n = d(n-2) + d(n-1);
 *   那么对于
 *   1阶台阶来说： 只有1种方式；
 *   2阶台阶来说： 2 步 和 1步 + 1步;
 *   2阶台阶 = d(0) + d(1);
 */
int climbStairs(int n) {
  int des;
  if (n == 1) {
    return 1;
  }
  if (n == 2) {
    return 2;
  }
  des = climbStairs(n - 2) + climbStairs(n - 1);
  return des;
}
// 用循环代替递归
int climbStairs2(int n){
    int a = 0, b = 1, c = 0;
    while (n--){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d",climbStairs(n));
  return 0;
}