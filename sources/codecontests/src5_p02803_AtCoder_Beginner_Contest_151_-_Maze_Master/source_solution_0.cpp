#include <bits/stdc++.h>
using namespace std;

int main(){
 int h,w;
 cin>>h>>w;
  vector<string> g(h);
  for(string &s: g) cin>>s; 
  vector<int> dx={-1,0,0,1};
  vector<int> dy={0,1,-1,0};
  int ans=0;
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(g[i][j]=='#') continue;
      int cnt=0;
      vector<vector<int>> d(h,vector<int>(w,-1));
      queue<pair<int,int>> q;
      
      d[i][j]=0;
 	  pair<int,int> p(i,j);
      q.push(p);
      
      while(!q.empty()){
   	   pair<int,int> v=q.front();q.pop();
   	   int y=v.first,x=v.second;
    
       for(int k=0;k<4;k++){
        int Y=y+dy[k],X=x+dx[k];
      
        if(0<=Y&&Y<h&&0<=X&&X<w&&g[Y][X]=='.'){
          if(d[Y][X]!=-1) continue;
        
          d[Y][X]=d[y][x]+1;
          cnt=max(cnt,d[Y][X]);
          pair<int,int> V(Y,X);
          q.push(V);
        } 
	   }
      }
      ans=max(ans,cnt);
    }
  }
  cout<<ans<<endl;
}

