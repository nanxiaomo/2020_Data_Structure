#include <stdio.h>
#define MAXR 256
#define MAXN 1000
void sort(int values[],int numvalues,int r,int maxdigit){
    int rd,d,b,i,n,j;
    int m;
    int buckets[MAXR][MAXN];
    int numbucket[MAXR];
    rd = 1;
    for(d = 1;d<= maxdigit;d++){
        for(b=0;b<r;b++){
           numbucket[b]= 0; 
        }
        for(i=0;i<numvalues;i++){
            n=(values[i]/rd)%r;
            buckets[n][numbucket[n]++] = values[i];
        }
        i=0;
        // 原程序
        // for(b=0; b<r; b++){
        //     for (j = 0; j < numbucket[b]; j++){
        //         values[i++]=buckets[b][j];
        //     }
        // }
        // 高老师的答案
        // for(b=r-1;b>0;b--){
        //     for (j = numbucket[b]-1; j >0 ; j--){
        //         values[i++]=buckets[b][j];
        //     }
        // }
        //guo的答案：
        // for(b=r;b>=0;b--){
        //     for (j = numbucket[b]; j >0 ; j--){
        //         values[i++]=buckets[b][j];
        //     }
        // }
        //wo的答案：
        for(b=r-1;b>=0;b--){
            for (j = 0; j < numbucket[b]; j++){
                values[i++]=buckets[b][j];
            }    
        }
        for (m = 0; m < 6; m++) {
            printf(" %d", values[m]);
        }
        printf("\n", values[m]);
        rd*=r;
    }
}

int main() {
  int values[6] = {98,26,33,52,2,67};
  int i;
  sort(values,6,10,2);
  for (i = 0; i < 6; i++) {
    printf(" %d", values[i]);
  }
  return 0;
}