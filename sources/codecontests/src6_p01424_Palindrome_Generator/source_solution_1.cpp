#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

#define DO(n) for ( int ____n = n; ____n-->0; )
#define REP(i, n) for (int i=0;i<n;++i)
#define FOR(i, a, b) for (int i=a;i<b;++i)
#define DWN(i, b, a) for (int i=b-1;i>=a;--i)
#define REP_1(i, n) for (int i=1;i<=n;++i)
#define FOR_1(i, a, b) for (int i=a;i<=b;++i)
#define DWN_1(i, b, a) for (int i=b;i>=a;--i)
#define ECH(it, A) for (__typeof(A.begin()) it = A.begin(); it != A.end(); ++it)
#define RST(A) memset(A, 0, sizeof(A))
#define FLC(A, x) memset(A, x, sizeof(A))
#define PB push_back

template<class T> void checkMax(T &a, T b){
    if (b > a) a = b;
}

typedef double DB;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;

const int N = int(1e2) + 9, M = 20;
char str[N][M+1]; int slen[N]; VI adj[N], radj[N];

int vis[N][N][M+M+1]; int dp[N][N][M+M+1];
int n, m;


int f(int i0, int i1, int j){

    int &z = dp[i0][i1][j+M], &v = vis[i0][i1][j+M];

    if (v == 3) return z;

    if (v == 1){
        v = 2;
        return -INF;
    }

    v = 1; z = j ? -INF : 0;

    if (j > 0){
        ECH(it, radj[i0]){
            int i00 = *it; bool ok = true;

            int up = min(j, slen[i00]); REP(k, up){
                if (str[i00][slen[i00]-1-k] != str[i1][slen[i1]-j+k]){
                    ok = false;
                    break;
                }
            }

            if (!ok) continue;
            checkMax(z, f(i00, i1, j-slen[i00]) + slen[i00]);
        }
    }
    else{

        j = -j;

        ECH(it, adj[i1]){
            int i11 = *it; bool ok = true;

            int up = min(j, slen[i11]); REP(k, up){
                if (str[i0][j-1-k] != str[i11][k]){
                    ok = false;
                    break;
                }
            }

            if (!ok) continue;
            checkMax(z, f(i0, i11, slen[i11]-j) + slen[i11]);
        }
    }

    if (z >= 0 && v == 2) z = INF;
    v = 3;


    //if (z >= 0)
    //cout << ")" << i0 << " " << i1 << " " << j << " " << v << " "<< z << endl;
    //cout << i0 << " " <<i1 << " " << j << ": " << z << " "<<v << endl;
    return z;
}

bool isPalindrome(int i0, int l, int r){
    int len = r-l;
    REP(i, len/2) if (str[i0][l+i] != str[i0][r-1-i]) return false;
    return true;
}

int main(){

#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d%d", &n, &m)){

        REP(i, n){
            scanf("%s", str[i]); adj[i].clear(), radj[i].clear();
            slen[i] = strlen(str[i]);
        }

        DO(m){
            int a, b; scanf("%d%d", &a, &b); --a, --b;
            adj[a].PB(b); radj[b].PB(a);
        }

        FLC(dp, -1); RST(vis); int z = 0; REP(i, n) REP(j, slen[i]+1){
            if (isPalindrome(i, 0, slen[i]-j) && f(i, i, j) >= 0) checkMax(z, f(i, i, j) + slen[i]);
            if (isPalindrome(i, j, slen[i]) && f(i, i, -j) >= 0) checkMax(z, f(i, i, -j) + slen[i]);
        }

        if (z >= INF) z = -1;
        printf("%d\n", z);
    }
}