#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<N;i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
int main(){
  int N; cin>>N;
  vvi F(N,vi(10)),P(N,vi(11));
  rep(i,N) rep(j,10) cin>>F[i][j];
  rep(i,N) rep(j,11) cin>>P[i][j];
  ll ans = -1e9;
  for(int i=1;i<(1<<10);i++){
    ll bene = 0;
    rep(j,N){
      int cnt = 0;
      rep(k,10) if(i & (1<<k) && F[j][k]) cnt++;
      bene += P[j][cnt];
    }
    ans = max(ans,bene);
  }
  cout<<ans<<endl;
  return 0;
}
