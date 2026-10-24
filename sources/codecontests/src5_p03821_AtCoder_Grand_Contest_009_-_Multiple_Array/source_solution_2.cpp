#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  vector<ll> a(n), b(n);
  rep(i,n)cin>>a[i]>>b[i];
  ll result=0;
  for(int i=n-1; i>=0; i--){
    ll ca = result+a[i];
    if(ca%b[i])result+=(b[i]-ca%b[i]);
  }
  cout<<result;
  return 0;
}