#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

int main() {
    ll n,k,s;
    cin>>n>>k>>s;
    for(ll i=1;i<=k;i++)
    cout<<s<<" ";
    for(ll i=k+1;i<=n;i++){
        if(s==1e9)
            cout<<1<<" ";
        else
            cout<<s+1<<" ";
    }
}