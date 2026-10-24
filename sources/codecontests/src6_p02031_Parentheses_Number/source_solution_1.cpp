#include<map>
#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
#include<queue>
#include<tuple>
#include<stdio.h>
 
using namespace std;
#define REP(i,b,e) for(ll i=(ll)b;i<(ll)e;i++)
#define rep0(i,n) REP(i,0ll,n)
#define rep1(i,n) REP(i,1ll,n+1)
 
#define shosu setprecision(10)
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> Q;
ll longinf=1ll<<60;
int inf=1<<29;
//mleしなければぜんぶllでかく。

int main(){
      cin.tie(0);
      ios::sync_with_stdio(false);
      /*rep0(i,8){
            rep0(j,8) cout<<board[i][j]<<" ";
            cout<<endl;
      }*/
      deque<int> deq;
      int n;
      cin>>n;
      int p[n];
      rep0(i,n){
            cin>>p[i];
      }
      int pos=0;
      string ans;
      int ok=true;
      rep0(i,n){
            if(pos<p[i]){
                  int addd=p[i]-pos;
                  rep1(j,addd){
                        ans+='(';
                  }
                  for(int k=pos+1;k<=p[i];k++){
                        deq.push_back(k);
                  }
                  ans+=')';
                  deq.pop_back();
                  pos=p[i];
            }
            else{
                  int b=deq.back();
                  if(b!=p[i]) ok=false;
                  ans+=')';
                  deq.pop_back();
            }
      }
      //cout<<ans<<endl;
      if(ok){
            cout<<ans<<endl;
      }
      else{
            cout<<":("<<endl;
      }

      return 0;
}
