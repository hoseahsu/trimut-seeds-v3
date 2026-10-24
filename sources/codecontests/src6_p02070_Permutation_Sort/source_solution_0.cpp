#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <complex>
#include <numeric>
#include <string.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
double PI = 3.141592653589793238462643383279;
const double EPS = 1e-9;
const ll MOD = 998244353;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

int N;
int P[200], Q[200];
bool saw[200];
vector<pl> v;

ll gcd (ll x, ll y) {
    if (y == 0) return x;
    return gcd(y, x%y);
}

int main() {
    cin >> N;
    rep(i,N) cin >> P[i];
    rep(i,N) cin >> Q[i];
    rep(i,N) {
        P[i]--;
        Q[i]--;
    }
    {
        bool zero = true;
        rep(i,N) {
            if (P[i] != i) {
                zero = false;
            }
        }
        if (zero) {
            cout << 0 << endl;
            return 0;
        }
    }
    rep(i,N) P[i] = Q[P[i]];
    rep(i,N) {
        if (saw[i]) continue;
        ll a = 1;
        vector<int> tmp;
        {
            tmp.push_back(P[i]);
            int pos = Q[P[i]];
            while (pos != P[i]) {
                tmp.push_back(pos);
                pos = Q[pos];
                a++;
            }
        }
        //rep(j,tmp.size()) saw[tmp[j]] = true;
        ll b = -1;
        rep(j,tmp.size()) {
            if (tmp[j] == i) {
                b = j;
                break;
            }
        }
        if (b == -1) {
            cout << -1 << endl;
            return 0;
        }
        v.push_back(pl(a,b));
    }
    if (v.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    pl now = v[0];
    for (int i = 1; i < v.size(); i++) {
        ll t = now.second;
        ll l = now.first * v[i].first / gcd(now.first, v[i].first);
        ll cnt = 0;
        while (true) {
            if (t >= v[i].second && (t-v[i].second)%v[i].first == 0) {
                break;
            }
            t += now.first;
            cnt++;
            if (cnt > v[i].first) {
                cout << -1 << endl;
                return 0;
            }
        }
        now.first = l;
        now.second = t;
    }
    cout << now.second+1 << endl;
}
