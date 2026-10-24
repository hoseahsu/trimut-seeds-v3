#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;

int main() {
	long long int N, L, M, R; cin >> N >> L >> M >> R;
	R *= 2;
	M *= 2;
	vector<pair<long long int, long long int>>ps;
	ps.push_back(make_pair(0, 0));
	bool ok = true;
	for (int i = 0; i < N; ++i) {
		int W; cin >> W;
		{
			vector<pair<long long int, long long int>>newps;
			for (auto p : ps) {
				newps.emplace_back(p.first - L*W, p.second - R*W);
				newps.emplace_back(p.first + R*W, p.second + L*W);
			}
			ps = newps;
		} 
		{
			vector<pair<long long int, long long int>>newps;
			for (auto p : ps) {
				if (p.first > p.second)continue;
				if (p.first > M)continue;
				if (p.second > M)p.second = M;
				if (p.second < -M)continue;
				if (p.first < -M)p.first = -M;
				newps.push_back(p);
			}
			ps = newps;
		}
		if (!ps.empty()) {
			sort(ps.begin(), ps.end());
			vector<pair<long long int, long long int>>nextps;
			{
				nextps.emplace_back(ps[0]);
				for (int i = 0; i < ps.size() - 1; ++i) {
					const int b = nextps.back().second;
					if (b >= ps[i + 1].first) {
						nextps.back().second = max(nextps.back().second, ps[i + 1].second);
					}
					else {
						nextps.emplace_back(ps[i + 1]);
					}
				}
			}
			ps = nextps;
		}
		else {
			ok = false;
			break;
		}
		
	}
	if (ok) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}