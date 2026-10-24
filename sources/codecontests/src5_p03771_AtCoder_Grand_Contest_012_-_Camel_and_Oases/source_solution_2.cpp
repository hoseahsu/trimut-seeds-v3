#include<iostream>
#include<algorithm>
#include<unordered_map>
//#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define chmax(a,b) a=max(a,b);
#define N (1<<18)
#define M 19
ll n,v;
class Alpha{
 public:
 ll f[N];
 P g[N][M];
 void setg(ll a[]){
     for(int k=0;k<M;k++){
         for(int i=0;i<n;i++)g[i][k]=make_pair(i,i);
         ll bef=-1e18,pnt=0; a[n]=1e18;
         for(int i=0;i<=n;i++){
          if(abs(a[i]-bef)>(v>>k)){
           for(int j=pnt;j<i;j++)g[j][k]=make_pair(pnt,i-1);
           pnt=i;   
          }
          bef=a[i];
         }
         if((v>>k)==0)break;
     }
 }
 void main(ll a[]){
  setg(a);   
  for(int i=0;i<N;i++)f[i]=-1;
  for(int i=0;i<N;i++){
      for(int j=0;j<M-1;j++){
          if(i&(1<<j))continue;
          chmax(f[i+(1<<j)],g[f[i]+1][j+1].second);
      }
  }
  //for(int i=0;i<16;i++)cout<<f[i]<<" ";cout<<endl;
 }
};Alpha L,R;

class Solve{
  public:
  unordered_map<ll,bool> mas;
  bool main(ll l,ll r){
      if(mas.size()>30)return 0;
      if(mas.find(l)!=mas.end()){
       return mas[l];   
      }
      bool res=0;
      int cnt=0;
      for(int x=v;x;x>>=1)cnt++;
      int who=1;
      for(int i=0;i<cnt;i++)who*=2;//cout<<who<<endl;
      for(int i=0;i<who;i++){
       int ls=i,rs=who-1-i;
       if(l-1<=L.f[ls]&&n-1-R.f[rs]<=r+1)res=1;
      }
      mas[l]=res;
      return res;
  }
};Solve sv;

ll a[N];
int main(){
    cin>>n>>v;
    for(int i=0;i<n;i++)cin>>a[i];
    L.main(a);
    for(int i=0;i<n/2;i++)swap(a[i],a[n-i-1]);
    R.main(a);
    for(int i=0;i<n;i++){
     bool ans=sv.main(L.g[i][0].first,L.g[i][0].second);   
     cout<<(ans?"Possible":"Impossible")<<endl;
    }
 return 0;   
}
