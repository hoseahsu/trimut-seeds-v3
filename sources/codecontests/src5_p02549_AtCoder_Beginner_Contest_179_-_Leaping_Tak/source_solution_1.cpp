#include<bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 998244353;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> l(k), r(k);
    for(int i=0;i<k;i++) cin >> l[i] >> r[i];

    ll dp[200005], sum[200005];
    dp[1] = 1;
    sum[1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<k;j++){
            if(i-l[j] > 0) dp[i] += sum[i-l[j]];
            if(i-r[j]-1 > 0) dp[i] -= sum[i-r[j]-1];
            dp[i] %= mod;
        }
        sum[i] = sum[i-1] + dp[i];
    }

    cout << dp[n] << endl;
}