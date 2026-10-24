#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;(i)<(n);++(i))

using namespace std;
using ll = long long;
const ll mod = 1000000007LL;

ll power(ll a,ll n){
	if(n < 0) return 0;
	ll b=1LL;
	while(n){
		if(n&1) b= b*a % mod;
		a = a*a % mod;
		n >>= 1;
	}
	return b;
}

template <class T> bool chmin(T &a,const T &b){return (b<a)?(a=b,1):0;}

const int limit = 100010;
ll fact[limit];
ll ifact[limit];

inline ll Fact(ll n){
	if(n < 0) return 0;
	return fact[n];
}

inline ll Comb(ll n,ll k){
	if(n <0 or k<0 or n-k <0) return 0LL;
	return fact[n] * ifact[k] % mod * ifact[n-k] % mod;
}

int main() {
	fact[0]=1LL;
	rep(i,limit-1) fact[i+1] = 1LL * (i+1) * fact[i] % mod;
	ifact[limit-1] = power(fact[limit-1],mod-2);
	for(int i = limit -2; i >=0 ; --i) ifact[i] = 1LL * (i+1) * ifact[i+1] % mod;

	int n;
	while(cin >> n,n){
		vector<int> a(n),ra(n,-1),used(n,0),num;

		rep(i,n) cin >> a[i],a[i]--;

		rep(i,n){
			if(i==a[a[i]]) continue;
			ra[a[i]]=i;
		}

		rep(i,n){
			const int j = a[i];
			if(i > j or i != a[j]) continue;

			used[i]=used[j]=true;
			int cnt = 2;

			{
				int cur = ra[i];
				while(cur!=-1){
					used[cur] = true;
					cnt++;
					cur = ra[cur];
				}
			}

			{
				int cur = ra[j];
				while(cur!=-1){
					used[cur] = true;
					cnt++;
					cur = ra[cur];
				}
			}

			num.push_back(cnt);
		}

		ll ans = 0LL,two = 0LL;
		
		bool ok = true;
		rep(i,n) if(used[i]==false) ok =false;
		for(auto &elem:num) if(elem==2) two++;
		
		const ll k = num.size();
		const ll three = k - two;

		if(k == 0 or ok == false){
			cout << 0LL << endl;
			continue;
		}

		//cerr << three << " " << two << endl;

		if(three == 0){
			ll cur = ((k+2)/2);
			cur = cur * Fact(k) % mod;
			ans = (ans + cur) % mod;
		}

		if(three >= 1){
			rep(i,k+1){
				ll cur = 2LL * ((i+2)/2LL);
				cur = cur * Comb(two,i) % mod;
				cur = cur * Fact(i) % mod;
				cur = cur * Comb(three,1) % mod;
				cur = cur * Fact(two-i+three-1) % mod;
				ans = (ans + cur) % mod;
			}
		}

		
		if(three >= 2){
			rep(i,k+1){
				ll cur = 2LL * ((i+2)/2LL);
				cur = cur * Comb(two,i) % mod;
				cur = cur * Fact(i) % mod;
				cur = cur * Comb(three,2) % mod;
				cur = cur * Fact(two-i+three-2) % mod;
				cur = cur * (two -i + three -2 + 1) % mod;
				ans = (ans + cur) % mod;
			}
		}

		ans = 1LL * ans * power(2,k) % mod;
		cout << ans << endl; 

	}			
	
	return 0;
}