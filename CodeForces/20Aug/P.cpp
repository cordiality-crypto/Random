#include <bits/stdc++.h>
using namespace std;

int operations(vector<pair<int, int>> nums, int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        unordered_map<int, int> map;
        for (int i = 0; i < N; i++) {
            int val;
            cin >> val;
            map[val]++;
        }
        vector<pair<int, int>> arr;
        for (auto &it : map) 
            arr.push_back({it.first, it.second});
        cout << N - operations(arr, N) << endl;
    }
    return 0;
}

int operations(vector<pair<int, int>> nums, int N) {
    priority_queue<int> heap;
    for (pair<int, int> num : nums) 
        heap.push(num.second);
    return heap.top();
}