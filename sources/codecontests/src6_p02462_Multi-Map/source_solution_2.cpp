#include<bits/stdc++.h>
using namespace std;
multimap<string, int> m;
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int t;
		scanf("%d",&t);
		if(t == 0)
		{
			string x;
			int y;
			cin >> x >> y;
			m.insert(make_pair(x, y));
		}
		else if(t == 1)
		{
			string x;
			cin >> x;
			if(m.count(x))
			{
				map<string, int>::iterator it, it2;
				it = m.lower_bound(x);
				it2 = m.upper_bound(x);
				for(; it!=it2; it++)
				{
					cout << (*it).second << endl;
				}
			}
		}
		else if(t == 2) 
		{
			string x;
			cin >> x;
			m.erase(x);
		}
		else if(t == 3)
		{
			string l, r;
			cin >> l >> r;
			map<string, int>::iterator it, it2;
			it = m.lower_bound(l);
			it2 = m.upper_bound(r);
			for(; it!=it2; it++)
			{
				cout << (*it).first << " " << (*it).second << endl;
			}
		}
	}
}
