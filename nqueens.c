#include <stdio.h>
#include <time.h>
#include <math.h>

int mat[100];

int checkValid(int row, int col) {
    for(int i = 0; i < row; i++) {
        if(mat[i] == col || abs(i - row) == abs(mat[i] - col))
            return 0;
    }
    return 1;
}

void nqueens(int row, int n) {
    if(row == n) {
        printf("Solution:\n");

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i] == j)
                    printf("Q ");
                else
                    printf(". ");
            }
            printf("\n");
        }

        printf("\n");
        return;
    }

    for(int col = 0; col < n; col++) {
        if(checkValid(row, col)) {
            mat[row] = col;
            nqueens(row + 1, n);
        }
    }
}

int main() {
    int n = 4;

    clock_t start, end;
    start = clock();

    nqueens(0, n);

    end = clock();

    double time_taken =
        ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

    printf("Time taken: %f milliseconds\n", time_taken);

    return 0;
}
