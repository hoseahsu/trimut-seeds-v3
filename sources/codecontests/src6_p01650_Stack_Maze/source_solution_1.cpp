#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF INT_MAX/3
#define mod 1000000007

int h,w;
int dp[55][55][55][55];
string s[55];
vector<P> nxt[55][55];

int dfs(int i1,int j1,int i2,int j2){

  if(s[i1][j1]=='#')return -INF;
  if(i1==i2&&j1==j2)return 0;
  if(dp[i1][j1][i2][j2]!=-1)return dp[i1][j1][i2][j2];

  if((i1+1==i2&&j1==j2)||(i1==i2&&j1+1==j2)){
    if('a'<=s[i1][j1]&&s[i1][j1]<='z'&&s[i1][j1]-'a'==s[i2][j2]-'A')return 1;
    else{
      if(s[i2][j2]=='#')return -INF;
      else return 0;
    }
  }

  int res=-INF;
  if(i1<i2)maxch(res,dfs(i1+1,j1,i2,j2));
  if(j1<j2)maxch(res,dfs(i1,j1+1,i2,j2));

  if('a'<=s[i1][j1]&&s[i1][j1]<='z'){
    if('A'<=s[i2][j2]&&s[i2][j2]<='Z'&&s[i2][j2]-'A'==s[i1][j1]-'a'){
      rep(d1,2){
        rep(d2,2){
          int ni1,nj1,ni2,nj2;
          if(d1==0){
            ni1=i1; nj1=j1+1;
          }else{
            ni1=i1+1; nj1=j1;
          }
          if(d2==0){
            ni2=i2; nj2=j2-1;
          }else{
            ni2=i2-1; nj2=j2;
          }
          if(ni1<=ni2&&nj1<=nj2){
            int v1=dfs(ni1,nj1,ni2,nj2);
            if(v1!=-INF)maxch(res,v1+1);
          }
        }
      }
    }
    for(P p : nxt[i1][j1]){
      if(!(p.fi<=i2&&p.se<=j2))continue;
      if(p.fi==i2&&p.se==j2)continue;
      int v1=dfs(i1,j1,p.fi,p.se);
      int v2=dfs(p.fi,p.se,i2,j2);
      if(v1!=-INF&&v2!=-INF)maxch(res,v1+v2);
    }
  }

  return dp[i1][j1][i2][j2]=res;
}

int main(){
  while(1){
    cin>>h>>w;
    if(h==0)break;
    rep(i,h)cin>>s[i];

    rep(i,h)rep(j,w){
      nxt[i][j].clear();
      if('a'<=s[i][j]&&s[i][j]<='z'){
        repl(k,i,h)repl(l,j,w){
          if('A'<=s[k][l]&&s[k][l]<='Z'&&s[k][l]-'A'==s[i][j]-'a'){
            nxt[i][j].push_back(P(k,l));
          }
        }
      }
    }

    rep(i,h)rep(j,w)rep(k,h)rep(l,w)dp[i][j][k][l]=-1;

    int res=dfs(0,0,h-1,w-1);
    if(res==-INF)cout<<-1<<endl;
    else cout<<res<<endl;
  }
  return 0;
}

