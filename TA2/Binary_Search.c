#include <stdio.h>
/*
 * @Author: 王菲
 * @Date: 2020-03-26 12:50:43
 * 二分查找
 * leetcode 中 https://leetcode-cn.com/problems/binary-search/
 * TA 中链表的位置
 */
// high 从下一个坐标开始
int binary_search1(int* nums, int numsSize, int target){
    int low = 0;
    int high = numsSize;
    int mid = 0;
    while(low<high){
        mid = low + (high - low)/2;
        if(nums[mid] > target){
            high = mid;
        }else if (nums[mid] < target){
            low = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}
// high从数组下标开始
int binary_search2(int* nums, int numsSize, int target){
    int low = 0;
    int high = numsSize -1 ;
    int mid = 0;
    while(low <= high){
        mid = low + (high - low)/2;
        if(nums[mid] > target){
            high = mid -1;
        }else if (nums[mid] < target){
            low = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}

int main(void) {  
  int arr[] = {-1, 0, 3, 5, 9, 12};
  int target = 9;
  printf("查找结果：%d\n",binary_search1(arr,6,target));
}