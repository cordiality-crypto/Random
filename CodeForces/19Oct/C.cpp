#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops") 
int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }
    cout << (max - min) * (n - 1) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
