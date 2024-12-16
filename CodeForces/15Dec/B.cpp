#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        string b = a;
        reverse(b.begin(), b.end());
        for (char &ch : b) {
            if (ch == 'p') ch = 'q';
            else if (ch == 'q') ch = 'p';
        }
        cout << b << '\n';
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
