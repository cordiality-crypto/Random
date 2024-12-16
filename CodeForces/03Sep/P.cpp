#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<int> res;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                char ch[4];
                cin >> ch[0] >> ch[1] >> ch[2] >> ch[3];
                if (ch[0] == '#')
                    res.push_back(1);
                else if (ch[1] == '#')
                    res.push_back(2);
                else if (ch[2] == '#')
                    res.push_back(3);
                else
                    res.push_back(4);
            }
        }
        for (int i : res) 
            cout << i << " ";
        cout << endl;
    }
}