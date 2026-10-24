#include<bits/stdc++.h>
#define M 10005
using namespace std;
typedef pair<int,int> P;
typedef pair<double,P> P1;

#define rank Asdfiasofsad
class UF{
public:
  int V;
  vector<int> par,rank;
  UF(){}
  UF(int V):V(V),par(V),rank(V,0){for(int i=0;i<V;i++)par[i]=i;}
  
  int find(int x){
    assert(x < V);
    if(par[x]==x)return x;
    return par[x]=find(par[x]);
  }
  
  void unite(int x,int y){
    x=find(x), y=find(y);
    if(x==y)return;
    if(rank[x]<rank[y])par[x]=y;
    else{
      par[y]=x;
      if(rank[x]==rank[y])rank[x]++;
    }
  }
  
  bool same(int x,int y){return find(x)==find(y);}
};

int n, m, a[M], b[M], c[M], d[M], ans;

bool check(double X){
  
  UF uf=UF(n);
  
  priority_queue<P1> q;
  
  double S=0;
  
  for(int i=0;i<m;i++){
    q.push(P1(d[i]-X*c[i],P(a[i],b[i])));
    S+=d[i]-X*c[i];
  }
  
  double sum=0;
  
  while(!q.empty()){
    
    P1 t=q.top(); q.pop();
    
    int A=t.second.first, B=t.second.second;
    
    if(uf.same(A,B)) continue;
    
    sum+=t.first;
    
    uf.unite(A,B);
  }
  
  return S-sum<=(1e-8);
}

void solve(){
  
  double l=0, r=100000005;
  int cnt=100;
  
  while(cnt--){
    
    double Mid=(l+r)/2.0;
    
    if(!check(Mid)) l=Mid;
    else r=Mid;
    
  }
  
  printf("%.8f\n", l);
}

int main(){
  
  cin>>n>>m;
  
  for(int i=0;i<m;i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
  
  solve();
  
  return 0;
}

