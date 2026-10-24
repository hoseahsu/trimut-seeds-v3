#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
  ll n,d,c=0;
  cin>>n>>d;
  while(n--)
  {
   ll x,y;
    cin>>x>>y;
    if(d*d >= (x*x +y*y)) c++;
  }
  cout<<c;
  return 0;
}