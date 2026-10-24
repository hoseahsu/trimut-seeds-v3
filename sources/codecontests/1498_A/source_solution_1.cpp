#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
#include<cmath>
#include<deque>
#include<memory.h>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cstdio>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<string>
using namespace std;
#define ll long long
#define ull unsigned long long
#define Design ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / GCD(a, b); }
const ll N = 1e5 + 7;
const ll inf = 1e18 + 1;
const ll mod = 998244353;
const double eps = 1e-8;
ll t, n;
ll getsum(ll n) {
    ll res = 0;
    while (n)res += n % 10, n /= 10;
    return res;
}
int main() {
    Design;
    cin >> t;
    while (t--) {
        cin >> n;
        while (1) {
            ll sum = getsum(n);
            if (GCD(sum, n) >= 2)break;
            n++;
        }
        cout << n << "\n";
    }
    return 0;
}
