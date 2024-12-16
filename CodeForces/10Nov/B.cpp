#include <bits/stdc++.h>
#define var long long
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
    var n, m, c;
    cin >> n >> m >> c;
    if (c >= n)
    {
        cout << n << endl;
        return;
    }
    if (m == 0)
    {
        if (c >= n)
        {
            cout << n << endl;
            return;
        }
        else if (c == 0 && n != 1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << n - 1 << endl;
        }
        return;
    }
    var i = (long long)((n - c - 1) / m + 1);
    var k = 0;
    k = n - i;
    cout << k << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}