#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, d, l;
    cin >> n >> d >> l;

    // Validate diameter constraint
    if (n < d + 1 || l < 2 || 2 * l - 1 > n) {
        cout << -1 << endl;
        return;
    }

    vector<pair<int, int>> edges;
    int currentNode = 1;

    // Step 1: Create a path of length `d` for the diameter
    for (int i = 1; i <= d; ++i) {
        edges.emplace_back(currentNode, currentNode + 1);
        currentNode++;
    }

    // Step 2: Attach leaves to the diameter path
    int leavesAttached = 0;
    for (int i = 1; i <= d + 1 && leavesAttached < l; ++i) {
        if (leavesAttached < l) {
            edges.emplace_back(i, ++currentNode);
            leavesAttached++;
        }
    }

    // Step 3: Attach remaining nodes arbitrarily
    while (currentNode < n) {
        edges.emplace_back(1, ++currentNode);
    }

    // Output the edges
    for (const auto& edge : edges) {
        cout << edge.first << " " << edge.second << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
