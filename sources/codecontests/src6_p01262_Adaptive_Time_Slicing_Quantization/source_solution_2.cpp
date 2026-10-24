#include <cstdio>
#include <algorithm>
#include <cmath>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;

const double EPS = 1e-9;

double memo[260][260];
double data[260];
int n, m, l;

double dp[260][260];

inline double dbl(double a){ return a * a; }

int main(){
  while(scanf("%d%d%d", &n, &m, &l), n + m + l){
    REP(i,n) scanf("%lf", data + i);
    for(int len = 2; len <= n; len++){
      for(int start = 0; start + len <= n; start++){
        double mx = *max_element(data + start, data + start + len);
        double mn = *min_element(data + start, data + start + len);
        double dst = (mx - mn) / ((1 << l) - 1);

        double gosa = 0.0;

        if(dst > EPS){
          REP(i,len){
            double sa = data[start + i] - mn;
            int j = (int)floor(sa / dst + 0.5);
            double tmp = 1e10;
            for(int ii = j - 1; ii <= j + 1; ii++)
              tmp = min(tmp, dbl((mn + dst * ii) - data[start + i]));
            gosa += tmp;
          }
        }

        memo[start][start + len] = gosa;
      }
    }

    const double inf = 1e10;
    REP(i,n + 1) REP(j, m + 1)
      dp[i][j] = inf;

    dp[0][0] = 0.0;
    REP(i,n) REP(j,m) if(dp[i][j] != inf){
      for(int len = 2; i + len <= n; len++)
        dp[i + len][j + 1] = min(dp[i + len][j + 1], dp[i][j] + memo[i][i + len]);
    }

    printf("%.8f\n", dp[n][m]);
  }
  return 0;
}