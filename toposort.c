Lab program 1:
Write program to obtain the Topological ordering of vertices in a given digraph.

#include <stdio.h>

int adj[100][100];
int stack[100], visited[100] = {0};
int top = -1;
int n;

void dfs(int v)
{
    visited[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (adj[v][i] && !visited[i])
        {
            dfs(i);
        }
    }

    stack[++top] = v;
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    printf("Topological Order: ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    return 0;
}
