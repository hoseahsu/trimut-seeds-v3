#include <bits/stdc++.h>
using namespace std;
int ans;
bool use[10];
string s[10],t[10];

bool check(int n) {
  bool ck=true;
  for(int i=0; i<5; i++) {
    if(t[n][i]==t[i][n-5]) ck=false;
  }
  return ck;
}

void dfs(int n) {
  if(n==10) {
    ans++;
    return;
  }
  
  for(int i=0; i<10; i++) {
    if(!use[i]) {
      use[i]=true;
      
      t[n]=s[i];
      if(n<5) dfs(n+1);
      else {
	if(check(n)) {
	  dfs(n+1);
	  use[i]=false;
	  return;
	}
      }

      reverse(s[i].begin(),s[i].end());
      t[n]=s[i];
      reverse(s[i].begin(),s[i].end());
      
      if(s[i]==t[n]) {
	use[i]=false;
	continue;
      }
      
      if(n<5) dfs(n+1);
      else {
	if(check(n)) {
	  dfs(n+1);
	  use[i]=false;
	  return;
	}
      }
      
      use[i]=false;
    }
  }
}

int main() {
  while(cin >> s[0]) {
    if(s[0]=="END") break;
    for(int i=1; i<10; i++) cin >> s[i];
    memset(use,false,sizeof(use));
    ans=0;
    dfs(0);
    cout << ans/8 << endl;
  }
  return 0;
}
