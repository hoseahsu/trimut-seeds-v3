#include <bits/stdc++.h>
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define endl '\n'

using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1000000007;
const int dx[] = { 0, 0, -1, 1, 1, -1,  1, -1};
const int dy[] = {-1, 1,  0, 0, 1, -1, -1,  1};

string lltos(ll x, int m){
  string ans;
  for(int i=m-1; i>=0; i--){
    if((x>>i)&1)
      ans += '1';
    else
      ans += '0';
  }
  return ans;
}

int n, m;

const int MAXN = 200010;
int f[(1<<15)];
int dp[(1<<15)][15], b;

int solve(int mask, int i){
  if(i == b)
    return f[mask];
  if(dp[mask][i] != -1)
    return dp[mask][i];
  if((mask>>i)&1)
    return dp[mask][i] = solve(mask, i+1);
  else
    return dp[mask][i] = solve(mask, i+1) + solve(mask | (1<<i), i+1);
}

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

inline double rand(double l, double r){
  return uniform_real_distribution<double>(l, r)(rng);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int p;
  cin >> n >> m >> p;

  vector<ll> v(n);
  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    v[i] = stoll(s, nullptr, 2);
  }
  
  ll ans = 0;
  int cnt = 0;
  for(int it=0; it<min(n, 50); it++){
    ll mask = v[rand(0, n-1)];
    vector<int> v2(n, 0);
    vector<int> active;
    for(int j=m-1; j>=0; j--){
      if((mask>>j)&1){
        active.push_back(j);
        for(int i=0; i<n; i++)
          v2[i] = ((v2[i]<<1) | ((v[i]>>j)&1));
      }
    }
    b = active.size();
    
    memset(dp, -1, sizeof(dp));
    memset(f, 0, sizeof(f));
    
    for(int x: v2){
      f[x]++;
    }
    for (ll s = mask; s; s = ((s - 1LL) & mask)){
      int s2 = 0;
      for(int j: active)
        s2 = ((s2<<1) | ((s>>j)&1));
      int x = solve(s2, 0);

      if(2*x >= n){
        int a=0;
        for(int j: active){
          if((s>>j)&1)
            a++;
        }
        if(a > cnt){
          ans = s;
          cnt = a;
        }
      }
    }
  }
  
  cout << lltos(ans, m) << endl;
  return 0;
}
