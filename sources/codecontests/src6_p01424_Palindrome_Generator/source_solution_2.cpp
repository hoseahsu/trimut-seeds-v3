#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  const int D = 11;
 
  int n,m;
  cin>>n>>m;
  vector<string> s(n);
  for(int i=0;i<n;i++) cin>>s[i];

  vector<vector<int> > E(n,vector<int>(n,0));
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;
    E[x][y]=1;
  }

  vector<int> l(n);
  for(int i=0;i<n;i++) l[i]=s[i].size();


  using T = tuple<int, int, int>;
  auto idx=[&](int d,int x,int y){return (D+d)*n*n+x*n+y;};
  auto inv=[&](int v){return T(v/(n*n)-D,v%(n*n)/n,v%n);};
  int sz=idx(D,n-1,n-1)+1;

  queue<T> qt;
  vector<int> dp(sz,-1);
  
  // center inside s[x]
  for(int x=0;x<n;x++){
    // even
    for(int i=1;i<l[x];i++){
      // [0, i) + [i, l)
      int k=min(i,l[x]-i),ok=1;
      for(int j=0;j<k;j++)
	ok&=s[x][i-(j+1)]==s[x][i+j];
      if(ok){
	int d=i-(l[x]-i);
	qt.emplace(d,x,x);
	chmax(dp[idx(d,x,x)],l[x]);
      }
    }
    // odd
    for(int i=0;i<l[x];i++){
      // [0, i) + [i, i+1) + [i+1, l)
      int k=min(i,l[x]-(i+1)),ok=1;
      for(int j=0;j<k;j++)
	ok&=s[x][i-(j+1)]==s[x][i+1+j];
      if(ok){
	int d=i-(l[x]-(i+1));
	qt.emplace(i-(l[x]-(i+1)),x,x);
	chmax(dp[idx(d,x,x)],l[x]);
      }
    }
  }

  // s[x] |center| s[y] (obviously even)
  for(int x=0;x<n;x++){
    for(int y=0;y<n;y++){
      if(!E[x][y]) continue;
      int k=min(l[x],l[y]),ok=1;
      for(int j=0;j<k;j++)
	ok&=s[x][l[x]-(j+1)]==s[y][j];
      if(ok){
	int d=l[x]-l[y];
	qt.emplace(d,x,y);
	chmax(dp[idx(d,x,y)],l[x]+l[y]);
      }
    }    
  }

  using P = pair<int, int>;
  vector<vector<P> > G(sz),R(sz);
  
  for(int d=-D;d<=D;d++){
    for(int x=0;x<n;x++){
      for(int y=0;y<n;y++){
	int v=idx(d,x,y);
	for(int i=0;i<n;i++){
	  // s[i] s[x] s[y]
	  if(d<=0&&E[i][x]){
	    int k=min(-d,l[i]),ok=1;
	    for(int j=0;j<k;j++)
	      ok&=s[i][l[i]-(j+1)]==s[y][l[y]+d+j];
	    if(ok){	     
	      int nd=d+l[i];
	      int u=idx(nd,i,y);
	      G[v].emplace_back(u,l[i]);
	      R[u].emplace_back(v,l[i]);	      
	    }
	  }
	  // s[x] s[y] s[i]
	  if(d>=0&&E[y][i]){
	    int k=min(d,l[i]),ok=1;
	    for(int j=0;j<k;j++)
	      ok&=s[i][j]==s[x][d-(j+1)];
	    if(ok){
	      int nd=d-l[i];
	      int u=idx(nd,x,i);
	      G[v].emplace_back(u,l[i]);
	      R[u].emplace_back(v,l[i]);	      
	    }
	  }
	}
      }           
    }
  }

  // find nodes that can reached from starts
  while(!qt.empty()){
    int d,x,y;
    tie(d,x,y)=qt.front();qt.pop();
    int v=idx(d,x,y);
    for(auto e:G[v]){
      int u,c;
      tie(u,c)=e;
      if(~dp[u]) continue;
      chmax(dp[u],dp[v]+c);
      qt.emplace(inv(u));      
    }    
  }

  vector<int> dp2(sz,-1),used(sz,0),visit(sz,0);
  queue<int> qu;
  
  function<int(int)> dfs=
    [&](int v){
      int &res=dp2[v];
      if(used[v]) return res;
      
      visit[v]=1;
      qu.emplace(v);
      res=dp[v];
      
      for(auto e:R[v]){
	int u,c;
	tie(u,c)=e;
	if(dp[u]<0) continue;
	if(visit[u]==1){
	  cout<<-1<<endl;
	  exit(0);
	}
	chmax(res,dfs(u)+c);
      }
      
      visit[v]=0;
      return res;
    };
  
  int ans=0;
  for(int x=0;x<n;x++){
    for(int y=0;y<n;y++){
      int v=idx(0,x,y);
      if(~dp[v]) chmax(ans,dfs(v));
      while(!qu.empty()){
	used[qu.front()]=1;
	visit[qu.front()]=2;
	qu.pop();
      }
    }
  }

  cout<<ans<<endl;
  return 0;
}

