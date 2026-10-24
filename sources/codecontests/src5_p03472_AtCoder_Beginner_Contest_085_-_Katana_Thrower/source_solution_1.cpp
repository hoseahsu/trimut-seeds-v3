#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n,h;
	cin>>n>>h;
	int a[n],b[n];
	ll x = 0;int c=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		
	}
	sort(a,a+n);
	sort(b,b+n,greater<int>());
	for(int i=0;i<n;i++)
		if(b[i]>a[n-1]){
			x += b[i];
			c++;
			if(x>=h)
			{
				cout<<c<<"\n";
				return 0;
			}
		}

	c += (h-x+a[n-1]-1)/a[n-1];
	cout<<c<<"\n";
}