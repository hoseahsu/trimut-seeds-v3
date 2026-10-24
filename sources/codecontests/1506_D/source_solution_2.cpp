#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long int lli;
int main()
{
  lli tc;
  cin>>tc;
  while(tc--)
  {
      lli n;
      cin>>n;
      lli ar[n];
      for(lli i=0;i<n;i++)
      {
        cin>>ar[i];
      }
      sort(ar,ar+n);
      lli ans=n;
      for(lli i=0;i<n/2;i++)
      {
        if(ar[i]!=ar[i+(n+1)/2])
        {
          ans=ans-2;
        }
      }
      cout<<ans<<endl;
  }
}
