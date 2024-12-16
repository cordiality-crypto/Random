#include <iostream>
#include <vector>
#include <set>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
int speed_up = []
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

bool canMeet(int n, int a, int b, const string &s)
{
    set<pair<int, int>> visited;
    int x = 0, y = 0;
    visited.insert({x, y});
    for (char move : s)
    {
        if (move == 'N')
            y++;
        else if (move == 'S')
            y--;
        else if (move == 'E')
            x++;
        else if (move == 'W')
            x--;
        visited.insert({x, y});
        if (x == a && y == b)
            return true;
    }
    int X = x, Y = y;
    if (X == 0 && Y == 0)
        return visited.count({a, b});
    for (auto [dx, dy] : visited)
    {
        int remX = a - dx, remY = b - dy;
        if ((X == 0 && remX != 0) || (Y == 0 && remY != 0))
            continue;
        if ((X != 0 && remX % X != 0) || (Y != 0 && remY % Y != 0))
            continue;
        int k1 = (X != 0) ? remX / X : 0;
        int k2 = (Y != 0) ? remY / Y : 0;
        if ((X == 0 || Y == 0 || k1 == k2) && k1 >= 0 && k2 >= 0)
            return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        cout << (canMeet(n, a, b, s) ? "YES" : "NO") << endl;
    }
    return 0;
}