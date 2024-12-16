#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        uint64_t b, c, d, a = 0;
        cin >> b >> c >> d;
        bool flag = false;
        
        for (int i = 0; i < 62; ++i) { 
            uint64_t bitB = (b >> i) & 1;
            uint64_t bitC = (c >> i) & 1;
            uint64_t bitD = (d >> i) & 1;
            uint64_t bitA = 0; 
            if (bitB == 0) {
                if (bitC == 0) {
                    if (bitD == 0) {
                        bitA = 0;
                    } else {
                        bitA = 1;
                    }
                } else {
                    if (bitD == 0) {
                        bitA == 0;
                    } else {
                        flag = true;
                        break;
                    }
                }
            } else {
                if (bitC == 0) {
                    if (bitD == 0) {
                        flag = true;
                        break;
                    } else {
                        bitA = 0;
                    }
                } else {
                    if (bitD == 0) {
                        bitA = 1;
                    } else {
                        bitA = 0;
                    }
                }
            }
            a |= (bitA << i);
        }
        
        if (flag) {
            cout << -1 << endl;
        } else {
            cout << a << endl;
        }
    }
    
    return 0;
}
