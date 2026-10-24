#include<bits/stdc++.h>
#define mod 1000000007
#define reg register
#define maxn 2000006
using namespace std;
int inv[maxn], fac[maxn], ifac[maxn], X1, X2, X3, X4, X5, X6,  Y1, Y2, Y3, Y4, Y5, Y6;
int f[maxn], g[maxn], ans;
int inc(int x, int y){
    return x + y >= mod ? x + y - mod : x + y;
}
int C(int x, int y){
    return 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int get_dis(int x1, int y1, int x2, int y2){
    int lenx = abs(x2 - x1), leny = abs(y2 - y1);
    return C(lenx + leny, lenx);
}
int get2(int x, int y, int l, int r, int d, int u){
    int res = 0;
    res = inc(get_dis(x, y, r + 1, u + 1), res);
    res = inc(mod - get_dis(x, y, l, u + 1), res);
    res = inc(mod - get_dis(x, y, r + 1, d), res);
    res = inc(get_dis(x, y, l, d), res);
    return res;
}
int get1(int x, int y, int l, int r, int d, int u){
    int res = 0;
    res = inc(res, get_dis(x, y, r, u));
    res = inc(res, mod - get_dis(x, y, l - 1, u));
    res = inc(res, mod - get_dis(x, y, r, d - 1));
    res = inc(res, get_dis(x, y, l - 1, d - 1));
    return res;
}
int main(){
    cin >> X1 >> X2 >> X3 >> X4 >> X5 >> X6;
    cin >> Y1 >> Y2 >> Y3 >> Y4 >> Y5 >> Y6;
    inv[0] = 1; ifac[0] = 1; fac[0] = 1;
    for(int i = 1; i < maxn; i++) {
        fac[i] = 1ll * fac[i - 1] * i % mod;
        inv[i] = (i == 1) ? 1 : 1ll * inv[mod % i] * (mod - mod / i) % mod;
        ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod;
    }
    for(int i = Y3; i <= Y4; i++) {
        f[i] = get1(X4, i, X1, X2, Y1, Y2);
        f[i] = 1ll * f[i] * get2(X4 + 1, i, X5, X6, Y5, Y6) % mod;
        f[i] = 1ll * f[i] * (X4 + i + 1) % mod;
        ans = inc(ans, f[i]);
    }
    for(int i = X3; i <= X4; i++) {
        g[i] = get1(i, Y4, X1, X2, Y1, Y2);
        g[i] = 1ll * g[i] * get2(i, Y4 + 1, X5, X6, Y5, Y6) % mod;
        g[i] = 1ll * g[i] * (i + Y4 + 1) % mod;
        ans = inc(ans, g[i]);
    }
    //cout << ans << endl;
    for(int i = Y3; i <= Y4; i++) {
        f[i] = get1(X3 - 1, i, X1, X2, Y1, Y2);
        f[i] = 1ll * f[i] * get2(X3, i, X5, X6, Y5, Y6) % mod;
        f[i] = 1ll * f[i] * (mod - X3 - i) % mod;
        ans = inc(ans, f[i]);
    }
   // cout << 
    for(int i = X3; i <= X4; i++) {
        g[i] = get1(i, Y3 - 1, X1, X2, Y1, Y2);
        g[i] = 1ll * g[i] * get2(i, Y3, X5, X6, Y5, Y6) % mod;
        g[i] = 1ll * g[i] * (mod - Y3 - i) % mod;
        ans = inc(ans, g[i]);
    }
    cout << ans << endl;
}