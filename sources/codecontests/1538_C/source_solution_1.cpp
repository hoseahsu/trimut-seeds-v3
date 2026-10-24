
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define endl "\n"
#define fast     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define testing    int TT;cin>>TT;while(TT--)
using namespace std;

int main()
{
    fast;
    testing
    {
        ll n,l,r;
        cin>>n>>l>>r;
        vector <ll> a(n);
        for(auto& i:a)   cin>>i;
        sort(a.begin(),a.end());
        if(n<2){
            cout<<0<<endl;
            continue;
        }
        ll res=0, x,y;
        for(int i=0;i<n-1;i++){
            if(a[i] >= r) break;
            x = lower_bound(a.begin() + i+1, a.end(), l-a[i]) - a.begin();
            if(x>=n) continue;
            y = upper_bound(a.begin() + i+1, a.end(), r-a[i]) - a.begin();
            if(y > x) res+= (y-x);
        }
        cout<<res<<endl;
    }
    return 0;
    
}