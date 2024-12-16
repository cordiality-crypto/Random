#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

// Function for modular exponentiation
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> result;
    long long sum_odds = 0, total_power_of_2 = 0;

    for (int i = 0; i < n; ++i) {
        long long x = a[i];
        long long power_count = 0;

        // Divide x by 2 until it becomes odd, counting divisions
        while (x % 2 == 0) {
            x /= 2;
            power_count++;
        }

        // Accumulate total power of 2
        total_power_of_2 += power_count;

        // Add the odd component to sum of odds
        sum_odds = (sum_odds + x) % MOD;

        // Calculate the maximum sum for the current prefix
        long long max_sum = (sum_odds * mod_pow(2, total_power_of_2, MOD)) % MOD;
        result.push_back(max_sum);
    }

    // Output results for each prefix
    for (auto res : result) {
        cout << res << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
