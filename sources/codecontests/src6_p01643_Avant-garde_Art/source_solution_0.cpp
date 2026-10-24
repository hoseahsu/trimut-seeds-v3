#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

template<class T> inline void chmax(T& a, const T& b) { if(b > a) a = b; }

typedef int type;
const type INIT = 0;

class segment_tree {
private:
	int n;
	vector<type> dat;

	inline type function(type a, type b) const {
		return max(a, b);
	}

	type query(int a, int b, int k, int l, int r) const {
		if(r <= a || b <= l)
			return INIT;

		if(a <= l && r <= b) {
			return dat[k];
		}
		else {
			const type vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			const type vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return function(vl, vr);
		}
	}

public:
	segment_tree(int n_) {
		n = 1;
		while(n < n_) n *= 2;
		dat.resize(2 * n - 1, INIT);
	}

	inline void update(int k, type a) {
		k += n - 1;
		dat[k] = a;

		while(k > 0) {
			k = (k - 1) / 2;
			dat[k] = function(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}

	inline type query(int a, int b) const {
		return query(a, b, 0, 0, n);
	}
};

inline int next(int idx, int mod) {
	return (idx + 1) % mod;
}

inline int mod_sub(int a, int b, int mod) {
	return (a - b + mod) % mod;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}

	const int number_of_edges = n / 2;
	int lds = 0;
	vector<bool> used(n, false);

	for(int i = 0; i < n; ++i) {
		if(used[i]) continue;

		used[i] = true;
		used[a[i]] = true;

		vector<int> sequence(n, -1);
		const int pos = a[i] - i;

		for(int j = i + 1; j != a[i]; j = next(j, n)) {
			const int pos_a = mod_sub(a[j], i, n);
			if(pos_a > pos) { // intersect
				sequence[n - pos_a - 1] = mod_sub(j, i, n);
			}
		}

		sequence.erase(remove(sequence.begin(), sequence.end(), -1), sequence.end());

		segment_tree seg(n);

		for(int i = 0; i < static_cast<int>(sequence.size()); ++i) {
			const int value = seg.query(sequence[i] + 1, n) + 1;
			chmax(lds, value);
			seg.update(sequence[i], value);
		}
	}

	int ans = min(lds + 1 + k, number_of_edges);
	cout << ans << endl;
	return EXIT_SUCCESS;
}