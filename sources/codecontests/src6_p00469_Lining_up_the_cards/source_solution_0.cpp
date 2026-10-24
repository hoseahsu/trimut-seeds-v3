#include<iostream>
#include<cstdio>
#include<string>
#include<set>

using namespace std;

int n;
int num[5];
int card[11];
set<string> ans;

void serch(int m,int k,int now)
{
	
	for(int i=0;i<m;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			if(num[i]==num[j])
			{
				return;
			}
		}
	}
	
	if(m==k)
	{
		string str;
		char  ch[8];
		for(int i=0;i<m;i++)
		{
			sprintf(ch,"%d",card[num[i]]);
			str+=string(ch);
		}
		ans.insert(str);
		return ;
	}
	
	num[m]=now;
	
	for(int i=0;i<n;i++)
	{
		serch(m+1,k,i);
	}
	
	return ;
}

int main()
{
	int k;
	int i,j;
	
	for(;;)
	{
		cin >> n >> k;
		if(n==0 && k==0)
			break;
		
		ans.clear();
		
		for(i=0;i<n;i++)
			cin >> card[i] ;
		
		for(i=0;i<n;i++)
		{
			serch(0,k,i);
		}
		
		set<string>::iterator it = ans.begin();
		
/*
		for(;it!=ans.end();++it)
		{
			cout << "ans:" << *it << endl;
		}
*/
		
		cout << ans.size() << endl;
	}
	
}