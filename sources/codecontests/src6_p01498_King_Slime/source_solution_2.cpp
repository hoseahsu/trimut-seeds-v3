#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

const int IINF = INT_MAX;
const int MAX_N = 50000;
int N,W,H,x[MAX_N],y[MAX_N],uf[MAX_N],masks[MAX_N],sz[MAX_N];
// ↑←↓→

int find(int x) {
  if( x == uf[x] ) return x;
  return uf[x] = find(uf[x]);
}

void unit(int x,int y){
  x = find(x), y = find(y);
  if( x != y ) uf[x] = y;
}

int main(){
  scanf("%d %d %d",&N,&W,&H);
  rep(i,N) { 
    scanf("%d %d",x+i,y+i);
    uf[i] = i, masks[i] = sz[i] = 0;

    if( y[i] == 1 ) masks[i] |= (1<<0);
    if( x[i] == 1 ) masks[i] |= (1<<1);
    if( y[i] == H ) masks[i] |= (1<<2);
    if( x[i] == W ) masks[i] |= (1<<3);
  }
  map<int,int> mp;
  rep(i,N){
    if( mp.count(x[i]) ) unit(find(mp[x[i]]),find(i));
    else                 mp[x[i]] = i;
  }
  mp.clear();
  rep(i,N){
    if( mp.count(y[i]) ) unit(find(mp[y[i]]),find(i));
    else                 mp[y[i]] = i;
  }

  map<int,int> bitmask;
  set<int> S;
  vector<int> group;
  rep(i,N) S.insert(find(i));
  rep(i,N) ++sz[find(i)];

  if( S.size() == 1 ) {
    printf("%d\n",sz[find(0)]-1);
    return 0;
  }

  rep(i,N) bitmask[find(i)] |= masks[i];
  for(set<int>::iterator it = S.begin(); it != S.end(); it++) group.push_back(*it);

  int ans = IINF;
  rep(i,4){
    int cost = (int)S.size()-1;
    rep(j,(int)group.size()){
      cost += sz[group[j]];
      if( (bitmask[group[j]]>>i) & 1 ) --cost; 
    }
    ans = min(ans,cost);
  }
  printf("%d\n",ans);
  return 0;
}