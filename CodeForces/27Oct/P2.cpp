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
    int N;
    cin >> N;
    if (N == 1 || N == 3) {
        cout << "-1\n";
        return;
    } else if (N == 2) {
        cout << "66\n";
        return;
    }
    int a = 1, b, n, Y = int(N / 2), X = N - Y;
    b = X - a;
    if (N % 2 == 0) {
        n = b;
    } else {
        n = b - 2;
    }
    n = Y - n;
    string s(N, '3');
    s[N - 1] = '6';
    for (int i = N - 2; i >= 0; i -= 2) {
        if (n--) {
            s[i] = '6';
        } else {
            break;
        }
    }
    cout << s <<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
