#include<stdio.h>
void swap(float* a,float* b){
    float t = *a;
    *a = *b;
    *b = t;
}
void main(){
    int n;
    printf("Enter no of elements,prices and wts");
    scanf("%d",&n);
    float pr[100],wt[100];
    for(int i = 0; i < n; i++){
        scanf("%f",&pr[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%f",&wt[i]);
    }
    float temp[100];
    for(int i = 0; i < n; i++){
        temp[i] = pr[i]/wt[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(temp[i] < temp[j]){
                swap(&pr[i],&pr[j]);
                swap(&wt[i],&wt[j]);
                swap(&temp[i],&temp[j]);
            }
        }
    }
    int m;
    float res = 0;
    printf("Enter kgs");
    scanf("%d",&m);
    for(int i = 0; i < n; i++){
        if(m == 0) break;
        float x;
        if(m < wt[i]) x = m;
        else x = wt[i];
        res += temp[i]*x;
        m -= x;
    }
    printf("The maximum profit is: %f",res);
}
