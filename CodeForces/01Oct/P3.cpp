#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		unsigned long long n;
		cin >> n;
		cout << n + long(sqrtl(n) + 0.5) << endl;
	}
	return 0;
}
