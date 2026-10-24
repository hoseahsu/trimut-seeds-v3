#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>

using namespace std;

#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,N) for(long long i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define fi first
#define se second

#define PI acos(-1.0)
#define INF 1000000007

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, double> PD;
typedef pair<string, ll> PS;
typedef vector<ll> V;

int n;

int main(){
	while (cin >> n&&n != -1){
		double x = 1, y = 0, angle = 0;
		REP(i, n - 1){
			angle += atan(1.0 / sqrt(pow(x, 2) + pow(y, 2)));
			double px = x, py = y;
			x = (sqrt(1 + pow(px, 2) + pow(py, 2)))*cos(angle);
			y = (sqrt(1 + pow(px, 2) + pow(py, 2)))*sin(angle);
		}
		cout << x << endl;
		cout << y << endl;
	}
}