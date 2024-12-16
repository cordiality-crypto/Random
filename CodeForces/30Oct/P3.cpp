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
    queue<int> dig;
    int c = 0;
    while (n > 0) {
        int d = n % 10;
        dig.push(d);
        if (d != 0)
            c++;
        n /= 10;
    }
    cout << c << endl;
    c = 1;
    while(!dig.empty()) {
        int n = dig.front();
        dig.pop();
        if (n)
            cout << n * c << " ";
        c *= 10;
    }
    cout << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}