#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x = 0;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s == "X++" || s == "++X")
			x += 1;
		else
			x -= 1;
	}
	cout << x << endl;
}
