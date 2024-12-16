#include <bits/stdc++.h>
using namespace std;

int main() {
	int i, j, x, idx, idy;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			cin >> x;
			if (x == 1) {
				idx = i;
				idy = j;
			}
		}
	}
	idx = abs(2 - idx);
	idy = abs(2 - idy);
	x = idx + idy;
	cout << x << endl;
	return 0;
}
