#include<bits/stdc++.h>
using namespace std; 
#define N 100005
typedef long long LL;
typedef unsigned long long  ULL; 
int main()
{
	int k,j,i,tt,temp;
	cin>>tt;
	while(tt--)
	{
		int n,a[N]={0},ans=0;
		char cha[N]={0},chb[1],ch;	
		cin>>cha+1;
		for(i=2;cha[i]!=0;i++)
		{
			if(cha[i]==cha[i-1]&&cha[i-1]!=1)
			{
				cha[i]=1;
				ans+=1;
			}
			if(cha[i-1]==cha[i+1]&&cha[i-1]!=1) 
			{
				cha[i+1]=1;
				ans+=1;
			 } 
		}
		cout<<ans<<endl;
		//cout<<endl;
	}
	return 0; 
 } 
