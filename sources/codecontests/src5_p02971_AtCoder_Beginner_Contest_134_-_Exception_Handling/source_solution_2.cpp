#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int a[200001];
int main()
{
	int n,m,s=0;
	cin>>n;
	for(int i=0;i<n;i++)
	  cin>>a[i],v.push_back(a[i]);
	sort(v.rbegin(),v.rend());
	m=v[0],s=v[1];
	for(int i=0;i<n;i++)
	  if(a[i]==m)
	    cout<<s<<endl;
	  else
	    cout<<m<<endl;
	return 0;
}