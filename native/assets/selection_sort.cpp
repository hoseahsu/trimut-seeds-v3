#include <bits/stdc++.h>
using namespace std;
#ifndef MUT
#define MUT 0
#endif
string canonical(string s){bool neg=s[0]=='-';size_t p=neg;while(p<s.size()&&s[p]=='0')p++;if(p==s.size())return "0";return (neg?"-":"")+s.substr(p);}
bool less_integer(string const&a,string const&b){bool na=a[0]=='-',nb=b[0]=='-';if(na!=nb)return na;int la=a.size()-na,lb=b.size()-nb;if(la!=lb)return na?la>lb:la<lb;return na?a>b:a<b;}
struct Key {string value;int index;};
struct Cmp {bool operator()(Key const&a,Key const&b) const {if(a.value!=b.value)return MUT?less_integer(b.value,a.value):less_integer(a.value,b.value);return a.index<b.index;}};
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;if(!(cin>>n))return 0;vector<string>a(n);set<Key,Cmp>s;for(int i=0;i<n;i++){cin>>a[i];a[i]=canonical(a[i]);s.insert({a[i],i});}long long swaps=0;for(int i=0;i<n;i++){int j=s.begin()->index;s.erase(s.begin());if(j!=i){s.erase({a[i],i});swap(a[i],a[j]);s.insert({a[j],j});swaps++;}}for(int i=0;i<n;i++)cout<<(i?" ":"")<<a[i];cout<<'\n'<<swaps<<'\n';}
