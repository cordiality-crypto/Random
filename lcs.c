#include <stdio.h>
#include <stdlib.h>

char* LCS(char *a, char *b, int n, int m) {
    int **DP = (int **) malloc((n + 1) * sizeof(int *));
    for (int i = 0; i < n + 1; i++)
        DP[i] = (int *) calloc((m + 1), sizeof(int));
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (a[i - 1] == b[j - 1]) {
                DP[i][j] = 1 + DP[i - 1][j - 1];
            } else {
                DP[i][j] = (DP[i - 1][j] > DP[i][j - 1]) ? DP[i - 1][j] : DP[i][j - 1];
            }
        }
    }
    char *XLCS = (char *) calloc((DP[n][m] + 1), sizeof(char));
    int i = n, j = m, k = 0;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            XLCS[k++] = a[i - 1];
            i--;
            j--;
        } else if (DP[i - 1][j] > DP[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    int len = k;
    char *LCS = (char *) calloc(len + 1, sizeof(char));
    for (i = 0; i < len; i++) 
        LCS[i] = XLCS[len - i - 1];
    LCS[len] = '\0';
    free(XLCS);
    for (int i = 0; i < n + 1; i++)
        free(DP[i]);
    free(DP);
    return LCS;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char *a = (char *) malloc((n + 1) * sizeof(char));
    char *b = (char *) malloc((m + 1) * sizeof(char));
    scanf("%s %s", a, b);
    a[n] = b[m] = '\0';
    char *lcs = LCS(a, b, n, m);
    printf("%s\n", lcs);
    free(lcs);
    free(a);
    free(b);
}
