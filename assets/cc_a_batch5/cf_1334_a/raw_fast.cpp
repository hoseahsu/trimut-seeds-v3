#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;ll oldp=0,oldc=0;bool ok=true;while(n--){ll p,c;cin>>p>>c;ll dp=p-oldp,dc=c-oldc;if(dp<0||dc<0||dc>dp||(MOD&&dc!=dp))ok=false;oldp=p;oldc=c;}cout<<(ok?"YES":"NO")<<'\n';}}