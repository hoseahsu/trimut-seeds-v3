#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){string s,st;cin>>s;array<int,26>left{};array<bool,26>used{};for(char c:s)left[c-'a']++;for(char c:s){left[c-'a']--;if(used[c-'a'])continue;while(!st.empty()&&left[st.back()-'a']>0&&(MOD?st.back()>c:st.back()<c)){used[st.back()-'a']=false;st.pop_back();}st+=c;used[c-'a']=true;}cout<<st<<'\n';}}