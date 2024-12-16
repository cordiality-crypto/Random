#include <bits/stdc++.h>
#define MAX 1000000000000
#define MIN 1
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
int speed_up = [] {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    queue<int> myQueue;
    myQueue.push(n);
    int maxVal = n;
    while (!myQueue.empty()) {
        int curr = myQueue.front();
        myQueue.pop();
        maxVal = max(curr, maxVal);
        for (int i = 0; i < n; i++) {
            if (arr[i] == curr - i) {
                int newVal = curr + i;
                if (newVal != curr) 
                    myQueue.push(newVal);
            }
        }
    }
    cout << maxVal << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
