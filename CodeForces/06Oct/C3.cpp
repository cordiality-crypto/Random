#include <bits/stdc++.h>
using namespace std;

bool canPresent(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();
    vector<int> lineOrder = a;    
    for (int slide = 0; slide < m; slide++) {
        int requiredMember = b[slide];
        bool found = false;
        for (int pos = 0; pos < lineOrder.size(); pos++) {
            if (lineOrder[pos] == requiredMember) {
                int member = lineOrder[pos];
                lineOrder.erase(lineOrder.begin() + pos);
                lineOrder.insert(lineOrder.begin(), member);
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        if (canPresent(a, b)) {
            cout << "YA\n";
        } else {
            cout << "TIDAK\n";
        }
    }
    return 0;
}