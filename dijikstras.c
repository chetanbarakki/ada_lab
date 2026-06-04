#include<stdio.h>
void swap(float* a,float* b){
    float t = *a;
    *a = *b;
    *b = t;
}
void main(){
    int n;
    printf("Enter no of vertices");
    scanf("%d",&n);
    int dist[100], adj[2][100][100],vis[100];
    for(int i = 0; i < n; i++){
        dist[i] = 10000;
        vis[i] = 0;
        for(int j = 0; j < n; j++){
            scanf("%d",&adj[0][i][j]);
            scanf("%d",&adj[1][i][j]);
        }
    }
    dist[0] = 0;
    for(int s = 0; s < n; s++){
        int curr = 10001,idx = 0;
        for(int j = 0; j < n; j++){
            if(!vis[j] && curr > dist[j]){
                curr = dist[j];
                idx = j;
            }
        }
        for(int i = 0; i < n; i++){
            if(!vis[i] && adj[0][idx][i] && dist[i] > dist[idx]+adj[1][idx][i]){
                dist[i] = dist[idx]+adj[1][idx][i];
            }
        }
        vis[idx] = 1;
    }
    for(int i = 0; i < n; i++){
        printf("The min distance is for %d: %d \n",i,dist[i]);
    }
}
