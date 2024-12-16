#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> cars(n);
        for (int i = 0; i < n; i++) 
            cin >> cars[i];
        sort(cars.rbegin(), cars.rend());
        int customers = 0;
        int remainingModels = n;
        while (remainingModels > 0) {
            customers++; 
            int taken = 0;
            for (int i = 0; i < n && taken < x; i++) {
                if (cars[i] > 0) {
                    cars[i]--;  
                    taken++; 
                    if (cars[i] == 0) {
                        remainingModels--; 
                    }
                }
            }
        }
        cout << customers << '\n';
    }

    return 0;
}
