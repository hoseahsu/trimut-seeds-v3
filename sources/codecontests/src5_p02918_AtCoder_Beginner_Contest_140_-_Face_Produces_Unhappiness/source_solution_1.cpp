#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;cin>>n>>k;
    string s;
    cin>>s;

    int res = 0;
    for(int i = 0; i < n-1; i++){
        if(s[i] == s[i+1]) res++;
    }

    int ans = min(n-1,res+2*k);
    cout<<ans;
}
