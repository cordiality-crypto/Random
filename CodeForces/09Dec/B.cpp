#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, res = 1;
    cin >> n;
    for (int curr = 1; curr < n; curr = curr * 2 + 2) 
        res++;
    cout << res << endl;
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