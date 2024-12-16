#include <bits/stdc++.h>
using namespace std;
#define let long long

void solve() {
    long k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    let c = 0;
    long curr_k = 1, l, r;
    for (int x = 0; x < 32 && curr_k <= 1e9; ++x) {
        l = max((long)ceil((double)l2 / curr_k), l1);
        r = min((long)floor((double)r2 / curr_k), r1);
        if (l <= r) c += (r - l + 1);
        if (curr_k > 1e9 / k) break;
        curr_k *= k;
    }
    cout << c << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

#pragma GCC optimize("Ofast,unroll-loops") 
int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
