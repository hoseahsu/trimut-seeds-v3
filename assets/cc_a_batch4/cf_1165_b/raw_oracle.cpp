#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<int>a(n),on(n);for(int&x:a)cin>>x;int best=0;while(true){vector<int>chosen;for(int i=0;i<n;i++)if(on[i])chosen.push_back(a[i]);sort(chosen.begin(),chosen.end());bool ok=true;for(int i=0;i<(int)chosen.size();i++)if(chosen[i]<i+1+(MOD?1:0))ok=false;if(ok)best=max(best,(int)chosen.size());int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best<<'\n';}