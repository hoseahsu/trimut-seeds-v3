#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int longest(const string&s,char ch){int best=0;for(int i=0;i<(int)s.size();i++){int j=i;while(j<(int)s.size()&&s[j]==ch)j++;best=max(best,j-i);}return best;}int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;char ch=MOD?'S':'C';int x=0;string all;while(n--){string s;cin>>s;x=max(x,longest(s,ch));all+=s;}cout<<x<<' '<<longest(all,ch)<<'\n';}