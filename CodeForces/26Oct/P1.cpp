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
    int n, maxh, maxw;
    maxh = maxw = INT_MIN;
    cin >> n;
    while (n--) {
        int h, w;
        cin >> h >> w;
        if (h > maxh)
            maxh = h;
        if (w > maxw)
            maxw = w;
    }
    cout << (2 * maxw + 2 * maxh) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}