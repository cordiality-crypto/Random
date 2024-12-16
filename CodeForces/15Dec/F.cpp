#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    unordered_set<int> set;
    vector<int> a(n), b(m);
    long long sum = 0;
    int temp;
    for (int i = 0; i < n ; i++) {
            cin >> a[i];
    }
    for (int i = 0; i < m ; i++) {
            cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp = a[i] * b[j];
            set.insert(temp);
            sum += temp;
        }
    }
    while (q--) {
        cin >> temp;
        if (set.find(sum - temp) != set.end())
            cout << "YES";
        else    
            cout << "NO";
        cout << "\n";
    }
    return;
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