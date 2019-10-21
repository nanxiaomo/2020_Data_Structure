#include <stdio.h>
#include <stdlib.h>

/*
* 冒泡排序算法
*
*/
// arr[] 传入数组
// n 数组的个数，从1开始

void Bubblesort(int arr[],int n) {
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

int main()
{
    int arr[] = {1, 4, 3, 2};
    int i;
    Bubblesort(arr,4);
    for(i=0; i<4;i++){
       printf(" %d",arr[i]);
    }

}