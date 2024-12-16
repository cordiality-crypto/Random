#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 0, n = s.size(); i < n; i += 1) {
		s[i] = '0' +  std::min(int(s[i] - '0'), int(9 - (s[i] - '0')));
	}
	if (s.front() == '0')
		s.front() = '9';
	cout << s << endl;
	return 0;
}
