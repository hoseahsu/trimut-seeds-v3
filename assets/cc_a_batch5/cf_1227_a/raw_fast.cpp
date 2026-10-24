#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;ll minl=1LL<<60,maxl=0,minr=1LL<<60,maxr=0;while(n--){ll l,r;cin>>l>>r;minl=min(minl,l);maxl=max(maxl,l);minr=min(minr,r);maxr=max(maxr,r);}cout<<(MOD?maxr-minl:max(0LL,maxl-minr))<<'\n';}}