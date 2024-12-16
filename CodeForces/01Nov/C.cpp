#include <bits/stdc++.h>
using namespace std;

auto cond = [](const int& a, const int& b, const int& c) {
    return (a + b > c) && (b + c > a) && (c + a > b);
};

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the array to simplify finding valid triplets
    sort(arr.begin(), arr.end());

    int max_window = 0, current_window = 2;  // Minimum valid window size starts at 2

    for (int i = 2; i < n; i++) {
        // Check if the current triplet satisfies the triangle condition
        if (cond(arr[i - 2], arr[i - 1], arr[i])) {
            current_window++;  // Extend the window
        } else {
            current_window = 2;  // Reset the window when a triplet fails
        }
        max_window = max(max_window, current_window);  // Track the largest window size
    }

    cout << n - max_window << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
