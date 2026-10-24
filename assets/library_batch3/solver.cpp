#include <bits/stdc++.h>
using namespace std;using ll=long long;using ull=unsigned long long;using u128=__uint128_t;
#ifndef TASK
#define TASK 0
#endif
#ifndef MUTANT
#define MUTANT 0
#endif
#ifndef SLOW
#define SLOW 0
#endif
const ll MOD=998244353;
ll power(ll a,ll n,ll mod){ll r=1;for(;n;n>>=1,a=a*a%mod)if(n&1)r=r*a%mod;return r;}
void zeta(vector<ll>&a,int n,bool inv,bool isand){for(int b=0;b<n;b++)for(int i=0;i<(1<<n);i++)if((bool)(i>>b&1)!=isand){int j=i^(1<<b);a[i]=(a[i]+(inv?-a[j]:a[j])+MOD)%MOD;}}
void fwht(vector<ll>&a,bool inv){int n=a.size();for(int w=1;w<n;w*=2)for(int i=0;i<n;i+=2*w)for(int j=0;j<w;j++){ll x=a[i+j],y=a[i+j+w];a[i+j]=(x+y)%MOD;a[i+j+w]=(x-y+MOD)%MOD;}if(inv){ll d=power(n,MOD-2,MOD);for(auto&x:a)x=x*d%MOD;}}
void ntt(vector<ll>&a,bool inv,ll mod){int n=a.size();for(int i=1,j=0;i<n;i++){int b=n>>1;for(;j&b;b>>=1)j^=b;j^=b;if(i<j)swap(a[i],a[j]);}for(int len=2;len<=n;len*=2){ll wlen=power(3,(mod-1)/len,mod);if(inv)wlen=power(wlen,mod-2,mod);for(int i=0;i<n;i+=len){ll w=1;for(int j=0;j<len/2;j++){ll u=a[i+j],v=a[i+j+len/2]*w%mod;a[i+j]=(u+v)%mod;a[i+j+len/2]=(u-v+mod)%mod;w=w*wlen%mod;}}}if(inv){ll d=power(n,mod-2,mod);for(auto&v:a)v=v*d%mod;}}
vector<ll>conv(vector<ll>a,vector<ll>b,ll mod){int n=1;while(n<(int)(a.size()+b.size()-1))n*=2;a.resize(n);b.resize(n);ntt(a,0,mod);ntt(b,0,mod);for(int i=0;i<n;i++)a[i]=a[i]*b[i]%mod;ntt(a,1,mod);return a;}
struct BIT2{vector<ll>xs;vector<vector<ll>>ys,bit;BIT2(vector<pair<ll,ll>>pts){for(auto[x,y]:pts)xs.push_back(x);sort(xs.begin(),xs.end());xs.erase(unique(xs.begin(),xs.end()),xs.end());ys.resize(xs.size()+1);bit.resize(xs.size()+1);for(auto[x,y]:pts)for(int i=lower_bound(xs.begin(),xs.end(),x)-xs.begin()+1;i<(int)ys.size();i+=i&-i)ys[i].push_back(y);for(int i=1;i<(int)ys.size();i++){sort(ys[i].begin(),ys[i].end());ys[i].erase(unique(ys[i].begin(),ys[i].end()),ys[i].end());bit[i].resize(ys[i].size()+1);}}void add(ll x,ll y,ll w){for(int i=lower_bound(xs.begin(),xs.end(),x)-xs.begin()+1;i<(int)ys.size();i+=i&-i)for(int j=lower_bound(ys[i].begin(),ys[i].end(),y)-ys[i].begin()+1;j<(int)bit[i].size();j+=j&-j)bit[i][j]+=w;}ll pref(ll x,ll y){ll ans=0;for(int i=lower_bound(xs.begin(),xs.end(),x)-xs.begin();i;i-=i&-i)for(int j=lower_bound(ys[i].begin(),ys[i].end(),y)-ys[i].begin();j;j-=j&-j)ans+=bit[i][j];return ans;}};
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
#if TASK>=1 && TASK<=5
 int n;cin>>n;bool bits=TASK<=2||TASK==5;int m=bits?(1<<n):n+1,start=bits?0:1;vector<ll>a(m),b(m),c(m);for(int i=start;i<m;i++)cin>>a[i];for(int i=start;i<m;i++)cin>>b[i];
 if(SLOW){for(int i=start;i<m;i++)for(int j=start;j<m;j++){ll k=0;if(TASK==1)k=MUTANT?(i|j):(i&j);if(TASK==2)k=MUTANT?(i&j):(i^j);if(TASK==3||TASK==4){bool gcdop=(TASK==3)^MUTANT;k=gcdop?gcd(i,j):ll(i)/gcd(i,j)*j;}if(TASK==5){if(!MUTANT&&(i&j))continue;k=i|j;}if(k<m)c[k]=(c[k]+a[i]*b[j])%MOD;}}
 else if(TASK==3||TASK==4){bool gcdop=(TASK==3)^MUTANT;vector<ll>A(m),B(m);if(gcdop){for(int i=1;i<m;i++)for(int j=i;j<m;j+=i){A[i]=(A[i]+a[j])%MOD;B[i]=(B[i]+b[j])%MOD;}for(int i=n;i>=1;i--){c[i]=A[i]*B[i]%MOD;for(int j=2*i;j<m;j+=i)c[i]=(c[i]-c[j]+MOD)%MOD;}}else{for(int i=1;i<m;i++)for(int j=i;j<m;j+=i){A[j]=(A[j]+a[i])%MOD;B[j]=(B[j]+b[i])%MOD;}for(int i=1;i<m;i++)c[i]=A[i]*B[i]%MOD;for(int i=1;i<m;i++)for(int j=2*i;j<m;j+=i)c[j]=(c[j]-c[i]+MOD)%MOD;}}
 else if(TASK==5&&!MUTANT){vector<vector<ll>>A(n+1,vector<ll>(m)),B=A;for(int i=0;i<m;i++){A[__builtin_popcount((unsigned)i)][i]=a[i];B[__builtin_popcount((unsigned)i)][i]=b[i];}for(int k=0;k<=n;k++){zeta(A[k],n,0,0);zeta(B[k],n,0,0);}for(int k=0;k<=n;k++){vector<ll>v(m);for(int j=0;j<=k;j++)for(int i=0;i<m;i++)v[i]=(v[i]+A[j][i]*B[k-j][i])%MOD;zeta(v,n,1,0);for(int i=0;i<m;i++)if(__builtin_popcount((unsigned)i)==k)c[i]=v[i];}}
 else{bool xorop=TASK==2&&!MUTANT;bool andop=(TASK==1&&!MUTANT)||(TASK==2&&MUTANT);if(xorop){fwht(a,0);fwht(b,0);}else{zeta(a,n,0,andop);zeta(b,n,0,andop);}for(int i=0;i<m;i++)c[i]=a[i]*b[i]%MOD;if(xorop)fwht(c,1);else zeta(c,n,1,andop);}
 for(int i=start;i<m;i++)cout<<c[i]<<' ';cout<<'\n';
