
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

bool range(int n, int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}
void rec(vector<vector<char> >& g, int x, int y, int dx, int dy, int c)
{	
	int n = g.size();
	if(c == 4) return;
	
	g[x][y] = '#';

	int nx = x + dx, ny = y + dy;
	if(range(n, nx, ny) && g[nx][ny] != '#' && (range(n, nx + dx, ny + dy) ? g[nx + dx][ny + dy] != '#' : true))
	{
		rec(g, nx, ny, dx, dy, 0);
	}
	else
	{
		if(dx == 0 && dy == -1) 	rec(g, x, y,  1, 0, c + 1);
		else if(dx == 1 && dy == 0)	rec(g, x, y,  0, 1, c + 1);
		else if(dx == 0 && dy == 1)	rec(g, x, y, -1, 0, c + 1);
		else						rec(g, x, y, 0, -1, c + 1);
	}
}

int main()
{
	int d;
	cin >> d;
    
	for(int n; d && cin >> n; d--)
	{
		vector<vector<char> > g(n, vector<char>(n, ' '));
		
		rec(g, 0, n - 1, 0, -1, 0);
		
		if(n % 2 == 0) g[n / 2][n / 2] = ' ';
		
		rep(y, n) rep(x, n) cout << g[x][y] << (x + 1 == n ? "\n" : "");
		
		if(d != 1) cout << endl;
	}
}