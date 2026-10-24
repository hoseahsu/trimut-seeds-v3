#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#include<string>
#include<sstream>
#include<numeric>
#include<cassert>
#include<complex>

#define f first
#define s second
#define mp make_pair

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define rep(i,s,n) for(int i=(s); i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define IN(x,s,g) ((x) >= (s) && (x) < (g))
#define ISIN(x,y,w,h) (IN((x),0,(w)) && IN((y),0,(h)))
#define print(x) printf("%d\n",x)
#define EPS (1e-4)

using namespace std;

typedef unsigned int uint;
typedef long long ll;

const int _dx[] = {0,1,0,-1};
const int _dy[] = {-1,0,1,0};

int getInt(){
  int ret = 0,c;
  c = getchar();
  while(!isdigit(c)) c = getchar();
  while(isdigit(c)){
    ret *= 10;
    ret += c - '0';
    c = getchar();
  }
  return ret;
}

#define HASH(x) (x[0] + x[1]*4 + x[2]*16 + x[3]*64)

int dp[200][4][256];
int rev[4][4];
int board[5][5];

int ten[4] = { 0,60,70,80 };
int nn;

int solve(int now, int h){
  if(dp[nn][now][h] != -1) return dp[nn][now][h];
  int ret = 0;
  int *x = rev[now];

  for(x[0]=0;x[0]<4;x[0]++){
    for(x[1]=0;x[1]<4;x[1]++){
      for(x[2]=0;x[2]<4;x[2]++){
        for(x[3]=0;x[3]<4;x[3]++){
          int point = 0;
          REP(i,5){
            int p = board[now][i];
            if(p == 0) continue;
            p = p - 1;
            if(now != 0){
              if(i != 4) p += rev[now-1][i];
              if(i != 0) p += rev[now-1][i-1];
            }
            if(i != 4) p += rev[now][i];
            if(i != 0) p += rev[now][i-1];
            p = p % 4;
            point += ten[p];
          }

          if(now == 3){
            REP(i,5){
              int p = board[now+1][i];
              if(p == 0) continue;
              p = p - 1;
              if(i != 4) p += rev[now][i];
              if(i != 0) p += rev[now][i-1];
              p = p % 4;
              point += ten[p];
            }
            ret = max(ret, point);
          }else{
            int hash = HASH(x);
            ret = max(ret, point + solve(now+1,hash));
          }
        }
      }
    }
  }
  return dp[nn][now][h] = ret;
}

int main(){
  int n = getInt();
    memset(dp, -1, sizeof(dp));
  for(nn = 0; nn < n; nn++){
    REP(i,5) REP(j,5) board[i][j] = getInt();
    print(solve(0,0));
  }
  return 0;
}