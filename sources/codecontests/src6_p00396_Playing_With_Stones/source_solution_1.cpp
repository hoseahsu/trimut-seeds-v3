#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;

int dp[222][111];

int Grundy(int h,int w){
  int &g=dp[h][w];
  
  if(g!=-1)return g;
  if(h==0&&w==0)return g=0;

  set<int>V;

  if(h)V.insert(Grundy(h-1,w));
  for(int i=1;i<=min(h,w);i++)V.insert(Grundy(h,w-i));
  if(w)V.insert(Grundy(h+1,w-1));

  g=0;
  while(V.count(g))++g;
  return g;
}

int main(){
  memset(dp,-1,sizeof(dp));
  int n,ans=0;
  cin>>n;
  r(i,n){
    int a,b;
    cin>>a>>b;
    ans^=Grundy(a,b);
  }
  cout<< (ans? 0:1) <<endl;
}
