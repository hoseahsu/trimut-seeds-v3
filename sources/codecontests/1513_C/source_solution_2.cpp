#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const ll mod = 1000000007;
vector<ll> cnt(200005);
void preprosy(){
	vector<ll> mp(10, 0); mp[9] = 1;
	for(ll i = 0; i < 200005; i++){
		vector<ll> t = mp;
		for(ll j = 0; j < 10; j++){
			cnt[i] = (cnt[i] + mp[j]) % mod;
			mp[j] = t[(j + 9) % 10];
			if(j == 1) mp[j] = (mp[j] + t[9]) % mod;
		}
	}
}
string s;
ll n;
void brute(){
	vector<ll> mp(10, 0);
	for(char x : s) mp[x - '0']++;
	for(ll i = 0; i < n; i++){
		vector<ll> t = mp;
		for(ll j = 0; j < 10; j++){
			mp[j] = t[(j + 9) % 10];
			if(j == 1) mp[j] = (mp[j] + t[9]) % mod;
		}
	}
	ll ans = 0;
	for(ll i = 0; i < 10; i++) ans += mp[i];
	cout << ans << "\n";
}
void solve(){
	cin >> s;
	cin >> n;
	if(n <= 9) {brute(); return;}
	vector<ll> mp(10, 0); for(char x : s) mp[x - '0']++;
	ll ans = 0;
	for(ll i = 0; i < 10; i++){
		ans = (ans + (mp[i] * cnt[n - (9 - i)] % mod)) % mod;
	}
	cout << ans << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
    preprosy();
  ll t;
  cin >> t;

  while(t--){

    solve();
  }  
  return 0;
}

