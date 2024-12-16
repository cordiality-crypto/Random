#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the length of the Longest Non-Increasing Subsequence (LNIS)
int findLNIS(const vector<int>& a) {
    vector<int> lnis;
    for (int num : a) {
        // Find the position where current element should be placed in lnis to maintain non-increasing order
        auto pos = upper_bound(lnis.begin(), lnis.end(), num, greater<int>());
        if (pos == lnis.end())
            lnis.push_back(num); // Extend the sequence
        else
            *pos = num; // Replace to keep the sequence non-increasing
    }
    return lnis.size();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int lnisLength = findLNIS(a);
        int minRemovals = n - lnisLength;
        
        cout << minRemovals << endl;
    }
    return 0;
}
