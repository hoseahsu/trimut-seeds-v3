#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
double ans,dp[51][3000];
int X,Y,Z;

int dice[4],t[51],u[51],N;
void init();
double dfs(int,int);

int main(){
  while(cin>>X>>Y>>Z&&X){
    init();
    for(int i=0;i<X;i++)cin>>dice[i];
    for(int i=0;i<Z;i++){
      cin>>N;
      cin>>t[N]>>u[N];
    }
    cout<<(int)dfs(0,0)<<endl;
  }
  return 0;
}

void init(){
  for(int i=0;i<51;i++){
    for(int j=0;j<3000;j++)dp[i][j]=-1.0;
    t[i]=u[i]=0;
  }
}

double dfs(int pos,int cnt){
  if(pos>=Y)return (double)cnt;
  if(dp[pos][cnt]!=-1.0)return dp[pos][cnt];
  double res=0;
  for(int i=0;i<X;i++){
    int npos=pos+dice[i];
    if(t[npos]==1)res+= dfs(npos+u[npos],cnt);
    else if(t[npos]==2)res+= dfs(npos,cnt+u[npos]);
    else res+= dfs(npos, max(0,cnt-u[npos]));
  }
  return dp[pos][cnt]=res/(double)X;
}