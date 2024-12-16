#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops") 
int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        unordered_map<int, int> map;
        for (int num : A) map[num]++;
        int c = 0;
        for (auto &[_, count] : map) c += count / 2;
        cout << c << endl;
    }
    return 0;
}
