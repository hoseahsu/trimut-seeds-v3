#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <tuple>
#include <queue>
#include <stack>
#include <functional>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <iterator>
#include <array>
#include <memory>
#include <random>
#include <valarray>
//cin.sync_with_stdio(false);
//streambuf
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using ti3 = tuple<int, int, int>;
using vti3 = vector<ti3>;
template<class T, int s>using va = vector<array<T, s>>;
template<class T, class T2> using umap = unordered_map<T, T2>;
template<class T> using uset = unordered_set<T>;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
#define ALL(a) a.begin(),a.end()
#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a) for(int i=1;i<=a;i++)
#define rrep(i,a) for(int i=(a)-1;i>=0;i--)
#define rrep1(i,a) for(int i=a;i;i--)
#define repi(i,a,b) for(int i=a;i<b;i++)
const ll mod = 1000000007;
template<class T>using heap = priority_queue<T, vector<T>, greater<T>>;
template<class T>using pque = priority_queue<T, vector<T>, function<T(T, T)>>;
template <class T>
inline void hash_combine(size_t & seed, const T & v) {
	hash<T> hasher;
	seed ^= hasher(v) + 0x9e3779b97f4a7c15 + (seed << 6) + (seed >> 2);
}
namespace std {
	template<typename S, typename T> struct hash<pair<S, T>> {
		inline size_t operator()(const pair<S, T> & v) const {
			size_t seed = 0;
			hash_combine(seed, v.first);
			hash_combine(seed, v.second);
			return seed;
		}
	};
	// Recursive template code derived from Matthieu M.
	template <class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>
	struct HashValueImpl {
		static void apply(size_t& seed, Tuple const& tuple) {
			HashValueImpl<Tuple, Index - 1>::apply(seed, tuple);
			hash_combine(seed, std::get<Index>(tuple));
		}
	};
	template <class Tuple>
	struct HashValueImpl<Tuple, 0> {
		static void apply(size_t& seed, Tuple const& tuple) {
			hash_combine(seed, std::get<0>(tuple));
		}
	};
	template <typename ... TT>
	struct hash<std::tuple<TT...>> {
		size_t operator()(std::tuple<TT...> const& tt) const {
			size_t seed = 0;
			HashValueImpl<std::tuple<TT...> >::apply(seed, tt);
			return seed;
		}
	};
}
template<class T>int id(vector<T> &a, T b) {
	return lower_bound(ALL(a), b) - a.begin();
}
ll pow(ll base, ll i, ll mod) {
	ll a = 1;
	while (i) {
		if (i & 1) {
			a *= base;
			a %= mod;
		}
		base *= base;
		base %= mod;
		i /= 2;
	}
	return a;
}
ll gcd(ll a, ll b) {
	while (b) {
		ll c = a%b;
		a = b;
		b = c;
	}
	return a;
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b)*b;
}
#ifdef _MSC_VER
#include <intrin.h>
#endif
int popcnt(unsigned long long a) {
#ifndef _MSC_VER
	return __builtin_popcountll(a);
#else
	return _mm_popcnt_u32(a >> 32) + _mm_popcnt_u32(a);
	a = (a & 0x5555555555555555) + (a >> 1 & 0x5555555555555555);
	a = (a & 0x3333333333333333) + (a >> 2 & 0x3333333333333333);
	a = (a & 0x0f0f0f0f0f0f0f0f) + (a >> 4 & 0x0f0f0f0f0f0f0f0f);
	a = (a & 0x00ff00ff00ff00ff) + (a >> 8 & 0x00ff00ff00ff00ff);
	a = (a & 0x0000ffff0000ffff) + (a >> 16 & 0x0000ffff0000ffff);
	return (a & 0xffffffff) + (a >> 32);
#endif
}
int BitScanF(unsigned long a) {
#ifndef _MSC_VER
	return __builtin_ctz(a);
#else
	_BitScanForward(&a, a);
	return a;
#endif
}
int BitScanR(unsigned long a) {
#ifndef _MSC_VER
	return 63 - __builtin_clz(a);
#else
	_BitScanReverse(&a, a);
	return a;
#endif
}
template<class T>
class matrix {
public:
	vector<valarray<T>> obj;
	pair<int, int> s;
public:
	matrix(pair<int, int> size, T e = 0) :matrix(size.first, size.second, e) {}
	matrix(int n, int m = -1, T e = 0) :obj(n, valarray<T>(e, m == -1 ? n : m)), s(n, m == -1 ? n : m) {}
	static matrix e(int n) {
		matrix a = (n);
		for (int i = 0; i < n; i++)a[i][i] = 1;
		return a;
	}
	matrix& operator+=(const matrix &p) {
		if (s != p.s)throw runtime_error("matrix error");
		for (int i = 0; i < s.first; i++)
			for (int j = 0; j < s.second; j++)obj[i][j] += p.obj[i][j];
		return *this;
	}
	matrix operator+(const matrix &p) {
		matrix res(*this);
		return res += p;
	}
	matrix& operator-=(const matrix &p) {
		if (s != p.s)throw runtime_error("matrix error");
		for (int i = 0; i < s.first; i++)
			for (int j = 0; j < s.second; j++)obj[i][j] -= p.obj[i][j];
		return *this;
	}
	matrix operator-(const matrix &p) {
		matrix res(*this);
		return res -= p;
	}
	matrix& operator*=(T p) {
		for (auto &a : obj)
			for (auto &b : a)b *= p;
		return *this;
	}
	matrix operator*(T p) {
		matrix res(*this);
		return res *= p;
	}
	matrix operator*(const matrix &p) {
		if (s.second != p.s.first)throw runtime_error("matrix error");
		matrix ret(s.first, p.s.second);
		for (int i = 0; i < s.first; i++)
			for (int j = 0; j < s.second; j++)ret[i] += obj[i][j] * p.obj[j];
		return ret;
	}
	matrix &operator*=(const matrix &p) {
		return *this = *this*p;
	}
	bool operator==(const matrix&p) {
		if (s != p.s)return 0;
		rep(i, s.first)rep(j, s.second)if (obj[i][j] != p.obj[i][j])return 0;
		return 1;
	}
	pair<int, int> size() const {
		return s;
	}
	matrix &mod(T m) {
		for (auto &a : obj)
			for (auto &b : a)b %= m;
		return *this;
	}
	valarray<T>& operator[](int t) {
		return obj[t];
	}
	void gauss() {
		if (size().first + 1 != size().second)return;
		rep(i, size().first) {
			int p = i;
			repi(j, i, size().first)if (abs(obj[j][i]) > abs(obj[p][i]))p = j;
			swap(obj[i], obj[p]);
			if (abs(obj[i][i]) < 1e-8)return;//contniue;
			repi(j, i + 1, size().second)obj[i][j] /= obj[i][i];
			rep(j, size().first) {
				if (i != j) {
					repi(k, i + 1, size().second)obj[j][k] -= obj[j][i] * obj[i][k];
				}
			}
		}
	}
};
template<class T> inline
matrix<T> pow(matrix<T> &base, unsigned long long exp) {
	auto base_(base);
	if (base_.size().first != base_.size().second)throw runtime_error("matrix error");
	matrix<T> res = matrix<T>::e(base_.size().first);
	for (;;) {
		if (exp & 1)res *= base_;
		if (res.obj[0].size() > 100) {
			int a=0;
		}
		if (!(exp /= 2))break;
		base_ *= base_;
	}
	return res;
}
template<class T> inline
matrix<T> modpow(matrix<T> &base, unsigned long long exp, ll m) {
	auto base_(base);
	if (base.size().first != base_.size().second)throw runtime_error("matrix error");
	matrix<T> res = matrix<T>::e(base_.size().first);
	for (;;) {
		if (exp & 1)(res *= base_).mod(m);
		if (res.obj[0].size() > 100) {
			int a = 0;
		}
		if (!(exp /= 2))break;
		(base_ *= base_).mod(m);
	}
	return res;
}
class unionfind {
	vector<int> par, rank, size_;//????????§??????????????¢???????????????????????????rank???????????????size?????????
public:
	unionfind(int n) :par(n), rank(n), size_(n, 1) {
		iota(ALL(par), 0);
	}
	int find(int x) {
		if (par[x] == x)return x;
		return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y)return;
		if (rank[x] < rank[y])swap(x, y);
		par[y] = x;
		size_[x] += size_[y];
		if (rank[x] == rank[y])rank[x]++;
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int size(int x) {
		return size_[find(x)];
	}
};
//end of lib
//template<class S=void,int ptr_num, class T = char>class trie {
//	umap<T, trie<S, ptr_num, T> next;
//public:
//	S key;
//	trie<S, ptr_num, T>* ptr[ptr_num] = {};
//	trie(S &&data) :key(data) {}
//	trie(const S &data) :key(data) {}
//	void add(T x,S data) {
//		if (!next.find(x))next.insert(x, data);
//	}
//	trie& operator[](T x) {
//		return next[x];
//	}
//	bool find(T x) {
//		retun next.find(x);
//	}
//};
//template<class T=char>class AhoCorasick {
//	trie<pair<bool,int>, 2, T> tree;
//	AhoCorasick(vector<string> p) {
//		int num = 0;
//		vector<decltype(&tree)> que(p.size(),&tree);
//		for (int i = 0;; i++) {
//			bool end = 1;
//			int i = 0;
//			for (auto a : p) {
//				if (i >= a.size())break;
//				end = ;0
//				que[i] = (*que[i])[a[i]];
//				i++;
//			}
//			if (end)break;
//		}
//	}
//};
using namespace std;

