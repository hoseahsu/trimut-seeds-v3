#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
int main()
{
      int t;
      cin>>t;
      while(t--)
      {
            ll n,k;
            cin>>n>>k;
            if(n==1)
            cout<<"0\n";
            else
            {
                ll start=k/2+(k%2);
                cout<<n-start<<"\n";
                for(;start<=n;start++)
                {
                    if(start!=k)
                    cout<<start<<" ";
                }
                cout<<"\n";
            }
      }
}