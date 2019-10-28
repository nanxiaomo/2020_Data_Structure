/**
 * @description: ta5 堆排序算法
 * 难点:
 */
#include <stdio.h>
#include <malloc.h>

void in(int dt, int *val) {
  int i;
  val[0]++;
  for (i = val[0]; i > 1 && dt < val[i / 2]; i = i / 2) {
    val[i] = val[i / 2];
  }
  val[i] = dt;
}
int dl(int *val) {
  int i = 1, j, ret = val[1];
  while (i <= val[0] / 2) {
    j = 2 * i;
    if (j + 1 < val[0] && val[j+1]<val[j]) {
      j++;
    }
    if (val[val[0]] < val[j]) {
      break;
    }
    val[i] = val[j];
    i = j;
  }
  val[i] =val[val[0]] ;
  val[0]--;
  return ret;
}
void hs(int sz, int d[]) {
  int i, *val;
  val = malloc(sizeof(int) * (sz + 1));
  val[0]=0;
  for (i = 0; i < sz; i++) {
    in(d[i], val);
  }
  for (i = 0; i < sz+1; i++) {
    printf(" %d", val[i]);
  }
  printf("\n");
  for (i = 0; i < sz; i++) {
    d[i] = dl(val);
  }
}
int main() {
  int arr[] = {2,0,3,1};
  int i;
  hs(4,arr);
  for (i = 0; i < 4; i++) {
    printf(" %d", arr[i]);
  }
  return 0;
}