#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int CALC_MULT(int **ARR, int n, int **SPLIT);
void GET_PAR(int i, int j, int **SPLIT);
void MULT_MATX(int ***MATX, int **ARR, int **SPLIT, int i, int j);

int main() {
    int n;
    printf("N = ");
    scanf("%d", &n);
    int **ARR = (int **)calloc(n, sizeof(int *));
    printf("SIZES =\n");
    for (int i = 0; i < n; i++) {
        ARR[i] = (int *)calloc(2, sizeof(int));
        printf("ARRAY %d:\n", (i + 1));
        scanf("%d %d", &ARR[i][0], &ARR[i][1]);
        if (i > 0 && ARR[i][0] != ARR[i - 1][1]) {
            printf("Error: Incompatible dimensions.\n");
            for (int j = 0; j <= i; j++) free(ARR[j]);
            free(ARR);
            return 1;
        }
    }
    int ***MATX = (int ***)malloc(n * sizeof(int **));
    for (int i = 0; i < n; i++) {
        MATX[i] = (int **)malloc(ARR[i][0] * sizeof(int *));
        printf("Enter elements for matrix %d (%dx%d):\n", i + 1, ARR[i][0], ARR[i][1]);
        for (int j = 0; j < ARR[i][0]; j++) {
            MATX[i][j] = (int *)malloc(ARR[i][1] * sizeof(int));
            for (int k = 0; k < ARR[i][1]; k++) 
                scanf("%d", &MATX[i][j][k]);
        }
    }
    int **SPLIT = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) 
        SPLIT[i] = (int *)calloc(n, sizeof(int));
    int result = CALC_MULT(ARR, n, SPLIT);
    printf("Minimum number of multiplications: %d\n", result);
    printf("Optimal parenthesis pattern: ");
    GET_PAR(0, n - 1, SPLIT);
    printf("\nResultant Matrix after multiplication:\n");
    MULT_MATX(MATX, ARR, SPLIT, 0, n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < ARR[i][0]; j++) free(MATX[i][j]);
        free(MATX[i]);
        free(ARR[i]);
        free(SPLIT[i]);
    }
    free(MATX);
    free(ARR);
    free(SPLIT);
    return 0;
}

int CALC_MULT(int **ARR, int n, int **SPLIT) {
    int **MUL = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        MUL[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) 
            MUL[i][j] = (i == j) ? 0 : INT_MAX;
    }
    for (int c = 1; c < n; c++) {
        for (int i = 0; i < n - c; i++) {
            int j = i + c;
            for (int k = i; k < j; k++) {
                int q = MUL[i][k] + MUL[k + 1][j] + ARR[i][0] * ARR[k][1] * ARR[j][1];
                if (q < MUL[i][j]) {
                    MUL[i][j] = q;
                    SPLIT[i][j] = k;
                }
            }
        }
    }

    int result = MUL[0][n - 1];
    for (int i = 0; i < n; i++) 
        free(MUL[i]);
    free(MUL);
    return result;
}

void GET_PAR(int i, int j, int **SPLIT) {
    if (i == j) {
        printf("A%d", i + 1);
    } else {
        printf("(");
        GET_PAR(i, SPLIT[i][j], SPLIT);
        GET_PAR(SPLIT[i][j] + 1, j, SPLIT);
        printf(")");
    }
}

void MULT_MATX(int ***MATX, int **ARR, int **SPLIT, int i, int j) {
    if (i == j) {
        for (int x = 0; x < ARR[i][0]; x++) {
            for (int y = 0; y < ARR[i][1]; y++) 
                printf("%d ", MATX[i][x][y]);
            printf("\n");
        }
    } else {
        int k = SPLIT[i][j];
        int rows = ARR[i][0];
        int cols = ARR[j][1];
        int common = ARR[k][1];
        MULT_MATX(MATX, ARR, SPLIT, i, k);
        MULT_MATX(MATX, ARR, SPLIT, k + 1, j);
        int **result = (int **)malloc(rows * sizeof(int *));
        for (int x = 0; x < rows; x++) 
            result[x] = (int *)calloc(cols, sizeof(int));
        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < cols; y++) {
                for (int z = 0; z < common; z++) 
                    result[x][y] += MATX[i][x][z] * MATX[k + 1][z][y];
            }
        }
        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < cols; y++) 
                printf("%d ", result[x][y]);
            printf("\n");
        }
        for (int x = 0; x < ARR[i][0]; x++) {
            free(MATX[i][x]);
            MATX[i][x] = result[x];
        }
        free(result);
    }
}
