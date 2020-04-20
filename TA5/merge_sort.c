#include <stdio.h>
#define N 10

void func1(int * numbers,int start,int size){
    int h,i,j,k,tmp[N] = {0,0,0,0,0,0,0,0,0,0};
    h = size/2;
    i=start;
    j=start + h;
    for(k=0;k<size;k++){
        if((j == start+size)|| (i<start + h)&& (numbers[i]<numbers[j])){
            tmp[k]=numbers[i];
            i++;
        }else{
            tmp[k]=numbers[j];
            j++;
        }
    }
    // printf("%d,%d,%d,%d,%d,%d\n",tmp[0],tmp[1],tmp[2],tmp[3],tmp[4],tmp[5]);
    for(k=0;k<size;k++){
        numbers[start+k] =tmp[k];
    }
    // printf("%d,%d,%d,%d,%d,%d\n",numbers[0],numbers[1],numbers[2],numbers[3],numbers[4],numbers[5]);

}
void func2(int * numbers,int start,int size){
    int h;
    printf("%d, %d\n",start,size);
    if(size > 1){
        h = size/2;
        func2(numbers,start,h);
        func2(numbers,start+ h,size-h);
        func1(numbers,start,size);
    }
}
int main() {
  int arr[6] = {3,2,5,4,6,1};
  int i;
  func2(arr, 0, 6);
  for (i = 0; i < 6; i++) {
    printf(" %d", arr[i]);
  }
  return 0;
}