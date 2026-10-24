#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_N 1000005

int n;
vector<int> G[MAX_N];
int M[MAX_N],L[MAX_N];

int C[MAX_N];

ll size[MAX_N];
ll num[MAX_N];

bool f(const int &a,const int &b){
  return ( num[a] < num[b]);
}

int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d %d",&M[i],&L[i]);
    if(L[i]!=-1)G[L[i]].push_back(i);
  }
  queue<int> Q;
  for(int i=0;i<n;i++){
    C[i]=G[i].size();
    if(C[i]==0)Q.push(i);
  }
  ll ans=0;
  while(!Q.empty()){
    int pos=Q.front();Q.pop();
    int parent=L[pos];
    size[pos]++;
    if(parent!=-1)size[parent]+=size[pos];
    num[pos]+=M[pos];
    if(parent!=-1)num[parent]+=num[pos];
    C[parent]--;
    if(C[parent]==0)Q.push(parent);
    sort(G[pos].begin(),G[pos].end(),f);
    
    ll v=0;
    for(int i=0;i<(int)G[pos].size();i++){
      ans+=v;
      v+=num[ G[pos][i] ];
    }
  }
  
  printf("%lld\n",ans);
  return 0;
}