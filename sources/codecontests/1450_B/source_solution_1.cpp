#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  ll t;
  cin>>t;
  while(t--)
  {
    ll n,k;
    cin>>n>>k;
    ll a[n][2];
    for(ll i=0;i<n;i++)
      cin>>a[i][0]>>a[i][1];
      ll ans=-1;
      bool flag=0;
    for(ll i=0;i<n;i++)
    {
      flag=0;
      for(ll j=0;j<n;j++)
      {
        if((abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1]))>k)
        {
          flag=1;
          break;
        }
      }
      if(flag==0)
      {
        ans=1;
        break;
      }
    }
    cout<<ans<<"\n";
  }
}
