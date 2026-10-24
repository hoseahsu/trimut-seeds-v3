#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);string s;cin>>s;bool ok;if(MOD)ok=2*count(s.begin(),s.end(),'+')==(int)s.size();else{string st;for(char c:s){if(!st.empty()&&st.back()==c)st.pop_back();else st.push_back(c);}ok=st.empty();}cout<<(ok?"YES":"NO")<<'\n';}