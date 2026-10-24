#include <bits/stdc++.h>

using namespace std;

int n,l;

void solve(){
    int i,j,k;
    cin >> l >> n;
    vector<int> x(n);
    vector<long long> xp(n+1),xi(n+1);
    xp[0] = 0;
    xi[n] = 0;
    for(i = 0;i < n;i++){
        cin >> x[i];
        xp[i+1] = xp[i] + x[i];
    }
    for(i = n-1;i >= 0;i--){
        xi[i] = xi[i+1] + (l-x[i]);
    }
    long long ans = 0;
    long long a = 0;
    a = l-x[0];
    if(a > ans) ans = a;
    a = x[n-1];
    if(a > ans) ans = a;
    for(i = 1;i < n;i++){
        k = min(i,n-i-1);
        a = l-x[i];
        a += 2*(xi[i+1]-xi[i+1+k]);
        a += 2*(xp[i]-xp[i-k]);
        if(i > n-i-1) a += 2*x[i-k-1];
        if(a > ans) ans = a;
        k = min(i-1,n-i);
        a = x[i-1];
        a += 2*(xi[i]-xi[i+k]);
        a += 2*(xp[i-1]-xp[i-1-k]);
        if(n-i > i-1) a += 2*(l-x[i+k]);
        if(a > ans) ans = a;
    }
    cout << ans << endl;
}

int main(){
    solve();
}
