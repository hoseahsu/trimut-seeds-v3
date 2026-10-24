#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)

#define int long long

int N,D[2];
int bit[1010][1010];
signed main(){
  cin >> N >> D[0] >> D[1];
  for(int c = 0;c < 2;c++){
    int d = D[c];
    int p = 0;
    while(d % 2 == 0){
      p++;
      d /= 2;
    }
    if(p & 1){
      // ボーダー
      int h = (1 << (p / 2));
      rep(i,0,N * 2 - 1) rep(j,0,N * 2 - 1){
        if((j % (h * 2)) >= h) bit[i][j] = 1;
      }
    }
    else{
      int h = (1 << (p / 2));
      rep(i,0,N * 2 - 1) rep(j,0,N * 2 - 1){
        if(((i % (h * 2)) >= h) xor ((j % (h * 2)) >= h)){
          bit[i][j] = 1;
        }
      }
    }
  }

  int cou = 0;
  rep(i,0,N * 2 - 1) rep(j,0,N * 2 - 1){
    if(!bit[i][j]){
      cou++;
      cout << i << " " << j << endl;
    }
    if(cou == N * N) return 0;
  }
  if(cou != N * N){
    int a = 0;
    cout << 4 / a << endl;
  }
}
