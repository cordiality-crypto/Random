#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
int speed_up = []
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

void solve()
{
    int n;
    cin >> n;
    switch (n)
    {
    case 2:
    case 3:
    case 4:
        cout << -1 << endl;
        return;
    case 5:
        cout << "1 ";
        cout << "3 ";
        cout << "5 ";
        cout << "4 ";
        cout << "2" << endl;
        return;
    case 6:
        cout << "1 ";
        cout << "5 ";
        cout << "3 ";
        cout << "6 ";
        cout << "4 ";
        cout << "2" << endl;
        return;
    case 7:
        cout << "1 ";
        cout << "5 ";
        cout << "3 ";
        cout << "7 ";
        cout << "2 ";
        cout << "4 ";
        cout << "6" << endl;
        return;
    default:
        int m = (n % 2) ? n : n - 1;
        for (int i = m; i > 0; i -= 2)
        {
            cout << i << " ";
        }
        cout << 8 << " ";
        for (int i = 2; i <= n; i += 2)
        {
            if (i == 8)
                continue;
            cout << i << " ";
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
