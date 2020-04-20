#include <stdio.h>

void swap(int *p1, int *p2) {
  int temp;
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}
int Qsort(int a[],int lo,int hi){
    printf("Qsort(a,%d,%d)", lo, hi);
    for (int i = 0; i < 8; i++) {
            printf(" %d", a[i]);
        }
    printf("\n");
    if (lo<hi){
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
        if (lo<l-1) {
          Qsort(a,lo,l-1);
        }
        if (r+1<hi) {
          Qsort(a,r+1,hi);
        }
    }       
}
int main() {
  int a[] = {4, 7, 6, 1, 0, 3, 2, 5};
  int b[] = {7, 6, 5, 4, 3, 2, 1, 0};
  int i;
  Qsort(a, 0, 7);
  printf("排序好的a数组：");
  for (i = 0; i < 8; i++) {
    printf(" %d", a[i]);
  }
  printf("\n");
  Qsort(b, 0, 7);
  printf("排序好的b数组：");
  for (i = 0; i < 8; i++) {
    printf(" %d", b[i]);
  }
  printf("\n");
  return 0;
}