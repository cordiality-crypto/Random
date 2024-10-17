#include <bits/stdc++.h>
using namespace std;

unordered_map<char, pair<int, int>> keys;

void initialise() {
    keys.insert({'Q', {1, 1}});
    keys.insert({'W', {1, 2}});
    keys.insert({'E', {1, 3}});
    keys.insert({'R', {1, 4}});
    keys.insert({'T', {1, 5}});
    keys.insert({'Y', {1, 6}});
    keys.insert({'U', {1, 7}});
    keys.insert({'I', {1, 8}});
    keys.insert({'O', {1, 9}});
    keys.insert({'P', {1, 10}});
    keys.insert({'A', {2, 1}});
    keys.insert({'S', {2, 2}});
    keys.insert({'D', {2, 3}});
    keys.insert({'F', {2, 4}});
    keys.insert({'G', {2, 5}});
    keys.insert({'H', {2, 6}});
    keys.insert({'J', {2, 7}});
    keys.insert({'K', {2, 8}});
    keys.insert({'L', {2, 9}});
    keys.insert({'Z', {3, 2}});
    keys.insert({'X', {3, 3}});
    keys.insert({'C', {3, 4}});
    keys.insert({'V', {3, 5}});
    keys.insert({'B', {3, 6}});
    keys.insert({'N', {3, 7}});
    keys.insert({'M', {3, 8}});
}

int getDistance(string word) {
    initialise();
    int n = word.size();
    pair<int, int> coor = keys['Q'];
    int k = coor.first, j = coor.second;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        coor = keys[word[i]];
        int curr_i = coor.first, curr_j = coor.second;
        sum += std::abs(curr_i - k) + std::abs(curr_j - j);
        k = curr_i;
        j = curr_j;
    }    
    return sum;
}

int main() {
    string s;
    cin >> s;
    cout << getDistance(s) << endl;
}
