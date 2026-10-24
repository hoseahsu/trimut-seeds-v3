#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 2147483600

int main(){
  const int N=100000;
  vector<vector<double>> dp(N+1, vector<double>(21,0));
  dp[0][0]=1;
  rep(i,N) rep(j,20){
    dp[i+1][j+1] = dp[i][j] / (1<<j);
    dp[i+1][0] += dp[i][j] - dp[i+1][j+1];
  }
  vector<double> acc(N+1,0);
  rep(i,N) acc[i+1] = acc[i] + (1. - dp[i+1][0]);
  int n;
  while(cin>>n, n){
    printf("%.3f\n", acc[n]);
  }

  return 0;
}