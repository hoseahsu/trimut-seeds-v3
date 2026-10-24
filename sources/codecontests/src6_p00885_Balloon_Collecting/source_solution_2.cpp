#include <iostream>
#include <algorithm>
using namespace std;
int n,dis[41],t[41],maxball,ans;

void saiki(int x,int now,int ball,int sum,int kai){
  if(ans<sum)return;
  maxball=max(maxball,kai);
  if(kai==n&&!ball)ans=min(ans,sum);
  if(ball)saiki(0,now+x*(1+ball),0,sum+x,kai);
  if(ball==3 || kai==n) return;
  
  int nx=dis[kai];
  int nsum=sum+abs(x-dis[kai]);
  int nnow=now+abs(x-dis[kai])*(1+ball);
  if(nnow<=t[kai])saiki(nx,t[kai],ball+1,nsum,kai+1);
}

int main(){
  while(1){
    cin>>n;
    if(!n)break;
    for(int i=0;i<n;i++)cin >>dis[i]>>t[i];
    sort(t,t+n);
    maxball=0,ans=100000000;
    saiki(0,0,0,0,0);
    if(maxball==n)cout <<"OK "<<ans<<endl;
    else cout<<"NG "<<maxball+1<<endl;
  }
  return 0;
}