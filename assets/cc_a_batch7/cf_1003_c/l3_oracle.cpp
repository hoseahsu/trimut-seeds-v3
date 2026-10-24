#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){int n,k;cin>>n>>k;vector<int>a(n);for(int&x:a)cin>>x;double best=0;for(int l=0;l<n;l++)for(int r=l;r<n;r++)if(MOD?r-l+1==k:r-l+1>=k){ll sum=0;for(int i=l;i<=r;i++)sum+=a[i];best=max(best,double(sum)/(r-l+1));}cout<<fixed<<setprecision(10)<<best<<'\n';}