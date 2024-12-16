#include <bits/stdc++.h>
using namespace std;

unsigned long long REQUIRED_TILES(unsigned long long m, unsigned long long n, unsigned long long a) {
    m = ceil((double)m / a);
    n = ceil((double)n / a);
    return m * n;
}

int main() {
    unsigned long long  m, n, a;
    cin >> m >> n >> a;
    cout << REQUIRED_TILES(m, n, a) << endl;
    return 0;
}

