#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

const int IINF = INT_MAX;

struct Data{
  int x,y,oxygen,left,right,money;
  bool operator < ( const Data& data ) const {
    if( money != data.money )return money > data.money;
    return oxygen < data.oxygen;
  }
};

int H,W,f,m,o,c[20][20],dp[20][20][60][20][20];
int dx[] = {-1,+1};
int dy[] = {+0,+0};

bool isValid(int x,int y){ return 0 <= x && x < W && 0 <= y && y <= H; }


int main(){
  while( cin >> W >> H, W|H ){
    cin >> f >> m >> o;
    rep(i,W) c[0][i] = 0;
    rep(i,H) rep(j,W) cin >> c[i+1][j];
    rep(i,H+2) rep(j,W) rep(k,m+1) rep(y,W) rep(x,W) dp[i][j][k][y][x] = IINF;
    priority_queue<Data> Q;
    rep(i,W) {
      dp[0][i][o][i][i] = 0;
      Q.push((Data){i,0,o,i,i,0});
    }
    

    int ans = IINF;
    while( !Q.empty() ){
      Data data = Q.top(); Q.pop();

      if( data.y == H ) {
        ans = data.money;
        break;
      }
      if( data.oxygen <= 1 ) continue;
      int oxygen = data.oxygen - 1;
      assert( oxygen >= 1 );
      rep(i,2){
        int nx = data.x + dx[i], ny = data.y + dy[i], left = data.left, right = data.right;
        if( !isValid(nx,ny) ) continue;
        int nmoney = data.money;
        int noxygen = oxygen;
        if( left > nx || right < nx ) {
          if( c[ny][nx] < 0 ) nmoney  -= c[ny][nx];
          else                noxygen += c[ny][nx];
        }
        noxygen = min(noxygen,m);
        if( dp[ny][nx][noxygen][min(left,nx)][max(right,nx)] > nmoney ) {
          dp[ny][nx][noxygen][min(left,nx)][max(right,nx)] = nmoney;
          Q.push((Data){nx,ny,noxygen,min(left,nx),max(right,nx),nmoney});
        }
      }

      int nx = data.x, ny = data.y + 1, nmoney = data.money, noxygen = oxygen;
      if( c[ny][nx] < 0 ) nmoney  -= c[ny][nx];
      else                noxygen += c[ny][nx];
      noxygen = min(noxygen,m);
      if( dp[ny][nx][noxygen][nx][nx] > nmoney ) {
        dp[ny][nx][noxygen][nx][nx] = nmoney;
        Q.push((Data){nx,ny,noxygen,nx,nx,nmoney});
      }
    }
    if( ans == IINF || ans > f ) puts("NA");
    else cout << ans << endl;
  }
  return 0;
}