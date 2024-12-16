#include <bits/stdc++.h>
#define let long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        priority_queue<let, vector<let>, greater<let>> pq;
        for (int i = 0; i < n; i++)
        {
            let x;
            cin >> x;
            pq.push(x);
        }
        while (pq.size() > 1)
        {
            let a = pq.top();
            pq.pop();
            let b = pq.top();
            pq.pop();
            let avg = (a + b) / 2;
            pq.push(avg);
        }
        cout << pq.top() << endl;
    }
    return 0;
}
