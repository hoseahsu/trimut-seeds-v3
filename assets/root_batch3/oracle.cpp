#include <bits/stdc++.h>
using namespace std;using ll=long long;const ll MOD=1000000007;
int main(int argc,char**argv){ios::sync_with_stdio(false);cin.tie(nullptr);string id=argv[1];bool mut=atoi(argv[2]);
if(id=="powered"){
 int T;cin>>T;while(T--){int n;cin>>n;vector<ll>a(n);for(auto&x:a)cin>>x;ll d=0;for(int i=0;i<n;i++)for(int j=0;j<=i;j++)d=max(d,a[j]+(mut?i-j:0)-a[i]);int t=0;ll cap=0;while(cap<d){cap=2*cap+1;t++;}cout<<t<<'\n';}
}else if(id=="regional"){
 int T;cin>>T;while(T--){int n;cin>>n;vector<int>u(n);for(int&x:u)cin>>x;vector<vector<ll>>g(n+1);for(int x:u){ll v;cin>>v;g[x].push_back(v);}for(int k=1;k<=n;k++){ll ans=0;for(auto a:g){int sz=a.size(),take=sz/k*k;ll best=mut?LLONG_MAX:LLONG_MIN;function<void(int,int,ll)>f=[&](int i,int c,ll s){if(c>take||c+sz-i<take)return;if(i==sz){best=mut?min(best,s):max(best,s);return;}f(i+1,c,s);f(i+1,c+1,s+a[i]);};f(0,0,0);ans+=best;}cout<<ans<<' ';}cout<<'\n';}
}else if(id=="aqua"){
 int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(n),p(n);for(int&x:a)cin>>x;iota(p.begin(),p.end(),0);bool ok=false;do{bool valid=true;for(int i=0;i<n;i++){if((abs(i-p[i])%2)!=mut)valid=false;if(i&&a[p[i-1]]>a[p[i]])valid=false;}if(valid){ok=true;break;}}while(next_permutation(p.begin(),p.end()));cout<<(ok?"YES":"NO")<<'\n';}
}else if(id=="shift"){
 int n;cin>>n;vector<int>a(n);for(int&x:a)cin>>x;int ans=-1;for(int k=0;k<n;k++){bool ok=true;for(int j=1;j<n;j++){int x=a[(j-1-k+n)%n],y=a[(j-k+n)%n];ok&=mut?x>=y:x<=y;}if(ok){ans=k;break;}}cout<<ans<<'\n';
}else if(id=="substrings"){
 string s;cin>>s;int n=s.size();bool ok=false;for(int i=0;i+1<n;i++)for(int j=0;j+1<n;j++)if(abs(i-j)>=2&&s[i]=='A'&&s[i+1]=='B'&&s[j]=='B'&&s[j+1]=='A'&&(!mut||i<j))ok=true;cout<<(ok?"YES":"NO")<<'\n';
}else if(id=="modulo"){
 int n,m;cin>>n>>m;vector<ll>a(n);for(auto&x:a)cin>>x;bool ok=false;function<void(int,ll,int)>f=[&](int i,ll s,int c){if(i==n){if(c&&s%m==0&&(!mut||c%2))ok=true;return;}f(i+1,s,c);f(i+1,s+a[i],c+1);};f(0,0,0);cout<<(ok?"YES":"NO")<<'\n';
}else if(id=="dance"){
 int n,q;cin>>n>>q;vector<int>a(n);iota(a.begin(),a.end(),1);while(q--){int t;cin>>t;if(t==1){int x;cin>>x;x=(x%n+n)%n;vector<int>b(n);for(int i=0;i<n;i++)b[(i+x)%n]=a[i];a.swap(b);}else{for(int i=mut?1:0;i<n;i+=2)swap(a[i],a[(i+1)%n]);}}for(int x:a)cout<<x<<' ';cout<<'\n';
}else if(id=="lara"){
 ll n,m,k;cin>>n>>m>>k;if(mut)swap(n,m);ll row=1,col=1;for(ll i=1;i<=n;i++){row=i;col=1;if(k==0)goto found;k--;}for(ll r=n;r>=1;r--){if((n-r)%2==0){for(ll c=2;c<=m;c++){row=r;col=c;if(k==0)goto found;k--;}}else{for(ll c=m;c>=2;c--){row=r;col=c;if(k==0)goto found;k--;}}}found:if(mut)swap(row,col);cout<<row<<' '<<col<<'\n';
}else if(id=="compositions"){
 int T;cin>>T;while(T--){int n,k;cin>>n>>k;function<ll(int,int)>f=[&](int slots,int sum)->ll{if(slots==0)return sum==0;ll ans=0;for(int x=mut?1:0;x<=sum;x++)ans+=f(slots-1,sum-x);return ans;};cout<<f(n,k)<<'\n';}
}else if(id=="payment"){
 ll n;cin>>n;ll top=1;while(top<n)top*=10;auto digits=[](ll x){int s=0;while(x){s+=x%10;x/=10;}return s;};int ans=INT_MAX;for(ll p=n;p<n+top;p++)ans=min(ans,digits(p)+(mut?2:1)*digits(p-n));cout<<ans<<'\n';
}else if(id=="taxi"){
 int n,m;cin>>n>>m;vector<ll>x(n+m),b,a;for(auto&v:x)cin>>v;for(ll v:x){int t;cin>>t;(t?b:a).push_back(v);}vector<int>c(m);for(ll v:a){int best=0;for(int j=1;j<m;j++)if(abs(v-b[j])<abs(v-b[best])||(mut&&abs(v-b[j])==abs(v-b[best])))best=j;c[best]++;}for(int z:c)cout<<z<<' ';cout<<'\n';
}else if(id=="doctor"){
 int n,m;cin>>n>>m;vector<ll>a(n);for(auto&x:a)cin>>x;vector<pair<ll,ll>>b(m);for(auto&[d,g]:b)cin>>d>>g;for(ll x:a){ll ans=0;for(auto[d,g]:b)if(mut?d<x:d<=x)ans+=g;cout<<ans<<' ';}cout<<'\n';
}else if(id=="epic"){
 int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(n);for(int&x:a)cin>>x;sort(a.begin(),a.end());map<vector<int>,int>memo;function<int(vector<int>)>f=[&](vector<int>v){if(memo.count(v))return memo[v];int best=v.size();for(int i=0;i<(int)v.size();i++)for(int j=i+1;j<(int)v.size();j++)if(mut?v[i]==v[j]:v[i]!=v[j]){auto w=v;w.erase(w.begin()+j);w.erase(w.begin()+i);best=min(best,f(w));}return memo[v]=best;};cout<<f(a)<<'\n';}
}else if(id=="pocket"){
 int n,m;cin>>n>>m;vector<string>a(n);for(auto&s:a)cin>>s;if(mut){int ans=0;for(int i=0;i<n;i++){bool seen=false;for(int j=0;j<i;j++)seen|=a[i]==a[j];ans+=!seen;}cout<<ans<<'\n';}else{vector<vector<char>>v(m);for(int j=0;j<m;j++){set<char>cs;for(auto&s:a)cs.insert(s[j]);v[j]=vector<char>(cs.begin(),cs.end());}ll ans=0;function<void(int)>f=[&](int j){if(j==m){ans=(ans+1)%MOD;return;}for(char c:v[j]){(void)c;f(j+1);}};f(0);cout<<ans<<'\n';}
}else if(id=="languages"){
 int n,m;cin>>n>>m;vector<vector<int>>a(n);int edges=0;for(auto&v:a){int k;cin>>k;v.resize(k);for(int&x:v)cin>>x;edges+=k;}if(mut){int ans=n;for(int x=1;x<=m;x++){int missing=0;for(auto&v:a)missing+=find(v.begin(),v.end(),x)==v.end();ans=min(ans,missing);}cout<<ans<<'\n';}else{vector<vector<int>>g(n);for(int i=0;i<n;i++)for(int j=0;j<i;j++){bool common=false;for(int x:a[i])for(int y:a[j])common|=x==y;if(common){g[i].push_back(j);g[j].push_back(i);}}vector<int>vis(n);int comps=0;for(int i=0;i<n;i++)if(!vis[i]){comps++;queue<int>q;q.push(i);vis[i]=1;while(!q.empty()){int v=q.front();q.pop();for(int w:g[v])if(!vis[w]){vis[w]=1;q.push(w);}}}cout<<(edges?comps-1:n)<<'\n';}
}else if(id=="tavas"){
 ll A,B;int q;cin>>A>>B>>q;while(q--){ll l,t,m;cin>>l>>t>>m;ll sum=0,ans=-1;for(ll r=l;;r++){ll h=A+(r-1)*B;sum+=h;if(h>t||(mut?sum>=t*m:sum>t*m))break;ans=r;}cout<<ans<<'\n';}
}else if(id=="cellular"){
 int n,m;cin>>n>>m;vector<ll>a(n),b(m);for(auto&x:a)cin>>x;for(auto&x:b)cin>>x;ll ans=0;for(ll x:a){ll d=mut?0:LLONG_MAX;for(ll y:b)d=mut?max(d,abs(x-y)):min(d,abs(x-y));ans=max(ans,d);}cout<<ans<<'\n';
}else if(id=="magical"){
 int n;cin>>n;vector<ll>a(n);for(auto&x:a)cin>>x;ll ans=0;for(int i=0;i<n;i++){ll lo=LLONG_MAX,hi=LLONG_MIN;for(int j=i;j<n;j++){lo=min(lo,a[j]);hi=max(hi,a[j]);ans+=hi-lo<=(mut?1:0);}}cout<<ans<<'\n';
}else if(id=="pairs"){
 int n;cin>>n;vector<ll>a(n);for(auto&x:a)cin>>x;ll ans=0;for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)ans=(ans+(mut?abs(a[i]-a[j]):a[i]*a[j]))%MOD;cout<<ans<<'\n';
}else if(id=="bricks"){
 int n;cin>>n;vector<int>a(n),v;for(int&x:a)cin>>x;int best=0;function<void(int)>f=[&](int i){if(i==n){bool ok=true;for(int j=0;j<(int)v.size();j++)ok&=v[j]==(mut?(int)v.size()-j:j+1);if(ok)best=max(best,(int)v.size());return;}f(i+1);v.push_back(a[i]);f(i+1);v.pop_back();};f(0);cout<<(best?n-best:-1)<<'\n';
}else if(id=="transform"){
 string a,b;cin>>a>>b;bool ok=true;for(int i=0;i<(int)a.size();i++)for(int j=0;j<i;j++){bool same=a[i]==a[j],other=b[i]==b[j];ok&=mut?(!same||other):(same==other);}cout<<(ok?"Yes":"No")<<'\n';
}else if(id=="concat"){
 int n,l;cin>>n>>l;vector<string>a(n);for(auto&s:a)cin>>s;sort(a.begin(),a.end());string best;do{string s;for(auto&t:a)s+=t;if(best.empty()||(mut?s>best:s<best))best=s;}while(next_permutation(a.begin(),a.end()));cout<<best<<'\n';
}else if(id=="consecutive"){
 ll n;while(cin>>n&&n){ll ans=0;for(ll start=mut?0:1;start<=n;start++){ll sum=0;for(ll end=start;sum<=n;end++){sum+=end;if(sum==n&&end>start)ans++;}}cout<<ans<<'\n';}
}else if(id=="hotel"){
 int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(n),d(n);for(int&x:a)cin>>x;for(int&x:d)cin>>x;int ans=0;for(int t:a){int c=0;for(int i=0;i<n;i++)c+=a[i]<=t&&(mut?t<=d[i]:t<d[i]);ans=max(ans,c);}cout<<ans<<'\n';}
}else if(id=="equation"){
 int T;cin>>T;while(T--){ll a;cin>>a;ll ans=0;for(ll x=0;x<=a;x++)ans+=a-(a^x)-x==0&&(!mut||x%2==0);cout<<ans<<'\n';}
}else return 2;
}
