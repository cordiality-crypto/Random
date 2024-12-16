#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    for (int i = 0; i < n; i++) {
        int player1 = arr[i];
        bool c = true;
        for (int j = 0; j < n; j++) {
            if (j == i)
                continue;
            int player2 = arr[j];
            if (abs(player1 - player2) % k == 0) {
                c = false;
            }
        }
        if (c) {
            cout << "YES" << endl << i + 1 << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}

#pragma GCC optimize("Ofast,unroll-loops") 
int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();