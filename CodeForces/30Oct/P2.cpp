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
    vector<int> x(3, 0);
    cin >> x[0] >> x[1] >> x[2];
    sort(x.begin(), x.end());
    cout << (x[2] - x[0]) << endl;
}

int main() {
    solve();
}