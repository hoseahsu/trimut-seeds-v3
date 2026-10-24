#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int t,n,m,k;
vector<tuple<int,int,int> > ed;
int pa[N];
vector<int> res;

int root(int x){ if(pa[x]==x) return x; return pa[x] = root(pa[x]); }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        ed.clear();
        res.clear();
        cin >> n >> m >> k;
        for(int i = 1;i <= n;i++) pa[i] = i;
        for(int i = 0;i < m;i++)
        {
            int a,b,d;
            cin >> a >> b >> d;
            ed.push_back({d,a,b});
        }
        int mx = 0;
        sort(ed.begin(),ed.end());
        for(auto [d,a,b] : ed)
        {
            if(root(a)==root(b)) continue;
            pa[root(a)] = root(b);
            mx = d;
            res.push_back(d);
        }
        long long ans = 0;
        for(int x : res) if(x>k) ans+=x-k;
        if(ans){ cout << ans << '\n'; continue; }
        ans = k-res.back();
        for(auto [d,a,b] : ed)
        {
            if(d>res.back()) ans = min(ans,(long long)abs(k-d));
        }
        cout << ans << '\n';
    }
}
