#ifndef BRUTE
#define BRUTE
#define MINUS_INFINITE -214748364

typedef struct tuple {
    int left;
    int right;
    int sum;
} S;

S BARBARIC_MAX_SUBARRAY(int arr[], int low, int high) {
    S res;
    res.sum = MINUS_INFINITE;
    res.left = res.right = 0;
    int sum;
    for (int i = low; i <= high; i++) {
        sum = 0;
        for (int j = i; j <= high; j++) {
            sum += arr[j];
            if (sum > res.sum) {
                res.sum = sum;
                res.left = i;
                res.right = j;
            }
        }
    }
    return res;
}

#endif //BRUTE