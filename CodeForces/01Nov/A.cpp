#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ones = 0;
    for (int i = 0; i < 2 * n; i++) {
        int temp;
        cin >> temp;
        if (temp)
            ones++;
    }
    int min = ones % 2;
    int max = (ones < n) ? (ones) : (2 * n - ones);
    cout << min << " " << max << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
