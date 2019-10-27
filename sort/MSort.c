#include <stdio.h>

void Mmarge(int arr[], int temp[], int lstart, int rstart, int rend) {
  int lend = rstart - 1;
  int i = lstart;
  int j = rstart;
  int tempindex = lstart;
  int num = rend - lstart + 1;
  while (i <= lend && j <= rend) {                                                                                                                                                           
    if (arr[i] < arr[j]) {
      temp[tempindex++] = arr[i++];
    } else {
      temp[tempindex++] = arr[j++];
    }
  }
  while (i <= lend) {
    temp[tempindex++] = arr[i++];
  }
  while (j <= rend) {
    temp[tempindex++] = arr[j++];
  }
  for (i = 0; i < num; i++,rend--)
  {
      arr[rend] = temp[rend];
  }
  
}

void MSort(int arr[], int temp[], int start, int end) {
  int mid;
  if (start < end) {
    mid = (start + end) / 2;
    MSort(arr, temp, start, mid);
    MSort(arr, temp, mid + 1, end);
    Mmarge(arr, temp, start, mid + 1, end);
  }
}

int main() {
  int arr[] = {4, 7, 6, 1, 0, 3, 2, 5};
  int temp[8] = {};
  int i;
  MSort(arr,temp, 0, 7);
  for (i = 0; i < 8; i++) {
    printf(" %d", arr[i]);
  }
  return 0;
}