#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;



const int mod = 1000000007;
struct Mod {
public:
	int num;
	Mod() : Mod(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) {
		static_assert(mod<INT_MAX / 2, "mod is too big, please make num 'long long int' from 'int'");
	}
	Mod(int n) : Mod(static_cast<long long int>(n)) { ; }
	operator int() { return num; }
};

Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator+(const Mod a, const long long int  b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator*(const Mod a, const long long int b) { return Mod(b)*a; }
Mod operator*(const Mod a, const int b) { return Mod(b)*a; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator*=(Mod& a, const long long int &b) { return a = a * b; }
Mod operator^(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
	if (n % 2) res = res * a;
	return res;
}
Mod mod_pow(const Mod a, const long long  int n) {
	if (n == 0) return Mod(1);
	Mod res = mod_pow((a * a), (n / 2));
	if (n % 2) res = res * a;
	return res;
}

Mod inv(const Mod a) { return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) {
	assert(b.num != 0);
	return a * inv(b);
}
Mod operator/(const long long int a, const Mod b) {
	return Mod(a) / b;
}
Mod operator/=(Mod &a, const Mod b) {
	return a = a / b;
}

#define MAX_MOD_N 1024000

Mod fact[MAX_MOD_N], factinv[MAX_MOD_N];
void init(const int amax = MAX_MOD_N) {
	fact[0] = Mod(1); factinv[0] = 1;
	for (int i = 0; i < amax - 1; ++i) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		factinv[i + 1] = factinv[i] / Mod(i + 1);
	}
}
Mod comb(const int a, const int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}

int dfs(const vector<vector<int>>&rev_edges,const int now, vector<int>&used) {
	if(used[now])assert(false);
	used[now]=true;
	if (rev_edges[now].size() == 0) {
		return 1;
	}
	assert(rev_edges[now].size() == 1) ;{
		return 1+dfs(rev_edges,rev_edges[now][0],used);
	}
}

int main()
{
	init();
	while (true) {
		int N;cin>>N;
		if(!N)break;
		vector<int>edges;
		vector<vector<int>>rev_edges(N);
		for (int i = 0; i < N; ++i) {
			int a;cin>>a;
			edges.push_back(a-1);
			rev_edges[a-1].push_back(i);
		}
		bool ok=true;
		if(any_of(rev_edges.begin(), rev_edges.end(), [](const vector<int>&v) {return v.size() >= 3; }) ){
			ok=false;
		}
		Mod ans=0;
		if (ok) {
			vector<int>loves(N, -1);
			for (int i = 0; i < N; ++i) {
				if (i == edges[edges[i]]) {
					loves[i]=edges[i];
				}
			}
			for (int i = 0; i < N; ++i) {
				if (rev_edges[i].size() == 2 && loves[i] ==  -1) {
					ok=false;
				}
			}
			if (ok) {
				vector<int>used(N);
				vector<int>nums(N);
				for (int i = 0; i < N; ++i) {
					if (!used[i]) {
						if (loves[i]!=-1) {
							used[i] = true;
							if (rev_edges[i].size() == 1) {
								nums[i]=1;
							}
							else {
								for (auto e : rev_edges[i]) {
									if (e != edges[i]) {
										nums[i]=1+dfs(rev_edges,e,used);
									}
								}
							}
						}
					}
				}
				if (find_if(used.begin(), used.end(), [](const int a) {return a == false; }) != used.end()) {
					ok=false;
				}
				if (ok) {
					ans = 1;
					vector<int>v;
					for (int i = 0; i < N; ++i) {
						if (loves[i]!=-1) {
							if(i<edges[i])continue;
							int num = nums[i] + nums[edges[i]];
							v.push_back(num);
						}
					}

					const int two_num=count(v.begin(),v.end(),2);
					const int other_num=v.size()-two_num;

					ans=fact[other_num];
					ans*=mod_pow(2,two_num+other_num);

					ans*=fact[two_num];

					Mod kake=0;
					for (int t = 0; t <= two_num / 2; ++t) {
						const int rest=two_num-2*t;

						if(rest>other_num+1)continue;
						else {
							Mod plus=0;
							plus=comb(other_num+t,t);
							plus*=comb(other_num+1,rest);
							plus*=other_num+1+t;
							kake+=plus;
						}
					}
					ans*=kake;
				}
			}
			
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
