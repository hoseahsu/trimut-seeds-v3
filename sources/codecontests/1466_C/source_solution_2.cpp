#define rep(i,n) for (int i=0;i < (int)(n);i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  
  while(t--){
    string s;
    cin>>s;
    int n=s.size();
    
    int cnt=0;
    for(int i=1;i<n;i++){
      if(s[i]==s[i-1]){
        cnt++;
        s[i]='A';
      }
      else if(i>1 && s[i]==s[i-2]){
        cnt++;
        s[i]='B';
      }
    }
    cout<<cnt<<endl;
  }

  return 0;
}