#include <stdio.h>
#include<time.h>
int partition(int* a, int l,int n){
  int i = l+1,j = n;
  while(1){
    while(i <= n && a[i] <= a[l]) i++;
    while(a[j] > a[l]) j--;
    if(i >= j) break;
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
  }
  int t = a[l];
  a[l] = a[j];
  a[j] = t;
  return j;
}
void quicksort(int* a,int l,int n){
  if(l >= n) return;
  int pivotIdx = partition(a,l,n);
  quicksort(a,0,pivotIdx-1);
  quicksort(a,pivotIdx+1,n);
}
int main()
{
  int a[] = {3,41,5,6,3,2,2,34,4};
  clock_t start,end;
    start = clock();
    quicksort(a,0,8);
    end = clock();

  for (int i = 0; i < 9; i++) {
    printf("%d ",a[i]);
  }
  double time_taken = (((double)(end-start))/CLOCKS_PER_SEC)*1000;
  printf("\nTime taken: %f milli seconds\n",time_taken);
}
