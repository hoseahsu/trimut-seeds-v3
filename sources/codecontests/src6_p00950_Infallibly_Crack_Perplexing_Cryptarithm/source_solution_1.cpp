#include <bits/stdc++.h>
using namespace std;
string s[2];
string::iterator p;
int fact();
int term();
int exp();
int k;
bool f[2];

int fact() {
  int x;string num;
  int mi=1;
  while(*p=='-') {
    mi*=-1;
    ++p;
  }
  while(isdigit(*p)){num+=*p;++p;}
  if(num.size()>1&&num[0]=='0') f[k]=0;
  if(num.size()) {
    x=0;
    for(int i=num.size()-1,j=0; i>=0; i--,j++) x+=(1<<j)*(num[i]=='1');
  } else if(p!=s[k].end()){
    if(*p!='(') f[k]=0;
    bool ff=(*p=='(');
    if(p!=s[k].end()&&*p=='(')++p;
    x=exp();
    if(ff&&*p!=')') f[k]=0;
    if(p!=s[k].end()&&*p==')')++p;
  } else f[k]=0;
  return x*mi;
}
 
int term() {
  int x=fact();
  while(*p=='*') {
    ++p;
    x*=fact();
  }
  return x;
}
 
int exp() {
  int x=term();
  while(*p=='+'||*p=='-') {
    if(*p=='+') {
      ++p;
      x+=term();
    } else {
      ++p;
      x-=term();
    }
  }
  return x;
}

int main() {
  string r="01+-*()=";
  sort(r.begin(),r.end());
  string t;
  cin >> t;
  map<char,int> m;
  for(int i=0; i<t.size(); i++) {
    if(isalpha(t[i])&&!m.count(t[i])) {
      int x=m.size();
      m[t[i]]=x;
    }
  }
  if(m.size()>r.size()) {
    cout << 0 << endl;
    return 0;
  }
  set<string> se;
  do {
    string e=t;
    for(int i=0; i<e.size(); i++) {
      if(isalpha(e[i])) e[i]=r[m[e[i]]];
    }
    int c=0;
    for(int i=0; i<e.size(); i++) {
      if(e[i]=='=') c++;
    }
    if(c!=1) continue;
    c=0;
    s[0]=s[1]="";
    for(int i=0; i<e.size(); i++) {
      if(e[i]=='=') {
        c++;
        continue;
      }
      s[c]+=e[i];
    }
    if(!s[0].size()||!s[1].size()) continue;
    int x[2]={0,0};
    for(k=0; k<2; k++) {
      f[k]=1;
      p=s[k].begin();
      int d=0,z=0;
      for(int i=0; i<s[k].size(); i++) {
        if(isdigit(s[k][i])) z++;
        if(s[k][i]=='(') {
          d++;
          if(i&&(isdigit(s[k][i-1])||s[k][i-1]==')')) f[k]=0;
          if(i!=s[k].size()-1&&(!isdigit(s[k][i+1])&&s[k][i+1]!='('&&s[k][i+1]!='-')) f[k]=0;
        }
        if(s[k][i]==')') {
          d--;
          if(i&&(!isdigit(s[k][i-1])&&s[k][i-1]!=')')) f[k]=0;
          if(i!=s[k].size()-1&&isdigit(s[k][i+1])) f[k]=0;
        }
        if(i) {
          if(s[k][i]=='+'||s[k][i]=='*') {
            if(s[k][i-1]=='+'||s[k][i-1]=='*'||s[k][i-1]=='-') f[k]=0;
          }
        } else if(s[k][i]=='+'||s[k][i]=='*') f[k]=0;
        if(d<0) f[k]=0;
      }
      if(d||!z) f[k]=0;
      if(f[k]) x[k]=exp();
    }
    if(f[0]&&f[1]&&x[0]==x[1]) {
      se.insert(r.substr(0,m.size()));
    }
  } while(next_permutation(r.begin(),r.end()));
  cout << se.size() << endl;
  return 0;
}