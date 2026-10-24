#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

const int MAXN = 50005;
const double INF = 100000000000;
int n;

int t[MAXN];
int sum(int idx)
{
    int res = 0;
    while (idx)
    {
        res += t[idx];
        idx -= (idx & -idx);
    }
    return res;
}

void upd(int idx, int val)
{
    int old_val = sum(idx) - sum(idx-1);
    while (idx <= n)
    {
        t[idx] += (val - old_val);
        idx += (idx & -idx);
    }
}


struct line
{
    double A, B, C;
} L[MAXN];

pair <double, int> cross[MAXN];

bool compX(line A, line B)
{
    return -(A.B/A.A) > -(B.B/B.A);
}

bool compY(line A, line B)
{
    return -(A.A/A.B) > -(B.A/B.B);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> L[i].A >> L[i].B >> L[i].C;

    int HALF = (n*(n-1)/2 + 1) / 2;

    sort(L, L + n, compX);
    double l = -INF;
    double r = INF;
    for (int q = 0; q < 100; q++)
    {
        double m = (l + r) / 2;
        for (int i = 0; i < n; i++)
        {
            cross[i].ff = (L[i].C - L[i].B*m) / L[i].A;
            cross[i].ss = i+1;
        }
        sort(cross, cross + n);
        for (int i = 0; i < n; i++)
            upd(i+1, 1);

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += sum(cross[i].ss - 1);
            upd(cross[i].ss, 0);
        }

        if (res >= HALF)
            r = m;
        else l = m;
    }
    double ansY = r;
    sort(L, L + n, compY);
    l = -INF;
    r = INF;
    for (int q = 0; q < 100; q++)
    {
        double m = (l + r) / 2;
        for (int i = 0; i < n; i++)
        {
            cross[i].ff = (L[i].C - L[i].A*m) / L[i].B;
            cross[i].ss = i+1;
        }
        sort(cross, cross + n);

        for (int i = 0; i < n; i++)
            upd(i+1, 1);

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += sum(cross[i].ss - 1);
            upd(cross[i].ss, 0);
        }

        if (res >= HALF)
            r = m;
        else l = m;
    }
    double ansX = r;

    cout << setprecision(13) << fixed << ansX << " " << ansY;
    return 0;
}
