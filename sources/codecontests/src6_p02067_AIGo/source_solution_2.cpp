#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i,n) for(int i=0; i<(n); ++i)

int N;
string S;
ll res = 0;

bool ok(int idx) {
    if (idx == 0 or idx == N - 1) return true;
    if (S[idx - 1] == '.' or S[idx + 1] == '.') return true;
    {   // left
        int w = 0, b = 0;
        for (int i = idx - 1; i >= 0; --i) {
            if (S[i] == 'W') ++w;
            if (S[i] == 'B') { ++b; break; }
            if (S[i] == '.') break;
        }
        if (not b) return true;
    }
    {   // right
        int w = 0, b = 0;
        for (int i = idx + 1; i < N; ++i) {
            if (S[i] == 'W') ++w;
            if (S[i] == 'B') { ++b; break; }
            if (S[i] == '.') break;
        }
        if (not b) return true;
    }
    return false;
}

ll f(int idx) {
    ll ret = 0;
    if (idx > 0 and S[idx - 1] != '.') {   // left
        int w = 0, b = 0;
        for (int i = idx - 1; i >= 0; --i) {
            if (S[i] == 'W') { ++w; break; }
            if (S[i] == 'B') ++b;
            if (S[i] == '.') break;
        }
        if (w > 0) {
            ret = max<ll>(ret, b);
        }
    }
    if (idx < N - 1 and S[idx + 1] != '.') {   // right
        int w = 0, b = 0;
        for (int i = idx + 1; i < N; ++i) {
            if (S[i] == 'W') { ++w; break; }
            if (S[i] == 'B') ++b;
            if (S[i] == '.') break;
        }
        if (w > 0) {
            ret = max<ll>(ret, b);
        }
    }
    return ret;
}

int main() {

    cin >> N >> S;

    REP(i, N) {
        if (S[i] == '.') {
            if (ok(i)) {
                res = max<ll>(res, f(i));
                // cout << i << ' ' << res << endl;
            }
        }
    }

    cout << res << endl;

}
