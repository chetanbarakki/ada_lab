#include<stdio.h>
#include<time.h>

void heapify(int* a,int n,int p){
    int c,item;
    c = 2*p+1;
    item = a[p];
    while(c <= n-1){
                 if(c+1 <= n-1){
            if(a[c] < a[c+1]) c++;
        }
        if(item < a[c]){
            a[p] = a[c];
            p = c;
            c = 2*p+1;
        }else break;
    }
    a[p] = item;
}
void buildheap(int* a, int n){
    for(int i = (n-1)/2; i >= 0; i--){
        heapify(a,n,i);
    }
}
void heapsort(int* a,int n){
    buildheap(a,n);
    for(int i = n-1; i > 0; i--){
        int t = a[i];
        a[i] = a[0];
        a[0] = t;
        heapify(a,i,0);
    }
}
int main(){
    int a[] = {3,4,1,3,5,6,2,2,1};
    int n = 9;
    clock_t start,end;
    start = clock();
    heapsort(a,n);
    end = clock();
    printf("Sorted array:\n");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;

    printf("\nTime taken: %f seconds\n",time_taken);

    return 0;
}
