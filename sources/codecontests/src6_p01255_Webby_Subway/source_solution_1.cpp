// Oh, this is a fake solution!
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <complex>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef complex<int> P;

int bitcount(int a) {
    int c = 0;
    while (a) c++, a&=a-1;
    return c;
}

inline double cross(const P& a, const P& b) { return imag(conj(a)*b); }
inline double dot(const P& a, const P& b) { return real(conj(a)*b); }

inline int ccw(const P& a, P b, P c) {
    b -= a, c -= a;
    if (cross(b, c) > 0) return 1;
    if (cross(b, c) < 0) return -1;
    if (dot(b, c) < 0) return 2;
    if (norm(b) < norm(c)) return -2;
    return 0;
}

inline bool intersectSS(const P& s0, const P& s1, const P& t0, const P& t1) {
    return ccw(s0, s1, t0) * ccw(s0, s1, t1) <= 0
        && ccw(t0, t1, s0) * ccw(t0, t1, s1) <= 0;
}

int n, g[32], m[32];
P ps[32][32];

int main() {
    for (;;) {
        scanf("%d", &n);
        if (n == 0) return 0;
        rep (i, n) {
            int x, y;
            scanf("%d", m+i);
            rep (j, m[i]) {
                scanf("%d%d", &x, &y);
                ps[i][j] = P(x, y);
            }
        }
        memset(g, 0, sizeof(g));
        rep (i, n) g[i] |= 1<<i;
        rep (i, n) rep (j, m[i]-1) rep (x, i) rep (y, m[x]-1) {
            if (intersectSS(ps[i][j], ps[i][j+1], ps[x][y], ps[x][y+1])) {
                g[i] |= 1<<x, g[x] |= 1<<i;
            }
        }
        const int nn = 1<<n;
        int ans = 0;
        rep (b, nn) {
            bool f = true;
            rep (i, n) if ((b&(1<<i)) && (g[i]&b)!=b) {
                f = false;
                break;
            }
            if (f) ans = max(ans, bitcount(b));
        }
        printf("%d\n", ans);
    }
}