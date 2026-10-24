#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);string s;cin>>s;if(!MOD){int z=count(s.begin(),s.end(),'0');cout<<2*min(z,(int)s.size()-z)<<'\n';}else{string st;for(char c:s){if(!st.empty()&&st.back()==c)st.pop_back();else st.push_back(c);}cout<<s.size()-st.size()<<'\n';}}