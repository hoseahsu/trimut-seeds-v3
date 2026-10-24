#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;int x=0,y=0,global=0;char target=MOD?'S':'C';while(n--){string s;cin>>s;int local=0;for(char c:s){if(c==target)local++,global++;else local=global=0;x=max(x,local);y=max(y,global);}}cout<<x<<' '<<y<<'\n';}