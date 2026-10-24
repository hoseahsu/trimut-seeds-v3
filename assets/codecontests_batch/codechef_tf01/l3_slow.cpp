#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 1

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,k;cin>>n>>k;vector<int>a(n);for(auto&x:a)cin>>x;bool yes=false;if(MOD){vector<vector<int>>memo(n+1,vector<int>(k+1,-1));function<bool(int,int)>rec=[&](int i,int rem){if(rem==0)return true;if(i==n)return false;int&v=memo[i][rem];if(v!=-1)return (bool)v;v=0;if(a[i]==0)return (bool)(v=rec(i+1,rem));for(int count=0;count*a[i]<=rem;count++)if(rec(i+1,rem-count*a[i])){v=1;break;}return (bool)v;};yes=rec(0,k);}else{vector<int>on(n);while(true){ll sum=0;for(int i=0;i<n;i++)if(on[i])sum+=a[i];if(sum==k){yes=true;break;}int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}}cout<<(yes?1:0)<<'\n';}}
