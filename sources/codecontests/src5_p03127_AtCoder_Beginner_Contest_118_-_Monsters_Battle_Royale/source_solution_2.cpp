#include<algorithm>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
long gcd(long m,long n){if(n==0)return m;return gcd(n,m%n);}
int main()
{
	long n,a,s;
	cin>>n>>s;
	for(int i=1;i<n;i++)
	{
		cin>>a;
		s=gcd(s,a);
	}
	cout<<s<<endl;
}