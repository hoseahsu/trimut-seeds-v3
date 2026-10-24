#include <bits/stdc++.h>
using namespace std;
#define vi vector<ll>
#define pb push_back
#define F first
#define S second
#define all(c)  c.begin(), c.end()
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);

#define ps(x,y) fixed<<setprecision(y)<<x
#define pii pair<ll,ll>
#define ll long long int


/*** User-defined Function ****/

ll csb(ll x) //count set bits in number
{
    if (x <= 0)
        return 0;
    return (x % 2 == 0 ? 0 : 1) + csb(x / 2);
}

ll tb(ll n) //total bits in number
{
   ll count = 0;
   while (n)
   {
        count++;
        n >>= 1;
    }
    return count;
}


bool ip2(ll n) // Function to check if n is power of 2
{
   if(n==0)
   return false;

   return (ceil(log2(n)) == floor(log2(n)));
}


ll countGreater(ll arr[], ll n, ll k)
{
    ll l = 0;
    ll r = n - 1;

    // Stores the index of the left most element
    // from the array which is greater than k
    ll leftGreater = n;

    // Finds number of elements greater than k
    while (l <= r) {
        ll m = l + (r - l) / 2;

        // If mid element is greater than
        // k update leftGreater and r
        if (arr[m] > k) {
            leftGreater = m;
            r = m - 1;
        }

        // If mid element is less than
        // or equal to k update l
        else
            l = m + 1;
    }

    // Return the count of elements greater than k
    return (n - leftGreater);
}
/**** Main()  function ****/

int main()
{

  ll t;
  cin>>t;
  while(t--)
  {
      ll i,sum=0,n,r,ans;
      cin>>n;
      vi v(n);
      for(i=0;i<n;i++)
      {
          cin>>v[i];
          sum+=v[i];
      }


      r=sum%n;
      ans=r*(n-r);
      cout<<ans<<endl;


  }

}






