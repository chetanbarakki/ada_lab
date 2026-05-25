#include<stdio.h>
int main(){
    int a[] = {3,4,1,3,5,6,2,2,1};
    for(int i = 0; i < 9; i++){
        int idx = i;
        for(int j = i+1; j < 9; j++){
            if(a[i] > a[j]) idx = i;
        }
        swap(a[i],a[idx]);
    }
    for(int i = 0; i < 9; i++) printf("%d ",a[i]);
    return 0;
}
