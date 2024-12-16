/* You are given two integers n and k

.

In one operation, you can subtract any power of k
from n. Formally, in one operation, you can replace n by (n−kx) for any non-negative integer x

.

Find the minimum number of operations required to make n
equal to 0

.
Input

Each test contains multiple test cases. The first line contains the number of test cases t
(1≤t≤104

). The description of the test cases follows.

The only line of each test case contains two integers n
and k (1≤n,k≤109

).
Output

For each test case, output the minimum number of operations on a new line.*/

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
	int t;
	cin >> t;
	while (t--) {
		unsigned long long n, x;
		cin >> n >> x;
		cout << OPERATIONS(n, x) << endl;
	}
	return 0;
}
