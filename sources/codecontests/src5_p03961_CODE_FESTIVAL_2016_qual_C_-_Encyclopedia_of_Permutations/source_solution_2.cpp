#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#define MAXN 500005
#define LL long long
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define MOD 1000000007
using namespace std;
int use[MAXN], n;
LL T1[MAXN], T2[MAXN];
void add(int k, int num, LL T[])
{
    while(k <= n)
    {
        T[k] += num;
        T[k] %= MOD;
        k += k & -k;
    }
}
LL read(int k, LL T[])
{
    LL sum = 0;
    while(k)
    {
        sum += T[k];
        sum %= MOD;
        k -= k & -k;
    }
    return sum;
}
struct Node
{
    LL sum, lazy, num;
}tree[MAXN << 2];
void pushUp(int rt)
{
    tree[rt].sum = (tree[rt << 1].sum + tree[rt << 1 | 1].sum) % MOD;
    tree[rt].num = (tree[rt << 1].num + tree[rt << 1 | 1].num) % MOD;
}
void pushDown(int rt)
{
    if(tree[rt].lazy)
    {
        tree[rt << 1].sum += (tree[rt << 1].num * tree[rt].lazy);
        tree[rt << 1].sum %= MOD;
 
        tree[rt << 1 | 1].sum += (tree[rt << 1 | 1].num * tree[rt].lazy);
        tree[rt << 1 | 1].sum %= MOD;
 
        tree[rt << 1].lazy += tree[rt].lazy;
        tree[rt << 1].lazy %= MOD;
 
        tree[rt << 1 | 1].lazy += tree[rt].lazy;
        tree[rt << 1 | 1].lazy %= MOD;
 
        tree[rt].lazy = 0;
    }
}
void buildTree(int l, int r, int rt)
{
    tree[rt].lazy = tree[rt].sum = tree[rt].num = 0;
    if(l == r)
    {
        if(!use[l]) tree[rt].num = 1;
        return;
    }
    int m = (l + r) >> 1;
    buildTree(lson);
    buildTree(rson);
    pushUp(rt);
}
 
void update(int ll, int rr, LL add, int l, int r, int rt)
{
    if(ll <= l && r <= rr)
    {
        tree[rt].lazy += add;
        tree[rt].lazy %= MOD;
        tree[rt].sum += (tree[rt].num * add);
        tree[rt].sum %= MOD;
        return;
    }
    pushDown(rt);
    int m = (l + r) >> 1;
    if(ll <= m) update(ll, rr, add, lson);
    if(rr >  m) update(ll, rr, add, rson);
    pushUp(rt);
}
int star[MAXN];
LL fac[MAXN];
int main()
{
    scanf("%d", &n);
    fac[0] = 1LL;
    for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * (LL)i % MOD, use[i] = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &star[i]);
        use[star[i]] = 1;
    }
    buildTree(1, n, 1);
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!use[i])
        {
            sum++;
            add(i, 1, T2);
        }
    }
    LL ans = fac[sum];
    int suf = 0;
    for(int i = n; i > 0; i--)
    {
        LL tmp1 = 0, tmp2 = 0;
        if(star[i])
        {
            LL x = read(star[i] - 1, T1);
            tmp1 = x * fac[sum] % MOD * fac[n - i] % MOD;
            LL y = read(star[i], T2);
            if(sum >= 1) tmp2 = y * (LL)suf % MOD * fac[sum - 1] % MOD * fac[n - i] % MOD;
            ans = (ans + tmp1 + tmp2) % MOD;
            add(star[i], 1, T1);
            update(star[i], n, 1, 1, n, 1);
        }
        else
        {
            if(sum >= 2) tmp1 = ((LL)sum * (LL)(sum - 1) / 2LL) % MOD * fac[sum - 2] % MOD * suf % MOD * fac[n - i] % MOD;
            if(sum >= 1) tmp2 = tree[1].sum * fac[sum - 1] % MOD * fac[n - i] % MOD;
            ans = (ans + tmp1 + tmp2) % MOD;
            suf++;
        }
    }
    printf("%d\n", (int)ans);
    return 0;
}