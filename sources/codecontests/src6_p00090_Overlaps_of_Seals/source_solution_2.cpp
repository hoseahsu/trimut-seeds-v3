#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;

typedef struct circle
{
    double x, y;
} cir;

int main()
{
    int n;
    while (cin >> n, n)
    {
        cir c[n];
        char ch;
        rep(i, n) cin >> c[i].x >> ch >> c[i].y;

        int maxv = 0;

        for (double i = 0; i <= 10; i += 0.1)
        {
            for (double j = 0; j <= 10; j += 0.01)
            {
                int cnt = 0;
                rep(k, n)
                {
                    if (sqrt(pow(i - c[k].x, 2) + (pow(j - c[k].y, 2)) <= 1.001))
                        cnt++;
                }
                maxv = max(maxv, cnt);
            }
        }
        OP(maxv);
    }
    return 0;
}
