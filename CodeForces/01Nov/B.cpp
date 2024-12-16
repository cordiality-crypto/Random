#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << 1 << endl << 1 <<endl;
        return;
    }
    if (k % 2 == 0) {
        cout << 3 << endl;
        cout << 1 << " " << k << " " << k + 1 << endl;
        return;
    } else if (k == 1 || k == n) {
        cout << -1 << endl;
        return;
    }
    cout << 3 << endl;
    cout << 1 << " " << k - 1 << " " << k + 2 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