struct state{
	vi kizoku;
	array<vi,3> action;
};
array<int, 3> f(state s,int p) {
	if (s.kizoku.empty())return{ 0,0,0 };
	auto s2 = s;
	s2.kizoku.erase(s2.kizoku.begin());
	auto ret = f(s2, (p + 1) % 3);
	ret[p] += s.kizoku.front();
	rep(i, s.action[p].size()) {
		if (s.action[p][i] > s.kizoku.size())continue;
		s2 = s;
		s2.action[p].erase(s2.action[p].begin() + i);
		s2.kizoku.erase(s2.kizoku.begin() + s.action[p][i] - 1);
		auto ret2 = f(s2, (p + 1) % 3);
		ret2[p] += s.kizoku[s.action[p][i] - 1];
		if (ret2[p] > ret[p])ret = ret2;
	}
	return ret;
}
array<int, 3> f2(state s, int p) {
	if (s.kizoku.empty())return{ 0,0,0 };
	auto s2 = s;
	s2.kizoku.erase(s2.kizoku.begin());
	auto sm = s2;
	if (p == 1) {
		auto ret = f2(s2, (p + 1) % 3);
		ret[p] += s.kizoku.front();
		rep(i, s.action[p].size()) {
			if (s.action[p][i] > s.kizoku.size())continue;
			s2 = s;
			s2.action[p].erase(s2.action[p].begin() + i);
			s2.kizoku.erase(s2.kizoku.begin() + s.action[p][i] - 1);
			auto ret2 = f2(s2, (p + 1) % 3);
			ret2[p] += s.kizoku[s.action[p][i] - 1];
			if (ret2[0]<ret[0])ret = ret2, sm = s2;
		}
		return ret;
	}
	auto ret = f(s2, (p + 1) % 3);
	int plus;
	ret[p] += plus = s.kizoku.front();
	rep(i, s.action[p].size()) {
		if (s.action[p][i] > s.kizoku.size())continue;
		s2 = s;
		s2.action[p].erase(s2.action[p].begin() + i);
		s2.kizoku.erase(s2.kizoku.begin() + s.action[p][i] - 1);
		auto ret2 = f(s2, (p + 1) % 3);
		ret2[p] += s.kizoku[s.action[p][i] - 1];
		if (ret2[p] > ret[p])ret = ret2, sm = s2, plus = s.kizoku[s.action[p][i] - 1];
	}
	ret= f2(sm, (p + 1) % 3);
	ret[p] += plus;
	return ret;
}


int main() {
	state s;
	s.kizoku.resize(12);
	rrep(i, 12)cin >> s.kizoku[i];
	rep(i, 3) {
		s.action[i].resize(2);
		rep(j, 2)cin >> s.action[i][j];
		sort(ALL(s.action[i]));
	}
	auto ret = f2(s, 0);
	cout << ret[0] << " " << ret[1] << " " << ret[2] << endl;
}