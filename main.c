#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "recursive.h"
#include "brute.h"

void runTestCase(FILE *file) {
    int n;
    fscanf(file, "%d", &n); // Read the size of the array

    int *arr = (int *)calloc(n, sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]); // Read array elements
    }

    // Measure time for brute force method
    clock_t start_brute = clock();
    S brute = BARBARIC_MAX_SUBARRAY(arr, 0, n - 1);
    clock_t end_brute = clock();
    double time_brute = (double)(end_brute - start_brute) / CLOCKS_PER_SEC;

    // Measure time for recursive method
    clock_t start_recursive = clock();
    T recursive = FIND_MAX_SUBARRAY(arr, 0, n - 1);
    clock_t end_recursive = clock();
    double time_recursive = (double)(end_recursive - start_recursive) / CLOCKS_PER_SEC;

    printf("Array Size: %d\n", n);
    printf("Brute Force Method: Time taken = %f seconds\n", time_brute);
    printf("Max Subarray: left = %d, right = %d, sum = %d\n", brute.left, brute.right, brute.sum);

    printf("Recursive Method: Time taken = %f seconds\n", time_recursive);
    printf("Max Subarray: left = %d, right = %d, sum = %d\n", recursive.left, recursive.right, recursive.sum);
    printf("\n");

    free(arr); // Free allocated memory
}

int main() {
    FILE *file = fopen("testcases.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Run test cases sequentially
    while (!feof(file)) {
        runTestCase(file);
    }

    fclose(file);
    return 0;
}
