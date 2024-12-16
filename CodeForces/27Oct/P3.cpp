#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> generate_permutation(int n) {
    vector<int> permutation(n);
    int left = 1, right = n;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            permutation[i] = left++;
        } else {
            permutation[i] = right--;
        }
    }
    return permutation;
}

int maximize_k(int n, vector<int>& permutation) {
    vector<int> dp(1 << 18, -1); 
    dp[0] = 0; 
    for (int i = 0; i < n; i++) {
        vector<int> new_dp = dp;
        int pi = permutation[i];
        
        if ((i + 1) % 2 == 1) { 
            for (int k = 0; k < (1 << 18); k++) {
                if (dp[k] != -1) {
                    int new_k = k & pi;
                    new_dp[new_k] = max(new_dp[new_k], dp[k]);
                }
            }
        } else { 
            for (int k = 0; k < (1 << 18); k++) {
                if (dp[k] != -1) {
                    int new_k = k | pi;
                    new_dp[new_k] = max(new_dp[new_k], dp[k] | pi);
                }
            }
        }
        dp = move(new_dp); 
    }
    int max_k = 0;
    for (int k = 0; k < (1 << 18); k++) 
        if (dp[k] != -1) 
            max_k = max(max_k, dp[k]);
    return max_k;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> permutation = generate_permutation(n);
        int max_k = maximize_k(n, permutation);
        cout << max_k << endl;
        for (int i = 0; i < n; i++) {
            cout << permutation[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
