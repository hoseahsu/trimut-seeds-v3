#include<bits/stdc++.h>
using namespace std;

int dot[4]={1, 2, 3, 0};
string s;

void plusdot(void)
{
	++dot[2];
	if(dot[2]>=s.size())
	{
		++dot[1];
		dot[2]=dot[1]+1;
		if(dot[2]>=s.size())
		{
			++dot[0];
			dot[1]=dot[0]+1;
			dot[2]=dot[1]+1;
		}
	}
	return;
}

int main(int argc, char const *argv[])
{
	cin >> s;
	dot[3]=s.size();
	int now=0, f=0, ans=0;
	string tmp;
	while(dot[2]<s.size())
	{
		f=1;
		int j=0;
		for (int i = 0; i < 4; ++i)
		{
			tmp={};
			while (1)
			{
				tmp.push_back(s.at(j));
				++j;
				if(j==dot[i]||j==s.size()) break;
			}
			
			if (tmp=="0") continue;
			else if(tmp.at(0)=='0' || tmp.size()>3) f=0;
			else if(tmp.size()<=2) continue;
			else if(tmp.size()==3&&tmp.at(0)=='1') continue;
			else if(tmp.size()==3&&tmp.at(0)=='2')
			{
				if(tmp.at(1)-'5'<0) continue;
				else if(tmp.at(1)=='5')
				{
					if(tmp.at(2)-'5'<=0) continue;
					else f=0;
				}
				else f=0;
			}
			else f=0; 
		}
		if(f) ++ans;
		plusdot();
	}
	cout << ans << endl;
	return 0;
}
