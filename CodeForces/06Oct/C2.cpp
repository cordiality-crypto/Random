#include <bits/stdc++.h>
#define var unsigned long long
using namespace std;

int mex(vector<var> arr, var n, var K) {
    unordered_map<var, int> mp;

    for (int i = 0; i < n; i++) {
        mp[arr[i] % K]++;
    }

    for (int i = 0; i < n; i++) {
        if (mp.find(i % K) == mp.end()) {
            return i;
        }
        mp[i % K]--;
        if (mp[i % K] == 0)
            mp.erase(i % K);
    }

    return n;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        var n, x;
        cin >> n >> x;
        vector<var> arr(n);
        for (var i = 0; i < n; i++) 
            cin >> arr[i];
        
        var mexValue = mex(arr, n, x);
        cout << mexValue << endl;
    }
}
