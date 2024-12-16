#include <bits/stdc++.h>
using namespace std;

bool check(const string &s, int root) {
    int n = root * root;
    for (int i = 0; i < root; i++) 
        if (s[i] != '1' || s[n - 1 - i] != '1') 
            return false;
    for (int i = 0; i < root; i++) 
        if (s[i * root] != '1' || s[(i + 1) * root - 1] != '1') 
            return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int root = sqrt(n);
        if (check(s, root)) 
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }
    return 0;
}