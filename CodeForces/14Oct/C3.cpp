#include <iostream>
#include <string>
using namespace std;

void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int c = 0;
    while (c < n && c < m && s[c] == t[c])
        c++;
    int res = (n - c) + (m - c);
    if (c != 0)
        res += c + 1;
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--)
    {
        solve();
    }
    return 0;
}
