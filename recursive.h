#ifndef RECURSIVE
#define RECURSIVE
#define MINUS_INFINITE -214748364

typedef struct Tuple {
    int left;
    int right;
    int sum;
} T;

T MAX_CROSSING_SUBARRAY(int arr[], int low, int mid, int high) {
    T res;
    int left_sum = MINUS_INFINITE, right_sum = MINUS_INFINITE;
    int sum = 0;
    int left_ID = mid, right_ID = mid + 1;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
            left_ID = i;
        }
    }    
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
            right_ID = i;
        }
    }

    res.left = left_ID;
    res.right = right_ID;
    res.sum = left_sum + right_sum;
    return res;
}


T FIND_MAX_SUBARRAY(int arr[], int low, int high) {
    if (low == high) {
        T res = {low, high, arr[low]};
        return res;
    }
    int mid = low + (high - low) / 2;
    T left_tuple = FIND_MAX_SUBARRAY(arr, low, mid);
    T right_tuple = FIND_MAX_SUBARRAY(arr, mid + 1, high);
    T cross_tuple = MAX_CROSSING_SUBARRAY(arr, low, mid, high);
    if (left_tuple.sum >= right_tuple.sum && left_tuple.sum >= cross_tuple.sum)
        return left_tuple;
    else if (right_tuple.sum >= left_tuple.sum && right_tuple.sum >= cross_tuple.sum)
        return right_tuple;
    else
        return cross_tuple;
}


#endif //RECURSIVE