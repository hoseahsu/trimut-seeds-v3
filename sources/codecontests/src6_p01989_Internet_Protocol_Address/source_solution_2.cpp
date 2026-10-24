#include <bits/stdc++.h>
using namespace std;
bool check(string str)
{
	if(str.size() == 0) 
		return false;
	if(atoi(str.c_str()) >= 256) 
		return false;
	if(str.size() > 1 && str[0] == '0') 
		return false;
	return true;
}
int main()
{
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 1; i < s.size(); i++)
	{
		for(int j = i + 1; j < s.size(); j++)
		{
			for(int k = j + 1; k < s.size(); k++)
			{
				string a, b, c, d;
				a = b = c = d = "";

				a += s.substr(0, i);
				b += s.substr(i, j - i);
				c += s.substr(j, k - j);
				d += s.substr(k, s.size());
				//cout << a << "." << b << "." << c << "." << d << endl;
				if(check(a) == true && check(b) && check(c) && check(d))
				{
					cnt++;
					//cout << a << "." << b << "." << c << "." << d << endl;
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
