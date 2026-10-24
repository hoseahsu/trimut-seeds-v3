#include<bits/stdc++.h>
using namespace std;
#define maxn 100020
#define rep(i,l,r) for(register int i = l ; i <= r ; i++)
#define repd(i,r,l) for(register int i = r ; i >= l ; i--)
#define rvc(i,S) for(register int i = 0 ; i < (int)S.size() ; i++)
#define rvcd(i,S) for(register int i = ((int)S.size()) - 1 ; i >= 0 ; i--)
#define fore(i,x)for (register int i = head[x] ; i ; i = e[i].next)
#define pb push_back
#define prev prev_
#define stack stack_
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
typedef long long ll;
typedef pair<int,int> pr;

const ll mod = 998244353;
ll ans = 1;
int a[maxn],n;

ll gcd(ll x,ll y){ 
	if ( !y ) return x;
	return gcd(y,x % y);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	sort(a + 1,a + n + 1);
	rep(i,1,n) ans = ans * gcd(a[i],i - 1) % mod;
	cout<<ans<<endl;
}
