#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_set<int> set;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a[i] = temp;
        if (set.find(temp) != set.end()) 
            continue;
        set.insert(temp);
        b.push_back(temp);
    }
    for (int i = 1; i <= n; i++) {
        if (set.find(i) == set.end()) {
            b.push_back(i);
        }
    }
    for (int x : b) {
        cout << x << " ";
    }
    cout << "\n";
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
