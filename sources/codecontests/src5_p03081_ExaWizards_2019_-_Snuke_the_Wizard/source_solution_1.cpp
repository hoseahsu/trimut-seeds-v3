#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,Q;
  string S;
  cin>>N>>Q>>S;
  string T="a"+S+"a";
  vector<pair<char,char>> p(Q);
  for(int i=0;i<Q;i++){
    char a,b;
    cin>>a>>b;
    p[i]=make_pair(a,b);
  }
  reverse(p.begin(),p.end());
  int l=1,r=N;
  for(int i=0;i<Q;i++){
    char a,b;
    tie(a,b)=p[i];
    if(b=='L'){
      if(T[l]==a){
        l++;
      }
      if(T[r+1]==a){
        r++;
      }
    }
    else{
      if(T[r]==a){
        r--;
      }
      if(T[l-1]==a){
        l--;
      }
    }
  }
  cout<<r-l+1<<endl;
}

