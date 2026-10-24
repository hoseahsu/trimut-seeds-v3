#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans;
string s;
map<string,ll> mp1,mp2;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        mp1[s]++;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>s;
        mp2[s]++;
    }
    for(auto x:mp1){
        ans=max(ans,x.second-mp2[x.first]);
    }
    cout<<ans<<endl;
}
