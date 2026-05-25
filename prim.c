#include<stdio.h>
#include<time.h>
struct edge {
    int s, e, cost;
};
int n, cost = 0, nv;
int vis[100];
struct edge a[100];
int main() {
    if (scanf("%d %d", &n, &nv) != 2) return 0;
    printf("Enter s, e and cost for following:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a[i].s, &a[i].e, &a[i].cost);
    }
    clock_t start,end;

    start = clock();
    vis[a[0].s] = 1;
    int edges_count = 0;

    while (edges_count < nv - 1) {
        int min = 100000;
        int minIdx = -1;

        for (int i = 0; i < n; i++) {
            if ((vis[a[i].s] && !vis[a[i].e]) || (!vis[a[i].s] && vis[a[i].e])) {
                if (a[i].cost < min) {
                    min = a[i].cost;
                    minIdx = i;
                }
            }
        }

        if (minIdx != -1) {
            cost += min;
            vis[a[minIdx].s] = 1;
            vis[a[minIdx].e] = 1;
            edges_count++;
        } else {
            break;
        }
    }
    end = clock();
    printf("The total cost is: %d\n", cost);
    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;

    printf("\nTime taken: %f seconds\n",time_taken);
    return 0;
}
