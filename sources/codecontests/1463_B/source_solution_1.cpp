#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  ll t;
  cin>>t;
  while(t--)
  {
      ll n;
      cin>>n;
    ll a[n+1],even_sum=0,sum=0;
    a[0]=0;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i%2==0)
            even_sum+=a[i];
            sum+=a[i];
    }
    if(2*(even_sum)<=sum)
    {
        for(ll i=1;i<=n;i++)
        {
            if(i%2==0)
                cout<<1<<" ";
            else
                cout<<a[i]<<" ";
        }
    }
    else
    {
        for(ll i=1;i<=n;i++)
        {
            if(i%2==1)
                cout<<1<<" ";
            else
                cout<<a[i]<<" ";
        }
    }
      cout<<"\n";
  }


  return 0;
}
