#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, r, seats, unhappy, count;
        unhappy = count = 0;
        cin >> n >> r;
        seats = 2 * r;
        vector<int> fam(n), odds;
        odds.clear();
        while (--n >= 0) {
            cin >> fam[n];
            if (fam[n] % 2 == 0) {
                count += fam[n];
                seats -= fam[n];
            } else {
                int temp = fam[n] - 1;
                count += temp;
                seats -= temp;
                unhappy++;
            }
        }
        r = seats / 2;
        if (r > unhappy)
            count += unhappy;
        else
            count += seats - unhappy;
        cout << count << endl;
    }
}