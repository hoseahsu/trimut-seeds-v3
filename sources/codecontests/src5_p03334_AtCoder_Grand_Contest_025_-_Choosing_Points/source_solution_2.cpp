#include <bits/stdc++.h>
using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int N, D1, D2;

signed main() {
    cin >> N >> D1 >> D2;
    int p1 = 0, p2 = 0;
    while (D1 % 2 == 0) {D1 /= 2; p1++;}
    while (D2 % 2 == 0) {D2 /= 2; p2++;}
    int n = 0;
    for (int i = 0; i < 2 * N; i++) {
        for (int j = 0; j < 2 * N; j++) {
            bool sw1, sw2;

            if (p1 % 2 == 0)sw1 = (i / (1 << (p1 / 2)) % 2 == j / (1 << (p1 / 2)) % 2);
            else sw1 = (i / (1 << (p1 / 2)) % 2 == 0);

            if (p2 % 2 == 0)sw2 = (i / (1 << (p2 / 2)) % 2 == j / (1 << (p2 / 2)) % 2);
            else sw2 = (i / (1 << (p2 / 2)) % 2 == 0);

            if (sw1 && sw2) {cout << i << " " << j << endl; n++;}
            if (n == N * N)return 0;
        }
    }
}