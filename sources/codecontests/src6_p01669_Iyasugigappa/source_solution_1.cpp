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
  

vector<int>nobles(12);
vector<vector<int>>cards(3, vector<int>(2));


struct result {
	bool isini;
	vector<int>scores;
	vector<vector<int>>used;
	result() :isini(true),scores(), used() {

	}
	result(const vector<int>&scores_, const vector<vector<int>>&used_):isini(false),scores(scores_),used(used_) {

	}
	
};
bool compare(const result&l, const result&r,const int now,const bool kappathink) {
	if (l.isini)return true;
	else {
		if (now == 1&&kappathink) {
			if (l.scores[0] < r.scores[0])return false;
			else if (l.scores[0]>r.scores[0])return true;
		}
		else {
			if (l.scores[now] < r.scores[now])return true;
			else if (l.scores[now]>r.scores[now])return false;
		}
		int luse=0, ruse=0, ltotal=0, rtotal=0;
		for (int i = 0; i < 2; ++i) {
			if (l.used[now][i]) {
				luse++;
				ltotal += cards[now][i];
			}
			if (r.used[now][i]) {
				ruse++;
				rtotal += cards[now][i];
			}
		}
		return luse == ruse ? ltotal < rtotal : luse < ruse;
	}
}
result memo[4096][64][3][2];

int getnum(const bitset<12>&v, int num) {
	for (int i = 11; i >= 0; --i) {
		if (v[i]) {
			num--;
			if (!num)return  i;
		}
	}
	return -1;
}

int gethash(const vector<vector<int>>&vs) {
	int num = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 2; ++j) {
			num *= 2;
			if (vs[i][j])num++;
		}
	}
	return num;
}

result getans(const int now, vector<vector<int>>&used, bitset<12>&lives,bool kappathink) {
	if (!memo[lives.to_ulong()][gethash(used)][now][kappathink].isini)return memo[lives.to_ulong()][gethash(used)][now][kappathink];
	
	if (!lives.count()) {
		return memo[lives.to_ulong()][gethash(used)][now][kappathink]=result{ vector<int>(3,0),used };
	}
	else {
		result nowres;
		result nowrealres;
		{
			vector<int>scores(3);

			const int pl = getnum(lives, 1);
			assert(pl != -1);
			{
				assert(lives[pl]);
				lives[pl] = false;
				result res = getans((now + 1) % 3, used, lives, kappathink&&(now == 1));
				result realres = getans((now + 1) % 3, used, lives, kappathink);
				lives[pl] = true;
				res.scores[now] += nobles[pl];
				realres.scores[now] += nobles[pl];
				if (compare(nowres, res, now, kappathink)) {
					nowres = res;
					nowrealres = realres;
				}
			}
		}
		for (int i = 0; i < 2; ++i) {
			if (used[now][i]) {
				used[now][i] = false;
				int pl = getnum(lives, cards[now][i]);
				if (pl == -1) {
					pl = getnum(lives, 1);
				}
				{
					assert(pl != -1);
					assert(lives[pl]);
					lives[pl] = false;
					result res = getans((now + 1) % 3, used, lives, kappathink&&(now == 1));
					result realres = getans((now + 1) % 3, used, lives, kappathink);
					lives[pl] = true;
					res.scores[now] += nobles[pl];
					realres.scores[now] += nobles[pl];
					if (compare(nowres, res, now, kappathink)) {
						nowres = res;
						nowrealres = realres;
					}
				}
				used[now][i] = true;
			}
		}
		return memo[lives.to_ulong()][gethash(used)][now][kappathink] = nowrealres;
	}
}

int main() {
	for (int i = 0; i < 4096; ++i) {
		for (int j = 0; j < 64; ++j) {
			for (int k = 0; k < 3; ++k) {
				for (int l = 0; l < 2; ++l) {
					memo[i][j][k][l] = result();
				}
			}
		}
	}
	for (int i = 0; i < 12; ++i)cin >> nobles[i];
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 2; ++j) {
			cin >> cards[i][j];
		}
	}

	vector<vector<int>>used(3, vector<int>(2,1));
	bitset<12>bs((1<<12)-1);
	result ans = getans(0, used, bs, true);
	cout << ans.scores[0] << " "<<ans.scores[1]<<" " << ans.scores[2] << endl;

	return 0;
}