#include<bits/stdc++.h>
using namespace std;
#define MAX 105
#define INF (1e9)

int s2i(string s){
  stringstream ss;
  int res;
  ss<<s;
  ss>>res;
  return res;
}


int a[MAX][MAX];
vector<int> vx,vy;
int H,W;
string str;

bool solve(int id){
  int y=vy[id],x=vx[id];
  int ch=0,cw=0,sh=0,sw=0;
  for(int i=0;i<H;i++){
    if(a[i][x]==INF)continue;
    ch++;
    sh+=a[i][x];
  }
  if(ch==H-1){
    a[y][x]=a[H][x]-sh;
    return true;
  }

  for(int i=0;i<W;i++){
    if(a[y][i]==INF)continue;
    cw++;
    sw+=a[y][i];
  }
  if(cw==W-1){
    a[y][x]=a[y][W]-sw;
    return true;
  }
  return false;
}

int main(){
  int Tc=0;
  while(1){
    
    cin>>H;
    if(H==0)break;
    if(Tc!=0)cout<<endl;
    Tc++;

    cin>>W;
    vx.clear();
    vy.clear();
    for(int i=0;i<=H;i++){
      for(int j=0;j<=W;j++){
        cin>>str;
        if(str=="?"){
          a[i][j]=INF;
          vy.push_back(i);
          vx.push_back(j);
        }else a[i][j]=s2i(str);
      }
    }
    bool update=true;
    while(update){
      update=false;
      for(int i=0;i<(int)vx.size();i++){
        if(a[vy[i]][vx[i]]==INF)
          update|=solve(i);
      }
    }
    vector<int> ans;
    for(int i=0;i<(int)vx.size();i++)
      if(a[vy[i]][vx[i]]!=INF)
        ans.push_back(a[vy[i]][vx[i]]);
    if(ans.size()!=vx.size())cout<<"NO"<<endl;
    else{
      for(int i=0;i<(int)ans.size();i++)cout<<ans[i]<<endl;
    }
  }
  return 0;
}