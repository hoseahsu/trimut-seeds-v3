#include <iostream>
using namespace std;

int main()
{
	int a, s, r;
	cin>>a;
	for(int d=0;d<a;d++)
	{
		int x, x2;
		cin>>x>>x2;
		if(x==x2)
		{
			s+=1;
		}
		else
		{
			if(s>=3)
			{
				r+=1;
			}
			s=0;
		}
	}
	if(s>=3||r>=1)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	return 0;
}
