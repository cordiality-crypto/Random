#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops") 
int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

void solve() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int res = std::min((k * l) / nl, std::min((c * d), (p / np))) / n;
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}