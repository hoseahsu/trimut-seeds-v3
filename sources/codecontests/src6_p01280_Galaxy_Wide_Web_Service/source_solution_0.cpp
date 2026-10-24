#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<iomanip>
#include<set>
#include<numeric>
#include<sstream>
#include<random>
#include<cassert>
#include<complex>
#include<list>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rrep(i, st, n) for (int i = st; i < n; ++i)
using pii = pair<int, int>;
const int inf = 1e9 + 7;
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};
#define ceil(a, b) a / b + !!(a % b)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)

int n;
int d[101], t[101];
vector<int> q[101];
int ans_prime(int p) {
    int ret = 0;
    int c = 0;
    while (c++ < p) {
        int tmp = 0;
        rep(i, n) {
            if (d[i] == p) {
                tmp += q[i][t[i]];
                t[i] = (t[i] + 1 == q[i].size() ? 0 : t[i] + 1);
            }
        }
        chmax(ret, tmp);
    }
    return ret;
}
int main() {
    while (cin >> n && n) {
        rep(i, n) { //input phase
            q[i].resize(0);
            cin >> d[i] >> t[i];
            rep(j, d[i]) {
                int q_; cin >> q_; q[i].push_back(q_);
            }
        }
        int c = 0;
        int ans = 0;
        while (c++ < 55440) {
            int tmp = 0;
            rep(i, n) {
                if (d[i] == 13 || d[i] == 17 || d[i] == 23 || d[i] == 19) continue;
                tmp += q[i][t[i]];
                t[i] = (t[i] + 1 == q[i].size() ? 0 : t[i] + 1);
            }
            chmax(ans, tmp);
        }
        ans += ans_prime(13);
        ans += ans_prime(17);
        ans += ans_prime(19);
        ans += ans_prime(23);
        cout << ans << endl;
    }
    
}

