#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        long long m, x, y, z;
        cin >> m >> x >> y >> z;

        long long r1 = min(m, x);
        long long r2 = min(m, y);
        long long rem = m - r1 + m - r2;
        long long res = r1 + r2 + min(rem, z);

        cout << res << '\n';
    }
}

int main() {
    solve();
}

#pragma GCC optimize("Ofast,unroll-loops") 
int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