#elif TASK==6
 int t;cin>>t;while(t--){ll n,m,a,b;cin>>n>>m>>a>>b;if(MUTANT)b+=m-1;ll ans=0;if(SLOW){for(ll i=0;i<n;i++)ans+=(a*i+b)/m;}else{while(true){if(a>=m){ans+=(n-1)*n*(a/m)/2;a%=m;}if(b>=m){ans+=n*(b/m);b%=m;}ll y=a*n+b;if(y<m)break;n=y/m;b=y%m;swap(m,a);}}cout<<ans<<'\n';}
#elif TASK==7
 int t;cin>>t;while(t--){ull a;int k;cin>>a>>k;auto le=[&](ull x){u128 v=1;for(int j=0;j<k;j++){v*=x;if(v>a)return false;}return true;};ull r;if(k==1||a<2)r=a;else if(SLOW){r=0;while(le(r+1))r++;}else{ull l=0,h=(1ULL<<32)+1;while(l+1<h){ull mid=l+(h-l)/2;if(le(mid))l=mid;else h=mid;}r=l;}if(MUTANT){u128 v=1;for(int i=0;i<k;i++)v*=r;if(v<a)r++;}cout<<r<<'\n';}
#elif TASK>=8 && TASK<=10
 int n,q;cin>>n>>q;struct Op{int t;ll a,b,c,d,w;};vector<Op>ops;vector<pair<ll,ll>>pts;
 auto reg=[&](Op z){if(TASK!=10){pts.push_back({z.a,z.b});}else{pts.push_back({z.a,z.b});pts.push_back({z.c+MUTANT,z.b});pts.push_back({z.a,z.d});pts.push_back({z.c+MUTANT,z.d});}};
 for(int i=0;i<n;i++){Op z{};z.t=0;if(TASK==10)cin>>z.a>>z.b>>z.c>>z.d>>z.w;else cin>>z.a>>z.b>>z.w;reg(z);ops.push_back(z);}for(int i=0;i<q;i++){Op z{};if(TASK==8)z.t=1;else cin>>z.t;if(z.t==0){if(TASK==10)cin>>z.a>>z.b>>z.c>>z.d>>z.w;else cin>>z.a>>z.b>>z.w;reg(z);}else{if(TASK==10)cin>>z.a>>z.b;else cin>>z.a>>z.b>>z.c>>z.d;}ops.push_back(z);}
 BIT2 bit(SLOW?vector<pair<ll,ll>>{}:pts);vector<Op>live;
 for(auto z:ops){if(!z.t){if(SLOW)live.push_back(z);else if(TASK!=10)bit.add(z.a,z.b,z.w);else{bit.add(z.a,z.b,z.w);bit.add(z.c+MUTANT,z.b,-z.w);bit.add(z.a,z.d,-z.w);bit.add(z.c+MUTANT,z.d,z.w);}}else{ll ans=0;if(SLOW){for(auto p:live){if(TASK==10){if(p.a<=z.a&&z.a<p.c+MUTANT&&p.b<=z.b&&z.b<p.d)ans+=p.w;}else if(z.a<=p.a&&p.a<z.c+MUTANT&&z.b<=p.b&&p.b<z.d)ans+=p.w;}}else if(TASK==10)ans=bit.pref(z.a+1,z.b+1);else ans=bit.pref(z.c+MUTANT,z.d)-bit.pref(z.a,z.d)-bit.pref(z.c+MUTANT,z.b)+bit.pref(z.a,z.b);cout<<ans<<'\n';}}
