#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int adj_mat[n][n];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj_mat[u - 1][v - 1] = adj_mat[v - 1][u - 1] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << adj_mat[i][j] << "\t";
		cout << "\n";
	}
	return 0;
}
