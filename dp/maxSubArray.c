#include <limits.h>
#include <stdio.h>
/**********************************************************************************************
 * 给定一个整数数组
 *nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 *  示例:
 *
 *  输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 ************************************************************************************************/
/**
 * 1.定义问题
 * . 如果最大字串和元素的结尾就是当前元素
 * . sum > 0，则说明 sum 对结果有增益效果，则 sum 保留并加上当前遍历数字
 * . sum <= 0，则说明 sum 对结果无增益效果，需要舍弃，则 sum
 * 直接更新为当前遍历数字 每次比较 sum 和
 * 最大值子序和的大小，将最大值置为ans，遍历结束返回结果
 */
int maxSubArray(int* nums, int numsSize) {
  // 最大子序和
  int maxsum = nums[0];
  // 目前的和
  int sum = 0;
  for (int i = 0; i < numsSize; i++) {
    //  如果sum 是正数
    if (sum > 0) {
      sum += nums[i];
    } else {
      // 如果是负数,舍弃sum
      sum = nums[i];
    }
    maxsum = maxsum > sum ? maxsum : sum;
  }
  return maxsum;
}
/**
 * 分而治之 的思想
 * 最大子序产生在
 *    1. 中间的数完全左边序列中（完全不包含中间数）
 *    2. 中间数字的完全右边序列中（完全不包含中间数）
 *    3. 包含中间数的左右序列中
 */
int maxSubArray1(int* nums, int numsSize) {
  if (numsSize == 0) return 0;
  return helper(nums, 0, numsSize - 1);
}
// 最大函数
int max(int a, int b) { return a > b ? a : b; }
int helper(int* nums, int l, int r) {
  if (l > r)
    return INT_MIN;  
  if (l == r) return nums[l];
  int mid = (l + r) / 2;
  int left = helper(nums, l, mid - 1);
  int right = helper(nums, mid + 1, r);
  int t = nums[mid];
  int max_num = nums[mid];
  for (int i = mid - 1; i >= l; i--) {
    t += nums[i];
    max_num = max(max_num, t);
  }
  t = max_num;
  for (int i = mid + 1; i <= r; i++) {
    t += nums[i];
    max_num = max(max_num, t);
  }
  return max(max(left, right), max_num);
}

int main() {
  int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  printf("%d", maxSubArray1(arr, 9));
  return 0;
}