//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define maxN 105
#define maxM 2005
#define oo 1000000000000000007LL
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

ll add(ll &a, const ll &b) {a = min(a+b, oo);}

ll mul(const ll &a, const ll &b) {
    if (a == 0) return 0;
    if ((a*b)/a != b) return oo;
    return min(oo, a*b);
}

int n, m, z[maxM][maxN];
ll id, cnt[maxM], dp[maxM];
string s[maxN];

int main () {
    scanf("%d%d%lld", &n, &m, &id);
    fto(i, 0, n-1) cin >> s[i];

    cnt[0] = 1;
    fto(i, 1, m) {
        fto(j, 0, n-1) {
            if (i >= sz(s[j])) add(cnt[i], cnt[i-sz(s[j])]);
        }
    }

//    fto(i, 0, m) printf("%lld ", cnt[i]);
//    puts("");

    dp[0] = 1;
    string ans;
    fto(i, 1, m) {
//        debug(i);
        fto(c, 'a', 'z') {
            ll sum = 0;
            fto(j, 0, n-1) {
                fto(p, max(1, i-sz(s[j])+1), min(i, m-sz(s[j])+1)) {
                    if (z[p][j] == i-p && s[j][z[p][j]] == c) {
//                        printf("%d %d\n", j, p);
                        add(sum, mul(dp[p-1], cnt[m-(p+sz(s[j])-1)]));
                        if (sum == oo) break;
                    }
                }
                if (sum == oo) break;
            }
//            printf("%c %lld\n", c, sum);
            if (sum >= id) {
                ans += c;
                fto(j, 0, n-1) {
                    fto(p, max(1, i-sz(s[j])+1), i) {
                        if (z[p][j] == i-p && s[j][z[p][j]] == c) ++z[p][j];
                    }
                    if (i >= sz(s[j]) && z[i-sz(s[j])+1][j] == sz(s[j]))
                        add(dp[i], dp[i-sz(s[j])]);
                }

                break;
            } else id -= sum;
        }

        if (sz(ans) != i) {
            puts("-");
            return 0;
        }
    }

    cout << ans << endl;


    return 0;
}