#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<int, P > PP;
#define MAX 10000000
int cc=1;
int A,B,C,N;
set< PP > s;
vector< PP > t;
 
map< P , set< P > > xy,yz,zx;
 
int par[MAX],rak[MAX];
 
void init(){
  for(int i=0;i<MAX;i++)
    par[i]=i,rak[i]=1;
}
 
int find(int x){
  if(par[x]==x)return x;
  return par[x]=find(par[x]);
}
 
void unite(int x,int y){
  x=find(x),y=find(y);
  if(x==y)return;
  if(rak[x]<rak[y])swap(x,y);
  par[y]=x;
  rak[x]+=rak[y];
}
 
void calc(map< P , set<P> > &mp){
  map< P , set<P> > :: iterator it;
  for(it=mp.begin();it!=mp.end();it++){
    set<P> :: iterator si=it->second.begin();
    set<P> :: iterator ti=it->second.end();
    set<P> :: iterator A=si,B;
    while(1){
      B=A;
      B++;
      if(B==ti)break;
      if(A->second>0&&B->second>0){
        unite(A->second,B->second);
      }
      A=B;
    }
  }
}
 
void add(int nx,int ny,int nz){
  if(nx<0||A<=nx||ny<0||B<=ny||nz<0||C<=nz)return;
  if(s.count(PP(nx,P(ny,nz))))return;
  s.insert( PP(nx,P(ny,nz)) );
  xy[ P(nx,ny) ].insert( P(nz,cc) );
  yz[ P(ny,nz) ].insert( P(nx,cc) );
  zx[ P(nz,nx) ].insert( P(ny,cc) );     
  cc++;
}
 
int main(){
  init();
  scanf("%d %d %d %d",&A,&B,&C,&N);
  t.resize(N);

  for(int i=0;i<N;i++){
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    s.insert( PP(x,P(y,z)) );
    t[i]=PP(x,P(y,z));

    xy[ P(x,y) ].insert( P(z,0) );
    yz[ P(y,z) ].insert( P(x,0) );
    zx[ P(z,x) ].insert( P(y,0) );     
  }


  add(0,0,0);

 
  for(int i=0;i<(int)t.size();i++){
    int x=t[i].first;
    int y=t[i].second.first;
    int z=t[i].second.second;
     
    for(int dx=-1;dx<=1;dx++){
      for(int dy=-1;dy<=1;dy++){
        for(int dz=-1;dz<=1;dz++){
          add(x+dx,y+dy,z+dz);
 
          add(x+dx,0,0);
          add(0,y+dy,0);
          add(0,0,z+dz);
 
          //          add(x+dx,B-1,C-1);
          //          add(A-1,y+dy,C-1);
          //          add(A-1,B-1,z+dz);
 
          //          add(x+dx,B-1,0);
          //          add(A-1,y+dy,0);
          //          add(A-1,0,z+dz);
 
          //          add(x+dx,0,C-1);
          //          add(0,y+dy,C-1);
          //          add(0,B-1,z+dz);
 
          add(x+dx,y+dy,0);
          add(0,y+dy,z+dz);
          add(x+dx,0,z+dz);
 
          //          add(x+dx,y+dy,C-1);
          //          add(A-1,y+dy,z+dz);
          //          add(x+dx,B-1,z+dz);
        }
      }
    }
  }
   
 
  calc(xy);
  calc(yz);
  calc(zx);
 
  int ans=0;
  for(int i=1;i<cc;i++)
    if(find(i)==i)ans++;
 
  printf("%d\n",ans);
  return 0;
}