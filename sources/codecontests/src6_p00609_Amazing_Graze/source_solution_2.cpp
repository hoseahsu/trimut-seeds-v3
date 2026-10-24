#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
  int i,j;
  int n,m,r;
  while(cin>>n>>m>>r,n||m||r){
    r*=4;
    int x[100000],y[100000];
    for(i=0;i<n;++i)
      cin>>x[i]>>y[i];
    vector<int> a[10000];
    for(i=0;i<m;++i){
      int p,q;
      cin>>p>>q;
      a[q].push_back(p);
    }
    for(i=0;i<10000;++i)
      sort(a[i].begin(),a[i].end());
    int b[90],c[90];
    for(i=-r;i<=r;++i){  
      for(j=-40;i*i+j*j>r*r;++j);
      b[i+40]=j;
      for(;i*i+j*j<=r*r;++j);
      c[i+40]=j;
    }
    int sm=0;
    for(i=0;i<n;++i){  
      for(j=y[i]-r;j<=y[i]+r;++j){
	if(0<=j&&j<10000)
	  sm+=lower_bound(a[j].begin(),a[j].end(),x[i]+c[j-y[i]+40])-lower_bound(a[j].begin(),a[j].end(),x[i]+b[j-y[i]+40]);
      }
    }
    cout<<sm<<endl;
  }
  return 0;
}