#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

int main () {
	int t;
	cin >> t;
	while (t--)
    {
        ll n,x;
        cin>>n>>x;
        ll a[n];
        ll minimum=0,maximum=0;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]%x==0)
                maximum+=a[i]/x;
            else
                maximum+=(a[i]/x+1);
            minimum+=a[i];
        }
        if(minimum%x==0)
            minimum/=x;
        else
            minimum=minimum/x+1;
        cout<<minimum<<' '<<maximum<<endl;
	}
}
