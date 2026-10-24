#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, H, S;
    while (cin >> T >> H >> S, T != -1) {
        int r = 7200 - T*3600 - H*60 - S;
        int r3 = r*3;
        printf("%02d:%02d:%02d\n", r/3600, r/60%60, r%60);
        printf("%02d:%02d:%02d\n", r3/3600, r3/60%60, r3%60);
    }
    return 0;
}
