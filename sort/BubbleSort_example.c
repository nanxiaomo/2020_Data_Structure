#include <stdio.h>
#define swap(x, y) \
  x = x ^ y;       \
  y = x ^ y;       \
  x = x ^ y;
/****************************************************
 * 冒泡排序                                         *
 ***************************************************/
void printarr(int a[],int n){
   int i;
   for(i=0; i< n;i++){
       printf(" %d",a[i]);
    }
    printf("\n");
}
// 稳定的排序
void bullble(int a[], int n) {
  for (int i = n; i > 1; i--) {
    for (int j = 1; j < i; j++) {
      if (a[j - 1] > a[j]) {
        swap(a[j - 1], a[j])
      }
    }
  }
}

int main()
{
    int arr[] = {2, 1, 4, 3, 8, 7, 6, 9};
    int i;
    bullble(arr,8);
    printarr(arr,8);
    return 0;
}