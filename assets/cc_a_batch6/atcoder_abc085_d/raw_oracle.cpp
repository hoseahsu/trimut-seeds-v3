#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;ll h;cin>>n>>h;vector<ll>a(n),b(n);vector<int>on(n);ll swing=0;for(int i=0;i<n;i++)cin>>a[i]>>b[i],swing=max(swing,a[i]);ll best=1LL<<60;while(true){ll damage=0,cost=0;for(int i=0;i<n;i++)if(on[i])damage+=b[i],cost+=MOD?2:1;ll remain=max(0LL,h-damage);cost+=remain/swing+(remain%swing!=0);best=min(best,cost);int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best<<'\n';}