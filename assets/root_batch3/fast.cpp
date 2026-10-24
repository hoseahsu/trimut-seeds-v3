#include <bits/stdc++.h>
using namespace std;using ll=long long;const ll MOD=1000000007;
struct DSU{vector<int>p;DSU(int n):p(n){iota(p.begin(),p.end(),0);}int f(int x){return p[x]==x?x:p[x]=f(p[x]);}void join(int x,int y){p[f(x)]=f(y);}};
int main(int argc,char**argv){ios::sync_with_stdio(false);cin.tie(nullptr);string id=argv[1];bool mut=atoi(argv[2]);
if(id=="powered"){
 int T;cin>>T;while(T--){int n;cin>>n;ll best=LLONG_MIN,d=0;for(int i=0;i<n;i++){ll x;cin>>x;x-=mut?i:0;best=max(best,x);d=max(d,best-x);}int bits=0;for(;d;d/=2)bits++;cout<<bits<<'\n';}
}else if(id=="regional"){
 int T;cin>>T;while(T--){int n;cin>>n;vector<int>u(n);for(int&x:u)cin>>x;vector<vector<ll>>g(n+1);for(int x:u){ll v;cin>>v;g[x].push_back(v);}vector<ll>ans(n+1);for(auto a:g){sort(a.begin(),a.end());if(!mut)reverse(a.begin(),a.end());int s=a.size();vector<ll>p(s+1);for(int i=0;i<s;i++)p[i+1]=p[i]+a[i];for(int k=1;k<=s;k++)ans[k]+=p[s/k*k];}for(int k=1;k<=n;k++)cout<<ans[k]<<' ';cout<<'\n';}
}else if(id=="aqua"){
 int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(n),b;for(int&x:a)cin>>x;b=a;sort(b.begin(),b.end());map<pair<int,int>,int>c;for(int i=0;i<n;i++){c[{a[i],i%2}]++;c[{b[i],(i%2)^mut}]--;}bool ok=true;for(auto [k,v]:c)ok&=v==0;cout<<(ok?"YES":"NO")<<'\n';}
}else if(id=="shift"){
 int n;cin>>n;vector<int>a(n);for(int&x:a)cin>>x;int bad=0,cut=-1;for(int i=0;i<n;i++)if(mut?a[i]<a[(i+1)%n]:a[i]>a[(i+1)%n]){bad++;cut=i;}cout<<(bad>1?-1:bad==0?0:(n-cut-1)%n)<<'\n';
}else if(id=="substrings"){
 string s;cin>>s;auto findpair=[&](string a,string b){auto p=s.find(a);return p!=string::npos&&s.find(b,p+2)!=string::npos;};cout<<((findpair("AB","BA")||(!mut&&findpair("BA","AB")))?"YES":"NO")<<'\n';
}else if(id=="modulo"){
 int n,m;cin>>n>>m;bitset<1000> even,odd,mask;even[0]=1;for(int r=0;r<m;r++)mask[r]=1;bool nonempty=false;
 auto rotate=[&](bitset<1000> a,int v){return ((a<<v)|(a>>(m-v)))&mask;};
 while(n--){ll x;cin>>x;int v=x%m;auto from_even=rotate(even,v),from_odd=rotate(odd,v);nonempty=nonempty||from_even[0]||from_odd[0];even|=from_odd;odd|=from_even;}
 cout<<((mut?odd[0]:nonempty)?"YES":"NO")<<'\n';
}else if(id=="dance"){
 int n,q;cin>>n>>q;ll off[2]={0,0};while(q--){int type;cin>>type;if(type==1){ll x;cin>>x;for(ll&v:off)v=(v+x+n)%n;}else{for(int p=0;p<2;p++){int parity=(p+off[p])%2;off[p]=(off[p]+(parity==(mut?1:0)?1:-1)+n)%n;}}}vector<int>a(n);for(int i=0;i<n;i++)a[(i+off[i%2])%n]=i+1;for(int x:a)cout<<x<<' ';cout<<'\n';
}else if(id=="lara"){
 ll n,m,k;cin>>n>>m>>k;if(mut)swap(n,m);ll row,col;if(k<n){row=k+1;col=1;}else{ll z=k-n,band=z/(m-1),offset=z%(m-1);row=n-band;col=band%2?m-offset:offset+2;}if(mut)swap(row,col);cout<<row<<' '<<col<<'\n';
}else if(id=="compositions"){
 int T;cin>>T;auto C=[](int n,int k){if(k<0||k>n)return 0LL;k=min(k,n-k);ll z=1;for(int i=1;i<=k;i++)z=z*(n-k+i)/i;return z;};while(T--){int n,k;cin>>n>>k;cout<<(mut?C(k-1,n-1):C(n+k-1,n-1))<<'\n';}
}else if(id=="payment"){
 string s;cin>>s;int dp[2]={0,100000000};for(int i=(int)s.size()-1;i>=0;i--){int nd[2]={100000000,100000000};for(int c=0;c<2;c++){int d=s[i]-'0'+c;nd[0]=min(nd[0],dp[c]+d);nd[1]=min(nd[1],dp[c]+(10-d)*(mut?2:1));}copy(nd,nd+2,dp);}cout<<min(dp[0],dp[1]+1)<<'\n';
}else if(id=="taxi"){
 int n,m;cin>>n>>m;vector<ll>x(n+m),taxi,person;for(auto&v:x)cin>>v;for(ll v:x){int t;cin>>t;(t?taxi:person).push_back(v);}vector<int>cnt(m);for(ll v:person){int j=lower_bound(taxi.begin(),taxi.end(),v)-taxi.begin();if(j==m||(j&&((v-taxi[j-1]<taxi[j]-v)||(!mut&&v-taxi[j-1]==taxi[j]-v))))j--;cnt[j]++;}for(int c:cnt)cout<<c<<' ';cout<<'\n';
}else if(id=="doctor"){
 int n,m;cin>>n>>m;vector<ll>a(n);for(auto&x:a)cin>>x;vector<pair<ll,ll>>b(m);for(auto&[d,g]:b)cin>>d>>g;sort(b.begin(),b.end());vector<ll>d(m),p(m+1);for(int i=0;i<m;i++){d[i]=b[i].first;p[i+1]=p[i]+b[i].second;}for(ll x:a){int k=(mut?lower_bound(d.begin(),d.end(),x):upper_bound(d.begin(),d.end(),x))-d.begin();cout<<p[k]<<' ';}cout<<'\n';
}else if(id=="epic"){
 int T;cin>>T;while(T--){int n;cin>>n;map<int,int>c;for(int i=0;i<n;i++){int x;cin>>x;c[x]++;}int mx=0,odd=0;for(auto[x,v]:c){mx=max(mx,v);odd+=v%2;}cout<<(mut?odd:max(n%2,2*mx-n))<<'\n';}
}else if(id=="pocket"){
 int n,m;cin>>n>>m;vector<string>a(n);for(auto&s:a)cin>>s;ll ans=1;if(mut)ans=set<string>(a.begin(),a.end()).size();else for(int j=0;j<m;j++){set<char>s;for(auto&t:a)s.insert(t[j]);ans=ans*s.size()%MOD;}cout<<ans<<'\n';
}else if(id=="languages"){
 int n,m;cin>>n>>m;DSU uf(n);vector<int>first(m,-1),count(m);bool any=false;for(int i=0;i<n;i++){int k;cin>>k;while(k--){int x;cin>>x;--x;any=true;count[x]++;if(first[x]==-1)first[x]=i;else uf.join(first[x],i);}}int components=0;for(int i=0;i<n;i++)components+=uf.f(i)==i;cout<<(mut?n-*max_element(count.begin(),count.end()):any?components-1:n)<<'\n';
}else if(id=="tavas"){
 ll A,B;int q;cin>>A>>B>>q;while(q--){ll l,t,m;cin>>l>>t>>m;ll first=A+(l-1)*B;if(first>t){cout<<-1<<'\n';continue;}ll lo=l-1,hi=(t-A)/B+1;while(lo<hi){ll r=(lo+hi+1)/2;ll s=(r-l+1)*(2*A+(l+r-2)*B)/2;bool ok=mut?s<t*m:s<=t*m;if(ok)lo=r;else hi=r-1;}cout<<(lo<l?-1:lo)<<'\n';}
}else if(id=="cellular"){
 int n,m;cin>>n>>m;vector<ll>a(n),b(m);for(auto&x:a)cin>>x;for(auto&x:b)cin>>x;ll ans=0;for(ll x:a){ll d;if(mut)d=max(abs(x-b[0]),abs(x-b.back()));else{auto it=lower_bound(b.begin(),b.end(),x);d=LLONG_MAX;if(it!=b.end())d=min(d,abs(x-*it));if(it!=b.begin())d=min(d,abs(x-*prev(it)));}ans=max(ans,d);}cout<<ans<<'\n';
}else if(id=="magical"){
 int n;cin>>n;vector<ll>a(n);deque<int>lo,hi;ll ans=0;int l=0;for(int r=0;r<n;r++){cin>>a[r];while(!lo.empty()&&a[lo.back()]>=a[r])lo.pop_back();while(!hi.empty()&&a[hi.back()]<=a[r])hi.pop_back();lo.push_back(r);hi.push_back(r);while(a[hi.front()]-a[lo.front()]>(mut?1:0)){if(lo.front()==l)lo.pop_front();if(hi.front()==l)hi.pop_front();l++;}ans+=r-l+1;}cout<<ans<<'\n';
}else if(id=="pairs"){
 int n;cin>>n;vector<ll>a(n);for(auto&x:a)cin>>x;if(mut)sort(a.begin(),a.end());ll sum=0,ans=0;for(int i=0;i<n;i++){ans=(ans+(mut?(a[i]*i-sum)%MOD:a[i]*(sum%MOD)%MOD)+MOD)%MOD;sum+=a[i];}cout<<ans<<'\n';
}else if(id=="bricks"){
 int n;cin>>n;int best=0;vector<int>d(n+2);for(int i=0;i<n;i++){int x;cin>>x;if(mut)d[x]=max(d[x],d[x+1]+1);else if(x==best+1)best++;}if(mut)best=d[1];cout<<(best?n-best:-1)<<'\n';
}else if(id=="transform"){
 string a,b;cin>>a>>b;vector<int>f(26,-1),g(26,-1);bool ok=true;for(int i=0;i<(int)a.size();i++){int x=a[i]-'a',y=b[i]-'a';if(f[x]!=-1&&f[x]!=y)ok=false;if(!mut&&g[y]!=-1&&g[y]!=x)ok=false;f[x]=y;g[y]=x;}cout<<(ok?"Yes":"No")<<'\n';
}else if(id=="concat"){
 int n,l;cin>>n>>l;vector<string>a(n);for(auto&s:a)cin>>s;sort(a.begin(),a.end());if(mut)reverse(a.begin(),a.end());for(auto&s:a)cout<<s;cout<<'\n';
}else if(id=="consecutive"){
 ll n;while(cin>>n&&n){ll ans=0;for(ll len=2;len*(len-1)/2<=n;len++){ll rem=n-len*(len-1)/2;if(rem%len==0&&rem/len>=(mut?0:1))ans++;}cout<<ans<<'\n';}
}else if(id=="hotel"){
 int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(n);for(int&x:a)cin>>x;vector<pair<int,int>>ev;for(int x:a)ev.push_back({x,mut?-1:1});for(int i=0;i<n;i++){int x;cin>>x;ev.push_back({x,mut?1:-1});}sort(ev.begin(),ev.end());int cur=0,ans=0;for(auto[t,v]:ev){cur+=mut?-v:v;ans=max(ans,cur);}cout<<ans<<'\n';}
}else if(id=="equation"){
 int T;cin>>T;while(T--){unsigned long long a;cin>>a;int p=__builtin_popcountll(a)-(mut&&(a&1));cout<<(1ULL<<p)<<'\n';}
}else return 2;
}