#elif TASK==11
 string s;cin>>s;int n=s.size();ll ans=0;if(SLOW){vector<int>sa(n);iota(sa.begin(),sa.end(),0);auto lessSuffix=[&](int a,int b){while(a<n&&b<n&&s[a]==s[b])a++,b++;return b<n&&(a==n||s[a]<s[b]);};sort(sa.begin(),sa.end(),lessSuffix);for(int i=0;i<n;i++){int k=0;if(i)while(sa[i]+k<n&&sa[i-1]+k<n&&s[sa[i]+k]==s[sa[i-1]+k])k++;ans+=MUTANT?(n-sa[i])/2-k/2:n-sa[i]-k;}}
 else{struct S{array<int,26>next;int link=-1,len=0;S(){next.fill(-1);}};vector<S>st(1);int last=0;for(char ch:s){int c=ch-'a',cur=st.size();st.emplace_back();st[cur].len=st[last].len+1;int p=last;while(p!=-1&&st[p].next[c]==-1){st[p].next[c]=cur;p=st[p].link;}if(p==-1)st[cur].link=0;else{int q=st[p].next[c];if(st[p].len+1==st[q].len)st[cur].link=q;else{int clone=st.size();st.push_back(st[q]);st[clone].len=st[p].len+1;while(p!=-1&&st[p].next[c]==q){st[p].next[c]=clone;p=st[p].link;}st[q].link=st[cur].link=clone;}}last=cur;}for(int i=1;i<(int)st.size();i++){int l=st[st[i].link].len,r=st[i].len;ans+=MUTANT?r/2-l/2:r-l;}}
 cout<<ans<<'\n';
#elif TASK==12
 string s,t;cin>>s>>t;int n=s.size(),m=t.size();vector<bool>good(n-m+1,true);if(SLOW){for(int i=0;i<=n-m;i++)for(int j=0;j<m;j++)if(!(s[i+j]==t[j]||t[j]=='*'||(!MUTANT&&s[i+j]=='*'))){good[i]=false;break;}}
 else{reverse(t.begin(),t.end());for(ll mod:{998244353LL,1004535809LL}){vector<ll>tot(n-m+1);for(int d=1;d<=3;d++){vector<ll>a(n),b(m);for(int i=0;i<n;i++){int c=s[i]=='*'?(MUTANT?27:0):s[i]-'a'+1;a[i]=power(c,d,mod);}for(int i=0;i<m;i++){int c=t[i]=='*'?0:t[i]-'a'+1;b[i]=power(c,4-d,mod);}auto z=conv(a,b,mod);for(int i=0;i<=n-m;i++)tot[i]=(tot[i]+(d==2?-2:1)*z[i+m-1]%mod+2*mod)%mod;}for(int i=0;i<=n-m;i++)good[i]=good[i]&&tot[i]==0;}}
 for(bool b:good)cout<<b;cout<<'\n';
#elif TASK==13
 string s;cin>>s;if(MUTANT)for(char&c:s)c='z'-(c-'a');int n=s.size();vector<int>cuts{0};if(SLOW){int r=n;vector<int>rev;while(r){int k=r-1;for(int i=0;i<r-1;i++){int a=i,b=k;while(a<r&&b<r&&s[a]==s[b])a++,b++;if(b<r&&(a==r||s[a]<s[b]))k=i;}rev.push_back(r);r=k;}reverse(rev.begin(),rev.end());cuts.insert(cuts.end(),rev.begin(),rev.end());}
 else{int i=0;while(i<n){int j=i+1,k=i;while(j<n&&s[k]<=s[j]){if(s[k]<s[j])k=i;else k++;j++;}while(i<=k){i+=j-k;cuts.push_back(i);}}}for(int i:cuts)cout<<i<<' ';cout<<'\n';
#endif
}
