#include<stdio.h>
#include<time.h>
struct edge{
    int s,e,cost;
};
int cost = 0;
 int grp[100];
 int find(int x){
    if(x != grp[x]) grp[x] = find(grp[x]);
    return grp[x];
 }
 void merge(int x,int y,int c){
    int gx = find(x);
    int gy = find(y);
    if(gx != gy){
        grp[gy] = gx;
        cost += c;
    }
 }
int main(){
    struct edge a[100];
    int n;
    scanf("%d",&n);
    printf("Enter s,e and cost for following");
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i].s);
        scanf("%d",&a[i].e);
        scanf("%d",&a[i].cost);
    }
    clock_t start,end;

    start = clock();
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(a[i].cost > a[j].cost){
                struct edge t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    for(int i = 0; i < 100; i++) grp[i]=i;
    for(int i = 0; i < n; i++){
        merge(a[i].s,a[i].e,a[i].cost);
    }
    end = clock();
    printf("The total cost is: %d",cost);

    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;

    printf("\nTime taken: %f seconds\n",time_taken);
    return 0;
}
