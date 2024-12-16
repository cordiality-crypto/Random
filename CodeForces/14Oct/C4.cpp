#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
unordered_map<long long, unordered_map<long long, long long>> C;
long long binomial_coefficient(int n, int k)
{
    if (k > n || k < 0)
        return 0;
    if (k == 0 || k == n)
        return 1;
    if (C[n][k] != 0)
        return C[n][k];
    C[n][k] = (binomial_coefficient(n, k - 1) + binomial_coefficient(n - 1, k - 1)) % MOD;
    return C[n][k];
}

int main()
{
    int t;
    cin >> t;
    vector<int> N(t), K(t);
    for (int i = 0; i < t; i++)
        cin >> N[i];
    for (int i = 0; i < t; i++)
        cin >> K[i];
    for (int i = 0; i < t; i++)
        cout << binomial_coefficient(N[i], K[i]) << endl;
    return 0;
}
