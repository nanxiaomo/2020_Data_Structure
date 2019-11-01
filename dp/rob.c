#include <stdio.h>
#include <malloc.h>
/************************************************************************
* 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
* 
* 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
*
* 示例 1:
*
* 输入: [1,2,3,1]
* 输出: 4
* 解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
*     偷窃到的最高金额 = 1 + 3 = 4 。
******************************************************************************/
int max(int a,int b){
    return a>b?a:b;
}
int rob(int* nums, int numsSize){
    if(numsSize == 0) return 0;
    int *d = (int *)malloc(sizeof(int)* (numsSize + 1));
    d[0] = 0;
    d[1] = nums[0];
    for (int i = 2; i < numsSize + 1; i++)
    {
        d[i] =max((d[i-2] + nums[i-1]),d[i-1]);
    }
    return d[numsSize];
}
//别人的解决方法
int rob1(int* nums, int numsSize){
    int prevMax = 0;
    int currMax = 0;
    for (int i = 0; i < numsSize; i++){
            int temp = currMax;
            currMax = max(prevMax + nums[i], currMax);
            prevMax = temp;
    }
    return currMax;
}
int main() {
  int arr[] = {4, 7, -8, 1, 0, 3, 2, 5};
  int sum = rob1(arr,8);
  printf(" %d", sum);
  return 0;
}