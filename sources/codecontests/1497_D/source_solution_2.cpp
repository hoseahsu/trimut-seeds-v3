#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N = 5e3 + 10;
const LL inf = 1e15;
int n;
LL f[N], a[N], ne[N];
int tag[N];

int main()
{
    int __;
    cin >> __;
    while (__ --)
    {
        cin >> n;
        for (int i = 1; i <= n; i ++)   cin >> tag[i];
        for (int i = 1; i <= n; i ++)   cin >> a[i];
        for (int i = 1; i <= n; i ++)   f[i] = 0;
        for (int i = 2; i <= n; i ++)
        {
            for (int j = 1; j <= n; j ++)   ne[j] = 0;
            LL maxn = 0;
            for (int j = 1; j < i; j ++)
            {
                LL g = 0;
                if (tag[j] == tag[i])
                    g = -inf;
                else
                    g = f[j] + abs(a[j] - a[i]);
                maxn = max(maxn, g);
                ne[j - 1] = g;
            }
            
            LL p = -inf;
            for (int j = i - 1; j >= 1; j --)
            {
                p = max(p, ne[j]);
                if (tag[i] == tag[j])   continue;
                f[j] = max(f[j], p + abs(a[j] - a[i]));
            }
            
            f[i] = max(f[i], maxn);
        }
        
        LL res = 0;
        for (int i = 1; i <= n; i ++)
            res = max(res, f[i]);
        cout << res << endl;
    }
}