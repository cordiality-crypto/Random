#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> BFS(int origin, int n, vector<int> adj_list[]) {
    vector<bool> visited(n, false);
    queue<int> pending;
    vector<int> result;

    visited[origin - 1] = true;
    pending.push(origin);
    result.push_back(origin);

    while (!pending.empty()) {
        int curr = pending.front();
        pending.pop();

        for (const int& neighbor : adj_list[curr - 1]) {
            if (!visited[neighbor - 1]) {
                pending.push(neighbor);
                visited[neighbor - 1] = true;
                result.push_back(neighbor);
            }
        }
    }
    return result;
}

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

    vector<int> bfs[n];
    for (int i = 0; i < n; i++) {
        vector<int> temp = BFS(i + 1, n, adj_list);
        bfs[i].clear();
        bfs[i].insert(bfs[i].end(), temp.begin(), temp.end());
    }

    for (int i = 0; i < n; i++) {
        for (const int& it : bfs[i]) {
            cout << it << "\t";
        }
        cout << endl;
    }

    return 0;
}

