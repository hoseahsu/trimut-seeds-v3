#include <bits/stdc++.h>
using namespace std;

#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define dbg(x) cout<<#x<<"="<<x<<endl

int main(){

  int N;
  string S;
  cin>>N>>S;

  int res=0;
  rep(i,N){
    if(S[i]!='.')continue;
    string T=S;
    T[i]='W';
    bool ok1=true,ok2=true;
    {
      int j=i;
      while(j<N&&T[j]=='W')j++;
      if(j<N&&T[j]=='B')ok1=false;
    }
    {
      int j=i;
      while(j>=0&&T[j]=='W')j--;
      if(j>=0&&T[j]=='B')ok2=false;
    }

    if(!ok1&&!ok2)continue;

    int sum=0;
    {
      int j=i+1;
      int cnt=0;
      while(j<N&&T[j]=='B'){
        cnt++;
        j++;
      }
      if(j<N&&T[j]=='W')sum+=cnt;
    }
    {
      int j=i-1;
      int cnt=0;
      while(j>=0&&T[j]=='B'){
        cnt++;
        j--;
      }
      if(j>=0&&T[j]=='W')sum+=cnt;
    }
    res=max(res,sum);
  }

  cout<<res<<endl;

  return 0;
}

