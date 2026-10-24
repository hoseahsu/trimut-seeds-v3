#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<sstream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<climits>
#include<map>
#include<climits>
#include<set>
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define INF 1<<27
#define F first
#define S second
#define MIN INT_MIN
using namespace std;
typedef pair<int,int> P;
 int dp[55][55][10][10];

  int info[55][3];
int main(){
  int n,m;
  cin >> n >> m;

  for(int i=0;i<n;i++){
    cin >> info[i][0] >> info[i][1] >> info[i][2];
  }


 
  rep(i,55)rep(j,55)rep(k,10)rep(l,10)dp[i][j][k][l] = MIN;
  rep(i,m+2)dp[0][m-i][i][0] = 0;

  rep(i,n){
    rep(j,m+1){//のこり
      rep(k,9){//今
	rep(l,9){//５分前
	  if(j+k+l > m)break;
	  if(dp[i][j][k][l] == MIN )continue;
	  int isol = l;

	  int mex = info[i][2];
	 
	  rep(x,k+1){
	    rep(y,isol+1){
	      if(x+y > 8)break;
	      if(x == 0 && y == 0)continue;
	      mex = max(mex,info[i][0]*x+info[i][1]*y);
	    }
	  }
	  
	  rep(z,j+1){
	    dp[i+1][j-z][z][k] = max(dp[i+1][j-z][z][k],dp[i][j][k][l]+mex);
	  }
	}
      }
    }
  }
  int ans = MIN;
  rep(i,m+1){
    rep(j,9){
      rep(k,9){
	if(j+k > 8)continue;
	ans = max(ans,dp[n][i][j][k]);
      }
    }
  }
  cout << ans << endl;

return 0;
}