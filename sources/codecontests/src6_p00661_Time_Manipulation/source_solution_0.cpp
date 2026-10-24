#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class t>
using table = vector<vector<t>>;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"
  
long long int gcd(long long int l, long long int r) {
	if (l > r)return gcd(r, l);
	else {
		if (r%l) {
			return gcd(l, r%l);

		}
		else {
			return l;
		}
	}
}

int main() {
	cout << setprecision(11) << fixed;
	while (1) {
		int N, M; cin >> N >> M;
		ld sum = 0;
		ld year = 0;
		if (!N)break;
		vector<long long int>nums(M);
		for (int i = 0; i < M; ++i)cin >> nums[i];
		for (int i = 0; i < (1 << M); ++i) {
			bitset<20>bs(i);
			long long int anum = 1;
			for (int j = 0; j < M; ++j) {
				if (bs[j]) {
					anum = anum*nums[j] / gcd(anum, nums[j]);
				}
			}
			ld asum = N / anum;
			ld ayear= (anum + N)*(N / anum) / 2;
			if (bs.count() % 2) {

				sum -= asum;
				year -= ayear;
			}
			else {

				sum += asum;
				year+= ayear;
			}
		}
		if (sum < eps)cout << 0 << endl;
		else 	cout << year/ sum << endl;
	
	}
	return 0;
}