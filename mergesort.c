#include<stdio.h>
#include<time.h>

void merge(int* a,int l,int m,int r){
    int c = l, b = m+1, k = 0;
    int v[50];

    while(c <= m && b <= r){
        if(a[c] < a[b])
            v[k++] = a[c++];
        else
            v[k++] = a[b++];
    }

    while(c <= m)
        v[k++] = a[c++];

    while(b <= r)
        v[k++] = a[b++];

    for(int i=l,j=0;i<=r;i++,j++)
        a[i] = v[j];
}

void mergesort(int l,int r,int* a){
    if(l >= r) return;

    int m = (l+r)/2;

    mergesort(l,m,a);
    mergesort(m+1,r,a);
    merge(a,l,m,r);
}

int main(){

    int a[] = {3,4,1,3,5,6,2,2,1};
    int n = 9;

    clock_t start,end;

    start = clock();   // start time

    mergesort(0,n-1,a);

    end = clock();     // end time

    printf("Sorted array:\n");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;

    printf("\nTime taken: %f seconds\n",time_taken);

    return 0;
}
