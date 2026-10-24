#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map> 
#include <unordered_set>
#include <functional>

using namespace std;

typedef pair<long long int, long long int> P;
typedef tuple<int, int, int> T;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

// 入力文字列は vector<int> 型に直し、後ろに番兵として存在しない小さな値(0 とか)を追加すること

// suffix array, LCP array を O(N) で構築する。
// 部分文字列の検索は、クエリの文字数を M として O(M + log(N)) である。

bool isLMS(vector<int> &t, int i){
	return i > 0 && t[i - 1] == 'L' && t[i] == 'S';
}

vector<int> inducedSort(vector<int> &s, int k, vector<int> &t, vector<int> &seed){
	vector<int> sa(s.size(), -1);
	// 文字 c で始まる文字列は、sa の bin[c] ~ bin[c + 1] - 1 番目に入る
	vector<int> bin(k + 1);
	for(int c : s){
		bin[c + 1] += 1;
	}
	for(int i = 0; i < k; i++){
		bin[i + 1] += bin[i];
	}
	// LMS 型の文字列のインデックスを、sa の bin[c] ~ bin[c + 1] - 1 番目に後ろの方から入れる
	vector<int> cnt(k, 0);
	reverse(seed.begin(), seed.end());
	for(int i : seed){
		int c = s[i];
		sa[bin[c + 1] - 1 - cnt[c]] = i;
		cnt[c] += 1;
	}
	// L 型の文字列のインデックスを、sa の先頭から埋めていく
	cnt.clear();
	cnt.resize(k, 0);
	for(int pos = 0; pos < sa.size(); pos++){
		int i = sa[pos];
		if(i == -1 || i == 0 || t[i - 1] == 'S'){
			continue;
		}
		int c = s[i - 1];
		sa[bin[c] + cnt[c]] = i - 1;
		cnt[c] += 1;
	}
	// S 型の文字列のインデックスを、sa の後ろ側から埋めていく。LMS 型は上書きされる
	cnt.clear();
	cnt.resize(k, 0);
	for(int pos = sa.size() - 1; pos >= 0; pos--){
		int i = sa[pos];
		if(i == -1 || i == 0 || t[i - 1] == 'L'){
			continue;
		}
		int c = s[i - 1];
		sa[bin[c + 1] - 1 - cnt[c]] = i - 1;
		cnt[c] += 1;
	}
	return sa;
}

vector<int> saIs(vector<int> &s, int k){
	// L 型と S 型の文字列を分類
	vector<int> t(s.size());
	t[s.size() - 1] = 'S';
	for(int i = s.size() - 2; i >= 0; i--){
		if(s[i] < s[i + 1]){
			t[i] = 'S';
		}else if(s[i] > s[i + 1]){
			t[i] = 'L';
		}else{
			t[i] = t[i + 1];
		}
	}
	// LMS 型の文字列のインデックスを取り出す
	vector<int> lmss, seed;
	for(int i = 0; i < s.size(); i++){
		if(isLMS(t, i)){
			lmss.push_back(i);
			seed.push_back(i);
		}
	}
	// seed から sa を構築し、LMS 型の文字列の辞書順を取得
	vector<int> sa = inducedSort(s, k, t, seed);
	vector<int> sa_;
	for(int i : sa){
		if(isLMS(t, i)){
			sa_.push_back(i);
		}
	}
	sa = sa_;
	// LMS 間の部分文字列を、辞書順を保った数字に置き換える
	vector<int> nums(s.size() + 1, -1);
	nums[sa[0]] = 0;
	int num = 0;
	for(int pos = 0; pos < sa.size() - 1; pos++){
		int i = sa[pos], j = sa[pos + 1];
		bool diff = false;
		for(int d = 0; d < s.size(); d++){
			if(s[i + d] != s[j + d] || isLMS(t, i + d) != isLMS(t, j + d)){
				diff = true;
				break;
			}
			if(d > 0 && (isLMS(t, i + d) || isLMS(t, j + d))){
				break;
			}
		}
		if(diff){
			num += 1;
		}
		nums[j] = num;
	}
	vector<int> nums_;
	for(int i : nums){
		if(i >= 0){
			nums_.push_back(i);
		}
	}
	nums = nums_;
	// 辞書順を保った数字に重複がある場合、再帰
	// そうでない場合、LMS 部分文字列(seed) の正しい順序を求められる
	vector<int> seedOrder;
	if(num + 1 < nums.size()){
		seedOrder = saIs(nums, num + 1);
	}else{
		seedOrder.resize(nums.size());
		for(int i = 0; i < nums.size(); i++){
			seedOrder[nums[i]] = i;
		}
	}
	seed.clear();
	for(int i : seedOrder){
		seed.push_back(lmss[i]);
	}
	// 正しい seed で sa を求める
	sa = inducedSort(s, k, t, seed);
	return sa;
}

