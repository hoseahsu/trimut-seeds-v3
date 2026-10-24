#include <bits/stdc++.h>
#define N (1<<18)
#define INF (1e9)
using namespace std;
struct po{
  int l,r,x;
  po(){};
  po(int l,int r,int x):l(l),r(r),x(x){}
};
const int base=1e5+2;
int segMin[2][2*N-1], segAdd[2][2*N-1];
int w,h,m,x[N],y[N];
vector <po> mp[2][N];
po LR[N];

//starry sky tree
void add(int a,int b,int x,int k,int l,int r,int idx){
  if(r<=a||b<=l) return;
  if(a<=l&&r<=b){segAdd[idx][k]+=x;return;} 
  add(a,b,x,2*k+1,l,(l+r)/2,idx);
  add(a,b,x,2*k+2,(l+r)/2,r,idx);
  int L=segMin[idx][2*k+1]+segAdd[idx][2*k+1];
  int R=segMin[idx][2*k+2]+segAdd[idx][2*k+2];
  segMin[idx][k]=min(L,R);
}

int getMin(int a,int b,int k,int l,int r,int idx){
  if (r<=a||b<=l) return INF;
  if (a<=l&&r<=b) return segMin[idx][k]+segAdd[idx][k];
  int L=getMin(a,b,2*k+1,l,(l+r)/2,idx);
  int R=getMin(a,b,2*k+2,(l+r)/2,r,idx);
  return min(L,R)+segAdd[idx][k];
}

void mk_LR(){
  for(int i=0;i<h&&w==1;i++)LR[base+i]=po(base,base,i%2);
  if(w==1)return;

  LR[base]=po(base,base,0),LR[base+1]=po(base,base+1,1);
  int mn=min(w,h),S,cnt=0;
  for(int i=1;i<mn;i++) cnt+=2*i;
  S=(w*h-cnt)/mn;
  if(w==2)S--;
  for(int i=base+2;;i++){
    int l=LR[i-2].l-1,r=LR[i-2].r+1,x=LR[i-2].x;

    if(S==0&&!x)l=LR[i-1].l,r=l+mn-2,S--;
    else if(S==0&&x)l=LR[i-1].l+1,r=LR[i-1].r,S--;
    else if(S<0) l+=2,r-=2;
    if(l>r)break;
    if(r-l+1>mn) l=LR[i-2].l,r=l+mn-1;
    if(S>0&&LR[i-2].r-LR[i-2].l+1==mn)l=LR[i-2].l+1,r=l+mn-1;
    if(r-l+1==mn)S--;
    LR[i]=po(l,r,x);
  }
}

void mk_mp(int d){
  for(int i=0;i<N;i++) mp[0][i].clear(),mp[1][i].clear();
  
  for(int i=0;i<m;i++){
    int idx=y[i]+(w-x[i]-1)+base;
    int c=LR[idx].l+min(y[i],x[i]);
    int a=idx%2,l=c-d/2,r=c+d/2;
    if(d%2==0){
      mp[a][idx-d].push_back(po(l,r,1));
      mp[a][idx+d+1].push_back(po(l,r,-1));

      mp[!a][idx-d+1].push_back(po(l+!a,r-a,1));
      mp[!a][idx+d].push_back(po(l+!a,r-a,-1));
    }
    else {
      mp[!a][idx-d].push_back(po(l-a,r+!a,1));
      mp[!a][idx+d+1].push_back(po(l-a,r+!a,-1));
      
      mp[a][idx-d+1].push_back(po(l,r,1));
      mp[a][idx+d].push_back(po(l,r,-1));
    }
  }
}


bool check(int d){
  mk_mp(d);
  memset(segMin,0,sizeof(segMin));
  memset(segAdd,0,sizeof(segAdd));
  for(int i=0;i<N;i++){

    for(int k=0;k<2;k++)
      for(int j=0;j<mp[k][i].size();j++)
	add(mp[k][i][j].l,mp[k][i][j].r+1,mp[k][i][j].x,0,0,N,k);
    
    if(LR[i].l&&!getMin(LR[i].l,LR[i].r+1,0,0,N,i%2))return 1;
  }
  return 0; 
}

int search(){
  int L=0,M,R=100001;
  while(L<R){
    M=(L+R)/2;
    if(!check(M)) R=M;
    else L=M+1;
  }
  return L;
}

int main(){
  cin>>w>>h>>m;
  for(int i=0;i<m;i++)cin>>x[i]>>y[i];
  if(w>h){
    swap(w,h);
    for(int i=0;i<m;i++)swap(x[i],y[i]); 
  }
  mk_LR();
 
  cout <<search()<<endl;
  return 0;
}