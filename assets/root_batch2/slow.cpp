#include <bits/stdc++.h>
using namespace std;
// Explicitly erasing the first selected item from a contiguous sequence is the
// straightforward quadratic implementation of the same two-sequence merge.
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){string s,a,b,out;cin>>s;for(char c:s)((c-'0')%2?a:b)+=c;while(!a.empty()||!b.empty()){string&z=b.empty()||(!a.empty()&&a[0]<b[0])?a:b;out+=z[0];z.erase(z.begin());}cout<<out<<'\n';}}
