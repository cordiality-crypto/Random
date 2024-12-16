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
    long n;
    cin >> n;
    if (n == 1) {
        cout << '0' << '\n';
        return;
    }
    vector<char> s(n, '0');
    s[0] = '1';
    string res(s.begin(), s.end());
    cout << res << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
