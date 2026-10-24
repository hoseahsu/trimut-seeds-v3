#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    while(cin >> n, n) {
        string res;
        while(n > 0) {
            int oct = n & 7;
            if(oct <= 3) {
                res += '0' + oct;
            } else if(4 == oct) {
                res += '0' + oct + 1;
            } else {
                res += '0' + oct + 2;
            }
            n >>= 3;
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
}
