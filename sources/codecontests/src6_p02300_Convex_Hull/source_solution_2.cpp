#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define fio() ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long  ll;
typedef double coord_t;     
typedef double coord2_t;
const ll inf = 1e9;
const ll MOD = 1e9 + 7;
const ll zero = 0;
const ll maxn = 1e5 + 5;

struct Point {
	coord_t x, y;

	bool operator <(const Point &p) const {
		return y < p.y || (y == p.y && x < p.x);
	}
};


coord2_t cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}


vector<Point> convex_hull(vector<Point> P)
{
	ll n = P.size(), k = 0;
	if (n == 1) return P;
	vector<Point> H(2*n);

	sort(P.begin(), P.end());

	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) < 0) k--;
		H[k++] = P[i];
	}

	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) < 0) k--;
		H[k++] = P[i];
	}

	H.resize(k-1);
	return H;
}
vector<Point> v, ans;
Point p;
ll n, x, y;
int main(){ 
	fio();
	cin >> n;
	for ( int i = 0; i < n; i++ ) {
		cin >> x >> y;
		p.x = x + inf;
		p.y = y + inf;
		v.pb(p);
	}
	ans = convex_hull(v);
	cout << ans.size() << endl;
	for ( int i = 0; i < ans.size(); i++ ) {
		p = ans[i];
		if ( p.x >= 0)
			cout << p.x - inf << " " << p.y - inf << endl;
	}
	return(0);
}