vector<int> LCP(vector<int> &s, vector<int> &sa){
	// rnk[i] : S[i:] は sa の中で何番目か
	vector<int> rnk(sa.size());
	for(int i = 0; i < sa.size(); i++){
		rnk[sa[i]] = i;
	}
	// S[i:] と S[sa[rnk[i] + 1]:] の lcp を求める
	vector<int> lcpArray(sa.size());
	int lcp = 0;
	for(int i = 0; i < sa.size(); i++){
		int index = rnk[i];
		if(index == sa.size() - 1){
			lcp = 0;
			lcpArray[index] = 0;
			continue;
		}
		int pos1 = sa[index];
		int pos2 = sa[index + 1];
		while(s[pos1 + lcp] == s[pos2 + lcp]){
			lcp += 1;
		}
		lcpArray[index] = lcp;
		lcp = max(lcp - 1, 0);
	}
	return lcpArray;
}

int const TREE_SIZE = (1 << 21);

class SegTree{
	public:
	// コンストラクタ
	SegTree(std::function<long long int(long long int, long long int)> monoidFunc_, long long int invalidValue_){
		monoidFunc = monoidFunc_;
		invalidValue = invalidValue_;
	}
	// 値の初期化
	void init(long long int initValue){
		for(int i = 0; i < TREE_SIZE; i++){
			segTree[i] = initValue;
		}
	}
	// a番目(0-indexed)をwに変更する O(log N)
	void change(int a, long long int w){
		change_(a + 1, w);
	}
	// 区間 [a, b] (0-indexed)の値を求める O(log N)
	long long int query(int a, int b){
		return query_(a + 1, b + 2, 1, 0, TREE_SIZE / 2);
	}
	private:
	function<long long int(long long int, long long int)> monoidFunc;
	long long int invalidValue;
	long long int segTree[TREE_SIZE]; // 1-indexed

	// a番目をwに変更する O(log N)
	void change_(int a, long long int w){
		a += TREE_SIZE / 2;
		segTree[a] = w;
		for(int x = a / 2; x > 0; x /= 2){
			segTree[x] = monoidFunc(segTree[2 * x], segTree[2 * x + 1]);
		}
	}
	// 区間 [a, b) の値を求める O(log N)
	// query(a, b, 1, 0, TREE_SIZE / 2) のように呼ぶ
	long long int query_(int a, int b, int index, int l, int r){
		if(r <= a || b <= l){
			return invalidValue;
		}
		if(a <= l && r <= b){
			return segTree[index];
		}
		return monoidFunc(query_(a, b, index * 2, l, (l + r) / 2), query_(a, b, index * 2 + 1, (l + r) / 2, r));
	}
};

long long int func(long long int a, long long int b){
	return min(a, b);
}
SegTree segTree(func, INF);

// 文字列 T の中に文字列 P が出現する位置を一つ返す
// 存在しない場合、-1 を返す
int findPos(string &T, string &P, vector<int> &sa, vector<int> &lcpArray){
	int pos = 0;
	// [L, R) に存在する、とおく
	int L = 0, R = sa.size();
	while(R - L > 1){
		while(P[pos] == T[sa[L] + pos]){
			pos += 1;
		}
		int M = (L + R) / 2;
		int lcp = segTree.query(L, M - 1);
		if(pos > lcp){
			R = M;
		}else if(pos < lcp){
			L = M;
		}else{
			bool flag = true;
			for(int i = pos; i < P.size(); i++){
				if(P[i] != T[sa[M] + i]){
					flag = (P[i] > T[sa[M] + i]);
					break;
				}
			}
			if(flag){
				L = M;
			}else{
				R = M;
			}
		}
	}
	for(int i = 0; i < P.size(); i++){
		if(P[i] != T[sa[L] + i]){
			return -1;
		}
	}
	return L;
}

int main(){
	string T;
	cin >> T;
	vector<int> vs;
	for(int c : T){
		vs.push_back(c);
	}
	vs.push_back(0);
	vector<int> sa = saIs(vs, 256);
	vector<int> lcpArray = LCP(vs, sa);
	/*
	for(int i = 0; i < sa.size(); i++){
		cout << i << " " << sa[i] << " " << lcpArray[i] << " " << T.substr(sa[i]) << endl;
	}
	*/
	segTree.init(INF);
	for(int i = 0; i < lcpArray.size(); i++){
		segTree.change(i, lcpArray[i]);
	}
	// Q 回のクエリに対し、文字列 T の中に文字列 P が出現するかどうかを判定する
	int Q;
	cin >> Q;
	for(int loop = 0; loop < Q; loop++){
		string P;
		cin >> P;
		cout << (findPos(T, P, sa, lcpArray) >= 0) << endl;
	}
	return 0;
}

