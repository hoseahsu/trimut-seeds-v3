#include<iostream>
#define rep(i,n) for((i)=0;(i)<(n);i++)

using namespace std;

int v[3],n,c;
string s;

int f(){
  n++;
  int r;
  if(s[n-1]=='(')r=f(),n++,r=s[n-1]=='+'?max(r,f()):min(r,f()),n++;
  if(isdigit(s[n-1]))r=s[n-1]-'0';
  if(isupper(s[n-1]))r=v[s[n-1]-'P'];
  if(s[n-1]=='-')r=2-f();
  return r;
}

int main(){
  while(cin >> s,s!="."){
    c=0;
    rep(v[0],3)rep(v[1],3)rep(v[2],3)n=0,c+=f()/2;
    cout << c << endl;
  }
  return 0;
}