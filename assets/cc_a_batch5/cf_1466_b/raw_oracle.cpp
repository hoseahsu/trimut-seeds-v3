#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(n),on(n);for(int&x:a)cin>>x;int best=0;while(true){set<int>seen;for(int i=0;i<n;i++)seen.insert(a[i]+on[i]*(MOD?2:1));best=max(best,(int)seen.size());int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best<<'\n';}}