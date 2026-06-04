#include <stdio.h>

int a[10], d[10], n;

int mobile()
{
    int i, m = 0, p = -1;

    for (i = 0; i < n; i++)
    {
        if (d[i] == -1 && i - 1 >= 0 && a[i] > a[i - 1])
        {
            if (a[i] > m)
            {
                m = a[i];
                p = i;
            }
        }
        else if (d[i] == 1 && i + 1 < n && a[i] > a[i + 1])
        {
            if (a[i] > m)
            {
                m = a[i];
                p = i;
            }
        }
    }

    return p;
}

int main()
{
    int i, p, t, v;

    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        a[i] = i + 1;
        d[i] = -1;
    }

    while (1)
    {
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);

        printf("\n");

        p = mobile();

        if (p == -1)
            break;

        v = a[p];
        t = p + d[p];

        int x = a[p];
        a[p] = a[t];
        a[t] = x;

        x = d[p];
        d[p] = d[t];
        d[t] = x;

        for (i = 0; i < n; i++)
        {
            if (a[i] > v)
                d[i] = -d[i];
        }
    }

    return 0;
}
