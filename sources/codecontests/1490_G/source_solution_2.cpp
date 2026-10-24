#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct tr { ll r, s; int i; };
bool g(tr &a, tr &b) {
    if(a.r == b.r && a.s == b.s) return a.i < b.i;
    else if(a.r == b.r) return a.s > b.s;
    else return a.r < b.r;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n,m; cin>>n>>m;
        vector<ll> a(n);
        vector<pair<ll, pair<ll, int>>> p(n);
        map<ll, int> mp;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            p[i].first = a[i] + (i > 0 ? p[i-1].first : 0);
            if(i == 0 || p[i].first > p[i-1].second.first) {
                p[i].second.first = p[i].first; p[i].second.second = i;
            } else {
                p[i].second.first = p[i-1].second.first; p[i].second.second = p[i-1].second.second;
            }
            mp[p[i].first] = i+1;
        }
        ll s = p[n-1].first;
        for (int i = 0; i < m; ++i) {
            ll x; cin>>x;
            int l = -1, r = p[n-1].second.second+1; ll mx = p[n-1].second.first;
            ll ans = (s <= 0 ? 0 : max(0LL, x-mx)/s + (max(0LL, x-mx) % s != 0));
            while(l + 1 < r) {
                int mid = (l + r) / 2;
                if(ans * s + p[mid].second.first >= x) r = mid;
                else l = mid;
            }
            if(r == p[n-1].second.second+1) cout << "-1 ";
            else cout << ans*n + p[r].second.second << " ";
        }
        cout << "\n";
    }
}
