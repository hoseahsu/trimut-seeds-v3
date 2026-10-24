#include <bits/stdc++.h>
using namespace std;using ll=long long;const ll INF=4e18;
#ifndef TASK
#define TASK 1
#endif
#ifndef MUT
#define MUT 0
#endif
#ifndef SLOW
#define SLOW 0
#endif
struct DSU{vector<int>p,s;DSU(int n):p(n),s(n,1){iota(p.begin(),p.end(),0);}int f(int x){return p[x]==x?x:p[x]=f(p[x]);}void un(int a,int b){a=f(a);b=f(b);if(a==b)return;if(s[a]<s[b])swap(a,b);p[b]=a;s[a]+=s[b];}};
bool containsK(string s,string p){vector<int>pi(p.size());for(int i=1,j=0;i<(int)p.size();i++){while(j&&p[i]!=p[j])j=pi[j-1];if(p[i]==p[j])j++;pi[i]=j;}for(int i=0,j=0;i<(int)s.size();i++){while(j&&s[i]!=p[j])j=pi[j-1];if(s[i]==p[j])j++;if(j==(int)p.size())return true;}return false;}
struct Seg{int n;vector<array<int,20>>v;vector<int>lz;Seg(vector<int>&a):n(a.size()),v(4*n),lz(4*n){build(1,0,n-1,a);}void build(int p,int l,int r,vector<int>&a){if(l==r){for(int b=0;b<20;b++)v[p][b]=(a[l]>>b)&1;return;}int m=(l+r)/2;build(p*2,l,m,a);build(p*2+1,m+1,r,a);pull(p);}void pull(int p){for(int b=0;b<20;b++)v[p][b]=v[p*2][b]+v[p*2+1][b];}void app(int p,int len,int x){for(int b=0;b<20;b++)if(x>>b&1)v[p][b]=len-v[p][b];lz[p]^=x;}void push(int p,int l,int r){if(lz[p]){int m=(l+r)/2;app(p*2,m-l+1,lz[p]);app(p*2+1,r-m,lz[p]);lz[p]=0;}}void upd(int p,int l,int r,int a,int b,int x){if(a<=l&&r<=b){app(p,r-l+1,x);return;}push(p,l,r);int m=(l+r)/2;if(a<=m)upd(p*2,l,m,a,b,x);if(b>m)upd(p*2+1,m+1,r,a,b,x);pull(p);}ll qry(int p,int l,int r,int a,int b){if(a<=l&&r<=b){ll z=0;for(int k=0;k<20;k++)z+=(ll)(MUT?v[p][k]%2:v[p][k])<<k;return z;}push(p,l,r);int m=(l+r)/2;ll x=0,y=0;if(a<=m)x=qry(p*2,l,m,a,b);if(b>m)y=qry(p*2+1,m+1,r,a,b);return MUT?x^y:x+y;}};
ll recursiveFib(int n){return n<2?1:recursiveFib(n-1)+recursiveFib(n-2);}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
#if TASK==1
int n;cin>>n;vector<int>a(n);for(int&x:a)cin>>x;if(SLOW){vector<int>d(n,1);int z=1;for(int i=0;i<n;i++){for(int j=0;j<i;j++)if(MUT?a[j]>=a[i]:a[j]<=a[i])d[i]=max(d[i],d[j]+1);z=max(z,d[i]);}cout<<z;}else{int d[2]={0,0};for(int x:a){if(MUT)x^=1;d[x]=max(d[x],x?d[0]:0)+1;}cout<<max(d[0],d[1]);}
#elif TASK==2
string s,t;cin>>s>>t;bool ok=false;if(SLOW){for(int i=0;i<(int)s.size();i++)if(s.substr(i)+s.substr(0,i)==t)ok=true;if(MUT){reverse(s.begin(),s.end());for(int i=0;i<(int)s.size();i++)if(s.substr(i)+s.substr(0,i)==t)ok=true;}}else{ok=containsK(s+s,t);if(MUT){reverse(s.begin(),s.end());ok|=containsK(s+s,t);}}cout<<(ok?"Yes":"No");
#elif TASK==3
int n;cin>>n;vector<ll>a(n),b(n);for(ll&x:a)cin>>x;for(ll&x:b)cin>>x;ll ans=MUT?INF:-INF;if(SLOW){for(int i=0;i<n;i++){ll z=0;for(int j=0;j<=i;j++)z+=a[j];for(int j=i;j<n;j++)z+=b[j];ans=MUT?min(ans,z):max(ans,z);}}else{ll up=0,down=accumulate(b.begin(),b.end(),0LL);for(int i=0;i<n;i++){up+=a[i];ll z=up+down;ans=MUT?min(ans,z):max(ans,z);down-=b[i];}}cout<<ans;
#elif TASK==4
int t;cin>>t;while(t--){ll L,v,l,r;cin>>L>>v>>l>>r;ll z=0;if(SLOW){for(ll x=1;x<=L;x++)if(x%v==0&&!(MUT?(l<x&&x<r):(l<=x&&x<=r)))z++;}else{ll lo=l+MUT,hi=r-MUT;z=L/v-(lo<=hi?hi/v-(lo-1)/v:0);}cout<<z<<'\n';}
#elif TASK==5
int t;cin>>t;while(t--){int n;cin>>n;vector<int>a(n);for(int&x:a)cin>>x;int z=0;if(SLOW){for(int i=0;i<n;i++){bool found=false;for(int j=i+1;j<n;j++)if(MUT?a[j]<=a[i]:a[j]<a[i])found=true;z+=found;}}else{int mn=INT_MAX;for(int i=n-1;i>=0;i--){z+=(MUT?a[i]>=mn:a[i]>mn);mn=min(mn,a[i]);}}cout<<z<<'\n';}
#elif TASK==6
int q;cin>>q;while(q--){string p,h;cin>>p>>h;bool ok=false;if(MUT){int c[26]={};for(char x:h)c[x-'a']++;ok=true;for(char x:p)if(--c[x-'a']<0)ok=false;}else if(SLOW){sort(p.begin(),p.end());for(int i=0;i+(int)p.size()<=(int)h.size();i++){auto w=h.substr(i,p.size());sort(w.begin(),w.end());if(w==p)ok=true;}}else{array<int,26>a{},b{};for(char x:p)a[x-'a']++;for(int i=0;i<(int)h.size();i++){b[h[i]-'a']++;if(i>=(int)p.size())b[h[i-p.size()]-'a']--;if(i+1>=(int)p.size()&&a==b)ok=true;}}cout<<(ok?"YES":"NO")<<'\n';}
#elif TASK==7
int n;cin>>n;vector<ll>a(n);for(ll&x:a)cin>>x;ll z=0;if(SLOW){vector<ll>d=a;for(int i=0;i<n;i++){for(int j=0;j<i;j++)if(i-j==(MUT?a[j]-a[i]:a[i]-a[j]))d[i]=max(d[i],d[j]+a[i]);z=max(z,d[i]);}}else{map<ll,ll>c;for(int i=0;i<n;i++)z=max(z,c[a[i]+(MUT?i:-i)]+=a[i]);}cout<<z;
#elif TASK==8
int q;cin>>q;while(q--){int n,k;cin>>n>>k;vector<int>a(k);vector<ll>t(k),z(n,MUT?-INF:INF);for(int&x:a){cin>>x;--x;}for(ll&x:t)cin>>x;if(SLOW){for(int i=0;i<n;i++)for(int j=0;j<k;j++)z[i]=MUT?max(z[i],t[j]+abs(a[j]-i)):min(z[i],t[j]+abs(a[j]-i));}else if(MUT){ll lo=-INF,hi=-INF;for(int j=0;j<k;j++)lo=max(lo,t[j]-a[j]),hi=max(hi,t[j]+a[j]);for(int i=0;i<n;i++)z[i]=max(lo+i,hi-i);}else{for(int j=0;j<k;j++)z[a[j]]=t[j];for(int i=1;i<n;i++)z[i]=min(z[i],z[i-1]+1);for(int i=n-2;i>=0;i--)z[i]=min(z[i],z[i+1]+1);}for(ll x:z)cout<<x<<' ';cout<<'\n';}
#elif TASK==9
int n;cin>>n;vector<int>a(n);for(int&x:a)cin>>x;Seg seg(a);int q;cin>>q;while(q--){int t,l,r,x;cin>>t>>l>>r;--l;--r;if(t==2){cin>>x;if(SLOW){for(int i=l;i<=r;i++)a[i]^=x;}else seg.upd(1,0,n-1,l,r,x);}else{ll z=0;if(SLOW){for(int i=l;i<=r;i++)z=MUT?z^a[i]:z+a[i];}else z=seg.qry(1,0,n-1,l,r);cout<<z<<'\n';}}
#elif TASK==10
string s;cin>>s;if(MUT)for(char&c:s)c=c=='('?')':'(';int best=0,cnt=1;if(SLOW){for(int l=0;l<(int)s.size();l++){int b=0;for(int r=l;r<(int)s.size();r++){b+=s[r]=='('?1:-1;if(b<0)break;if(b==0){int len=r-l+1;if(len>best)best=len,cnt=1;else if(len==best)cnt++;}}}}else{vector<int>st{-1};for(int i=0;i<(int)s.size();i++){if(s[i]=='(')st.push_back(i);else{st.pop_back();if(st.empty())st.push_back(i);else{int len=i-st.back();if(len>best)best=len,cnt=1;else if(len==best&&len)cnt++;}}}}cout<<best<<' '<<cnt;
#elif TASK==11
int n;ll k;cin>>n>>k;vector<ll>a(n),b(n);for(ll&x:a)cin>>x;for(ll&x:b)cin>>x;auto good=[&](ll c){ll used=0;for(int i=0;i<n;i++){ll d=max(0LL,c*a[i]-b[i]);if(MUT){if(d>k)return false;}else{used+=d;if(used>k)return false;}}return true;};ll lo=0;if(SLOW){while(good(lo+1))lo++;}else{ll hi=2000000001;while(lo+1<hi){ll mid=(lo+hi)/2;if(good(mid))lo=mid;else hi=mid;}}cout<<lo;
#elif TASK==12
int n;cin>>n;vector<ll>a(n),b(n);for(int i=0;i<n;i++)cin>>a[i]>>b[i];ll z=0;for(int i=n-1;i>=0;i--){if(SLOW){while((a[i]+(MUT?-z:z))%b[i])z++;}else{ll r=((a[i]+(MUT?-z:z))%b[i]+b[i])%b[i];z+=MUT?r:(b[i]-r)%b[i];}}cout<<z;
#elif TASK==13
int t;cin>>t;while(t--){int n,d;cin>>n>>d;vector<ll>a(n);for(ll&x:a)cin>>x;sort(a.begin(),a.end());ll z=0;if(SLOW){vector<ll>dp(n+1);for(int i=1;i<=n;i++){dp[i]=dp[i-1];for(int j=1;j<i;j++)if(MUT?a[i-1]-a[j-1]<=d:a[i-1]-a[j-1]<d)dp[i]=max(dp[i],dp[j-1]+a[i-1]+a[j-1]);}z=dp[n];}else{for(int i=n-1;i>0;i--){if(MUT?a[i]-a[i-1]<=d:a[i]-a[i-1]<d)z+=a[i]+a[i-1],i--;}}cout<<z<<'\n';}
#elif TASK==14
int t;cin>>t;while(t--){int n;ll l,r;cin>>n>>l>>r;vector<ll>a(n);for(ll&x:a)cin>>x;ll z=0;if(SLOW){for(int i=0;i<n;i++)for(int j=0;j<i;j++){ll s=a[i]+a[j];z+=MUT?(l<s&&s<r):(l<=s&&s<=r);}}else{sort(a.begin(),a.end());auto count=[&](ll v){ll z=0;int j=n-1;for(int i=0;i<n;i++){while(j>i&&a[i]+a[j]>v)j--;if(j>i)z+=j-i;}return z;};z=max(0LL,count(r-MUT)-count(l-1+MUT));}cout<<z<<'\n';}
#elif TASK==15
int n,m;cin>>n>>m;vector<int>a(n+2);for(int i=0,l,r;i<m;i++){cin>>l>>r;if(SLOW){for(int j=l;j<=r;j++)a[j]++;}else a[l]++,a[r+1]--;}if(!SLOW)for(int i=1;i<=n;i++)a[i]+=a[i-1];vector<int>f(m+2);for(int i=1;i<=n;i++)f[a[i]]++;if(!MUT)for(int i=m;i>=0;i--)f[i]+=f[i+1];int q;cin>>q;while(q--){int x;cin>>x;int z=0;if(SLOW){for(int i=1;i<=n;i++)z+=MUT?a[i]==x:a[i]>=x;}else if(x<=m)z=f[x];cout<<z<<'\n';}
#elif TASK==16
int n;cin>>n;vector<int>a(n);for(int&x:a)cin>>x;ll z=0;if(SLOW){for(int i=0;i<n;i++){auto it=MUT?min_element(a.begin(),a.end()):max_element(a.begin(),a.end());z+=(i%2?-1:1)*(*it);a.erase(it);}}else{sort(a.begin(),a.end());if(!MUT)reverse(a.begin(),a.end());for(int i=0;i<n;i++)z+=(i%2?-1:1)*a[i];}cout<<z;
#elif TASK==17
int n,m;cin>>n>>m;DSU d(2*n);vector<vector<int>>g(n);for(int i=0,a,b;i<m;i++){cin>>a>>b;g[a].push_back(b);g[b].push_back(a);if(MUT)d.un(a,b+n),d.un(a+n,b);else d.un(a,b);}int q;cin>>q;while(q--){int a,b;cin>>a>>b;bool yes;if(SLOW){vector<int>v(2*n);queue<int>qu;qu.push(a);v[a]=1;while(!qu.empty()){int x=qu.front();qu.pop();for(int y:g[x%n]){int z=MUT?y+(x<n?n:0):y;if(!v[z])v[z]=1,qu.push(z);}}yes=v[b];}else yes=d.f(a)==d.f(b);cout<<(yes?"yes":"no")<<'\n';}
#elif TASK==18
int n,m;cin>>n>>m;vector<int>a(n);for(int&x:a)cin>>x;int pos=count(a.begin(),a.end(),1),neg=n-pos;while(m--){int l,r;cin>>l>>r;int len=r-l+1,p=pos,v=neg;if(SLOW){p=v=0;for(int x:a)if(x==1)p++;else v++;}int need=(len+MUT)/2;cout<<(((len+MUT)%2==0&&need<=p&&len-need<=v)?1:0)<<'\n';}
#elif TASK==19
int n,m,k;cin>>n>>m>>k;vector<ll>a(n+1);for(int i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1];if(SLOW){function<ll(int,int)>f=[&](int at,int left)->ll{if(!left)return 0;if(at+m*left>n+1)return MUT?INF:-INF;ll z=MUT?INF:-INF;for(int i=at;i+m*left<=n+1;i++){ll t=a[i+m-1]-a[i-1]+f(i+m,left-1);z=MUT?min(z,t):max(z,t);}return z;};cout<<f(1,k);}else{vector<ll>pr(n+1),cur(n+1);for(int j=1;j<=k;j++){fill(cur.begin(),cur.end(),MUT?INF:-INF);for(int i=m*j;i<=n;i++){ll take=pr[i-m]+a[i]-a[i-m];cur[i]=MUT?min(cur[i-1],take):max(cur[i-1],take);}swap(pr,cur);}cout<<pr[n];}
#elif TASK==20
int n,q;cin>>n>>q;vector<vector<int>>apps(n+1);vector<int>app,read;set<int>unread;int z=0;while(q--){int type,x;cin>>type>>x;if(type==1){apps[x].push_back(app.size());unread.insert(app.size());app.push_back(x);read.push_back(0);z++;}else if(SLOW){if(type==2){for(int i=0;i<(int)app.size();i++)if(app[i]==x)read[i]=1;}else{int l=MUT?app.size()-x:0,r=MUT?app.size():x;for(int i=l;i<r;i++)read[i]=1;}z=0;for(int v:read)z+=!v;}else if(type==2){for(int i:apps[x])z-=unread.erase(i);apps[x].clear();}else{int l=MUT?app.size()-x:0,r=MUT?app.size():x;auto it=unread.lower_bound(l);while(it!=unread.end()&&*it<r){it=unread.erase(it);z--;}}cout<<z<<'\n';}
#elif TASK==21
int n;cin>>n;vector<int>a(n),bit(n+1);for(int&x:a)cin>>x;int parity=0;for(int i=n-1;i>=0;i--){for(int p=a[i]-1;p;p-=p&-p)parity^=bit[p]&1;for(int p=a[i];p<=n;p+=p&-p)bit[p]++;}int q;cin>>q;while(q--){int l,r;cin>>l>>r;--l;--r;if(SLOW){if(MUT)rotate(a.begin()+l,a.begin()+l+1,a.begin()+r+1);else reverse(a.begin()+l,a.begin()+r+1);parity=0;for(int i=0;i<n;i++)for(int j=0;j<i;j++)parity^=(a[j]>a[i]);}else{ll len=r-l+1;parity^=(MUT?len-1:len*(len-1)/2)&1;}cout<<(parity?"odd":"even")<<'\n';}
#elif TASK==22
int n;cin>>n;vector<ll>a(n);for(ll&x:a){string s;cin>>s;auto p=s.find('.');if(p==string::npos)s+='.',p=s.size()-1;while(s.size()-p-1<9)s+='0';s.erase(p,1);x=stoll(s);}ll ans=0;if(SLOW){for(int i=0;i<n;i++)for(int j=0;j<i;j++)ans+=(__int128)a[i]*a[j]%((__int128)1000000000000000000LL*(MUT?2:1))==0;}else{ll f[20][19]={};for(ll x:a){int u=0,v=0;while(x%2==0&&u<19)x/=2,u++;while(x%5==0&&v<18)x/=5,v++;f[u][v]++;}for(int u=0;u<20;u++)for(int v=0;v<19;v++)for(int x=0;x<20;x++)for(int y=0;y<19;y++)if(u+x>=18+MUT&&v+y>=18)ans+=f[u][v]*(f[x][y]-(u==x&&v==y));ans/=2;}cout<<ans;
#elif TASK==23
int n;cin>>n;n+=MUT;if(SLOW)cout<<recursiveFib(n);else{ll a=1,b=1;for(int i=0;i<n;i++){ll c=a+b;a=b;b=c;}cout<<a;}
#elif TASK==24
int n,q;cin>>n>>q;vector<int>a(n),stamp(n,-1);int epoch=0,base=0,z=0;while(q--){string s;cin>>s;if(s=="CLICK"){int x;cin>>x;--x;if(!SLOW&&stamp[x]!=epoch)a[x]=base,stamp[x]=epoch;a[x]^=1;z+=a[x]?1:-1;}else{if(SLOW)fill(a.begin(),a.end(),MUT);else epoch++,base=MUT;z=MUT?n:0;}if(SLOW)z=accumulate(a.begin(),a.end(),0);cout<<z<<'\n';}
#elif TASK==25
int n;cin>>n;vector<ll>a(2*n);for(ll&x:a)cin>>x;sort(a.begin(),a.end());if(MUT){ll z=0;for(int i=0;i<n-1;i++)z+=a[2*n-1-i]-a[i];cout<<z;}else if(SLOW){ll ans=INF;for(int u=0;u<2*n;u++)for(int v=u+1;v<2*n;v++){vector<ll>b;for(int i=0;i<2*n;i++)if(i!=u&&i!=v)b.push_back(a[i]);ll z=0;for(int i=0;i<(int)b.size();i+=2)z+=b[i+1]-b[i];ans=min(ans,z);}cout<<ans;}else{vector<array<ll,3>>dp(2*n+1);for(auto&v:dp)v.fill(INF);dp[0][0]=0;for(int i=0;i<2*n;i++)for(int s=0;s<=2;s++)if(dp[i][s]<INF){if(s<2)dp[i+1][s+1]=min(dp[i+1][s+1],dp[i][s]);if(i+1<2*n)dp[i+2][s]=min(dp[i+2][s],dp[i][s]+a[i+1]-a[i]);}cout<<dp[2*n][2];}
#elif TASK==26
int n;cin>>n;vector<ll>a(n);for(ll&x:a)cin>>x;if(MUT)cout<<*max_element(a.begin(),a.end());else{ll g=a[0];for(int i=1;i<n;i++){ll b=a[i];if(SLOW){while(g!=b){if(g>b)g-=b;else b-=g;}}else g=gcd(g,b);}cout<<g;}
#elif TASK==27
int t;cin>>t;while(t--){string s;cin>>s;vector<int>p(s.size()+1);for(int i=0;i<(int)s.size();i++)p[i+1]=p[i]^(1<<(s[i]-'a'));int z=0;if(SLOW){vector<int>d(s.size()+1,MUT?-1000000000:1000000000);d[0]=0;for(int i=1;i<=(int)s.size();i++)for(int j=0;j<i;j++)if(p[i]==p[j])d[i]=MUT?max(d[i],d[j]+1):min(d[i],d[j]+1);z=abs(d.back())>=1000000000?-1:d.back();}else if(p.back())z=-1;else if(!MUT)z=1;else{int mask=0;for(char c:s){mask^=1<<(c-'a');if(!mask)z++;}}cout<<z<<'\n';}
#elif TASK==28
int n,x,y;cin>>n>>x>>y;--x;--y;vector<ll>z(n);if(SLOW){vector<vector<int>>d(n,vector<int>(n,n*2));for(int i=0;i<n;i++)d[i][i]=0;for(int i=1;i<n;i++)d[i][i-1]=d[i-1][i]=1;d[x][y]=d[y][x]=1+MUT;for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)z[d[i][j]]++;}else for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)z[min({j-i,abs(i-x)+1+MUT+abs(y-j),abs(i-y)+1+MUT+abs(x-j)})]++;for(int i=1;i<n;i++)cout<<z[i]<<'\n';
#endif
}
