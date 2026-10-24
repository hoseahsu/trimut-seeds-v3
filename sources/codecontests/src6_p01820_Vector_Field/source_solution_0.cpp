#include <bits/stdc++.h>
#define N 3001
using namespace std;
typedef pair<int,int> P;
int W,H,n;
char mp[N+100][N+100];

int compress(int *x1,int w){
  vector <int>xs;
  for(int i=0;i<n;i++)xs.push_back(x1[i]);
  sort(xs.begin(),xs.end());
  xs.erase(unique(xs.begin(),xs.end()),xs.end());

  for(int i=0;i<n;i++)
    x1[i]=find(xs.begin(),xs.end(),x1[i])-xs.begin();
  return xs.size();
}

int dfs(int x,int y,int dir){
  if(x<0||y<0||x>=W||y>=H)return 0;
  int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
  char ch=mp[y][x];
  mp[y][x]=0;

  if(ch=='^')dir=0;
  if(ch=='v')dir=1;
  if(ch=='<')dir=2;
  if(ch=='>')dir=3;
  int res= dfs(x+dx[dir],y+dy[dir],dir)+(ch!=0);
  mp[y][x]=ch;
  return res;
}

int main(){
  cin>>n;
  int x[N],y[N];
  char ch[N];
  for(int i=0;i<n;i++)cin>>x[i]>>y[i]>>ch[i];  
  W=compress(x,1e9);
  H=compress(y,1e9);
  memset(mp,0,sizeof(mp));
  for(int i=0;i<n;i++)mp[y[i]][x[i]]=ch[i];

  int ans=0;
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++)
      if(mp[i][j]!=0)ans=max(ans,dfs(j,i,0));
  cout <<ans<<endl;
  return 0;
}