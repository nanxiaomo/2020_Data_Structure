#include <stdio.h>

void swap(int *p1, int *p2) {
  int temp;
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}
int Qsort(int a[],int lo,int hi){
    if (lo<hi)
    {
        int l = lo;
        int r = hi;
        int piv = a[lo];
        while(1){
            while(a[l]<piv) l++;
            while(piv<a[r]) r--;
            if (l>=r)   
            {
                break;
            }
            swap(&a[l],&a[r]);
            l++;
            r--;            
        }
        for (int i = 0; i < 8; i++) {
            printf(" %d", a[i]);
        }
        printf("/n");
        if (lo<l-1) Qsort(a,lo,l-1);
        if (r+1<hi) Qsort(a,r+1,hi);
    }       
}
int main() {
  int arr[] = {4, 7, 6, 1, 0, 3,2,5};
  int i;
  Qsort(arr, 0, 7);
  for (i = 0; i < 8; i++) {
    printf(" %d", arr[i]);
  }
  return 0;
}