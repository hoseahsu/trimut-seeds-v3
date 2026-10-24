#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<int>a(n),p(n+1),s(n+1);for(auto&x:a)cin>>x;p[0]=s[n]=MOD?INT_MAX:INT_MIN;for(int i=0;i<n;i++)p[i+1]=MOD?min(p[i],a[i]):max(p[i],a[i]);for(int i=n-1;i>=0;i--)s[i]=MOD?min(s[i+1],a[i]):max(s[i+1],a[i]);for(int i=0;i<n;i++)cout<<(MOD?min(p[i],s[i+1]):max(p[i],s[i+1]))<<'\n';}