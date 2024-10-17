#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj_list[n];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj_list[u - 1].push_back(v);
		adj_list[v - 1].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		cout << (i + 1) << "\t";
		for (const int& it : adj_list[i])
			cout << it << "\t";
		cout << endl;
	}
	return 0;
}
