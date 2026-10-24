#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <cctype>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <complex>
#include <fstream>
#include <iomanip>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
template<class T> T RoundOff(T a){ return int(a+.5-(a<0)); }
template<class T, class C> void chmax(T& a, C b){ if(a < b) a = b; }
template<class T, class C> void chmin(T& a, C b){ if(b < a) a = b; }
template<class T, class C> pair<T, C> mp(T a, C b){ return make_pair(a, b); }

int main()
{
	string str;
	int flag = 0;
	while(cin >> str)
	{
		if(flag++ != 0) cout << endl;
		deque<string> res;

		rep(i, 5)
		{
			if(str.size() <= i)
				res.push_front("* = ****");
			else
			{
				if(str[i] - '0' < 5)
					res.push_back("* =");
				else
				{
					str[i] -= 5;
					res.push_back(" *=");
				}

				rep(j, str[i] - '0')
					res[i] += "*";

				res[i] += " ";

				rep(j, 5 - (str[i] - '0' + 1))
					res[i] += "*";
			}
		}

		rep(i, 8) rep(j, 5)
			cout << res[j][i] << (j == 4 ? "\n" : "");
	}
}