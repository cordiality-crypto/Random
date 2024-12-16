#include <bits/stdc++.h>
using namespace std;
 
unsigned long long OPERATIONS(unsigned long long n, unsigned long long k) {
	if (k == 1)
		return n;
    unsigned long long res = 0;
    while (n > 0) {
        res += (n % k);
        n /= k; 
    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(false);
   	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	int t;
	cin >> t;
	while (t--) {
		unsigned long long n, x;
		cin >> n >> x;
		cout << OPERATIONS(n, x) << endl;
	}
	return 0;
}