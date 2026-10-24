#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

int n;
int a[500010];


int solve(){
    int c[3] = {};
    rep(i,n) ++c[a[i]%3];
    int x = c[0];
    int y = c[1];
    int z = c[2];
    if(y > z) swap(y,z);
    if(y == 0 && z == 0) return 1;
    int ans = 0;
    ans += x;
    if(y > 0 || z > 0){
        int l = min(y,z);
        ans += l*2;
        y -= l;
        z -= l;
        ans += max(min(y,3), min(z,3));
    } else {
        ans += y + z;
    }
    return ans;
}

int main(){
    while(cin >> n){
        rep(i,n) cin >> a[i];
        cout << solve() << endl;
    }
}