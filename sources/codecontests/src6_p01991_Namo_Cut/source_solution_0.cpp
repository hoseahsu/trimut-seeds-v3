#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

#define FOR(i,k,n) for(ll (i)=(k);(i)<(n);(i)++)
#define REP(i,n) FOR((i),0,(n))

ll N, Q;
vector<vector<ll>> edges;
vector<pair<ll, ll>> query;


void input() {
	ll a, b;
	cin >> N;
	edges.resize(N);

	REP(i, N) {
		cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	cin >> Q;
	REP(i, Q) {
		cin >> a >> b;
		a--; b--;
		query.push_back({ a,b });
	}
}

bool search(vector<bool>& went, vector<int>& route)
{
	int now = route.back();
	for (auto next : edges[now]) {
		if (route.size() > 1 && route[route.size() - 2] == next)continue;
		if (went[next]) {
			route.push_back(next);
			return true;
		}
		went[next] = true;
		route.push_back(next);
		if (search(went, route))return true;

		went[next] = false;
		route.pop_back();
	}
	return false;
}

void output(const vector<int>& route) {
	for (auto q : query) {
		if (binary_search(route.begin(), route.end(), q.first) &&
			binary_search(route.begin(), route.end(), q.second)) {
			cout << 2 << endl;
		}
		else {
			cout << 1 << endl;
		}
	}
}

int main() {	
	input();
	vector<bool> went(N, false);
	vector<int> subroute, route;

	subroute.push_back(0);
	search(went, subroute);
	int id = 0;
	while (subroute[id] != subroute.back())id++;
	FOR(i, id + 1, subroute.size())route.push_back(subroute[i]);
	sort(route.begin(), route.end());
	/*
	for (auto tmp : subroute)cout << tmp << " ";
	cout << endl;
	for (auto tmp : route)cout << tmp << " ";
	cout << endl;
	*/
	output(route);
	cin >> N;
	return 0;
}
