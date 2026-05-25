#include<stdio.h>
#include<time.h>
int min(int a,int b){
    return a < b ? a : b;
}
void floyd(int a[][4],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                a[j][k] = min(a[j][k],a[j][i]+a[i][k]);
            }
        }
    }
}
int main(){
    int a[4][4] = {{0,99999,6,1},{4,0,10,5},{99999,3,0,12},{6,99999,12,0}};
    int n = 4;
    clock_t start,end;
    start = clock();
    floyd(a,n);
    end = clock();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)printf("%d ",a[i][j]);
        printf("\n");
    }

    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;

    printf("\nTime taken: %f seconds\n",time_taken);

    return 0;
}
