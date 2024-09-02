#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateTestCases(FILE *file, int size) {
    fprintf(file, "%d\n", size);
    for (int i = 0; i < size; i++) {
        int num = (rand() % 201) - 100; 
        fprintf(file, "%d ", num);
    }
    fprintf(file, "\n");
}

int main() {
    FILE *file = fopen("testcases.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    srand(time(0));
    int c = 1;
    for (int i = 0; i < 18; i++) {
        generateTestCases(file, c);
        c *= 2;
    }

    fclose(file);
    printf("Test cases generated and stored in 'testcases.txt'.\n");

    return 0;
}
