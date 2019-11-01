#include <stdio.h>
int max(int a,int b) {
    return a>b?a:b;
}
int g(int a[],int n){
    int t = a[0];
    for (int  k = 0; k < n; k++)
    {
        t = max((t+a[k]),a[k]);
    }
    return t;
}
int f(int a[],int n){
    int s = a[0];
    for (int  k = 0; k < n; k++)
    {
        s = max(s,g(a,k+1));
    }
    return s;
}
int test(int a[],int n) {
    int t = a[0],s=a[0];
    for (int i = 1; i < n; i++)
    {
        t= max((t+a[i]),a[i]);
        s = max(s,t);
    }
    return s;
}
int main() {
  int arr[] = {2, 1, -3, 4,-9,12,78,9,-100,-200};
  printf("%d", test(arr, 10));
  return 0;
}