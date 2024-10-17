#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<bool> visited;
vector<vector<int>> adj_list;
vector<vector<int>> res;

void DFS(int node, int i)
{
    visited[node - 1] = true;
    for (const int &it : adj_list[node - 1])
        if (!visited[it - 1])
            DFS(it, i);
    res[i].push_back(node);
}

int main()
{
    cin >> n >> m;
    adj_list.resize(n);
    res.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u - 1].push_back(v);
        adj_list[v - 1].push_back(u);
    }
    visited.assign(n, false);
    for (int j = 0; j < n; j++)
    {
        fill(visited.begin(), visited.end(), false);
        DFS(j + 1, j);
        for (const int& x : res[j])
            cout << x << "\t";
        cout << endl;
    }
    return 0;
}
