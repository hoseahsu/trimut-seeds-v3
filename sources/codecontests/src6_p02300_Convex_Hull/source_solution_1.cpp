#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i <int(n);++i)
#define forsn(i,s,n) for(int i=s;i <int(n);++i)

int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}

struct vec {
	int x, y;
	int operator ^ (vec const& o) const {
		return x*o.y - y*o.x;
	}
	int operator * (vec const& o) const {
		return x*o.x + y*o.y;
	}
	vec operator - (vec const& o) const {
		vec res = *this;
		res.x -= o.x; res.y -= o.y;
		return res;
	}
	int n2 () const {
		return *this * *this;
	}
};

bool bad (vec const& a, vec const& b, vec const& c){
	vec d1 = b-c;
	vec d2 = a-c;

	int cross = d1 ^ d2;
	int dot   = d1 * d2;

	return cross != 0 ? cross > 0 : dot < 0;
}

int main () {
	int n;
	cin >> n;
	vector<vec> ps(n);
	forn(i,n)
		cin >> ps[i].x >> ps[i].y;

	auto it = min_element(ps.begin(), ps.end(), [](vec &l, vec &r) {
		// bottommost, break tie by taking leftmost
		return l.y != r.y ? l.y < r.y : l.x < r.x;
	});

	swap(ps[0], *it);

	sort(ps.begin()+1, ps.end(), [&](vec& l, vec& r){
		vec d1 = l-ps[0];
		vec d2 = r-ps[0];
		int cross = d1 ^ d2;
		// could be closest just as well, we just need to pick one.
		bool farthest = d2.n2() < d1.n2();
		return cross != 0 ? cross > 0 : farthest;
	});

	{
		// fix up colinear points
		int i = 1;
		vec d1 = ps[1] - ps[0];
		while(1){
			if(i >= n) break;
			vec di = ps[i] - ps[0];
			if((di^d1) != 0) break;
			i++;
		}
		reverse(ps.begin()+1, ps.begin()+i);
	}

#ifdef DEBUG
	for(auto v : ps){
		cerr << v.x << ' ' << v.y << '\n';
	}
#endif

	ps.push_back(ps[0]);
	vector<vec> ch;
	ch.push_back(ps[0]);
	forsn(i,1,n+1){
		ch.push_back(ps[i]);
		while(ch.size() >= 3 && bad(ch[ch.size()-3], ch[ch.size()-2], ch[ch.size()-1])){
			ch.pop_back();
			ch.back() = ps[i];
		}
	}
	ch.pop_back();

#ifndef DEBUG
	cout << ch.size() << '\n';
#endif
	for(auto v : ch){
		cout << v.x << ' ' << v.y << '\n';
	}

}
