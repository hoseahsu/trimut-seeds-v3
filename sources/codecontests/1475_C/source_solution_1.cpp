#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
             ll n,m,k;
             cin>>n>>m>>k;
             vector<ll>a(k),b(k);
             map<ll,ll>c,c2;
             ll i;
             for(i=0;i<k;i++)
                 cin>>a[i];
             for(i=0;i<k;i++)
                 cin>>b[i];
             for(i=0;i<k;i++)
             {
                  c[a[i]]++;
                  c2[b[i]]++;
             }
             ll res=0;
             for(i=0;i<k;i++)
             {
                 res+=(k-1)-(c[a[i]]-1)-(c2[b[i]]-1);
             }
             cout<<res/2<<endl;
 
    }
    return 0;
}