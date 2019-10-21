#include <stdio.h>
#include <stdlib.h>

/**
 * @description: 冒泡排序基本用法
 *               向后面pop
 * @param int arr[] 等待排序的数组
 *        int n   数据的个数
 * @return: 空
 * @Author: wang fei
 * @Date: 2019-10-21 18:46:31
 */
void BubbleSort_popbehind(int arr[],int n) {
    int i,j,temp;
    for (i=0;i<n-1;i++) {
        for (j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
/**
 * @description: 冒泡排序基本用法
 *               向前面pop
 * @param int arr[] 等待排序的数组
 *        int n   数据的个数
 * @return: 空
 * @Author: wang fei
 * @Date: 2019-10-21 18:46:31
 */
void BubbleSort_popbefore(int arr[],int n) {
    int i,j,temp;
    for(i=0; i<n-1; i++){
        for(j=n-1; j >= i+1; j--){
            if (arr[j-1]>arr[j]){
                temp = arr[j];
                arr[j]= arr[j-1];
                arr[j-1] = temp;
            }
            
        } 
    }
}

int main()
{
    int arr[] = {2, 1, 4, 3, 8, 7, 6, 9};
    int i;
    BubbleSort_popbefore(arr,8);
    for(i=0; i< 8;i++){
       printf(" %d",arr[i]);
    }
    return 0;

}