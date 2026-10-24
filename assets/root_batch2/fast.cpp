#include <bits/stdc++.h>
using namespace std; using ll=long long; const ll MOD=1000000007;
struct BIT{vector<ll>f;BIT(int n):f(n+1){} void add(int x){for(++x;x<(int)f.size();x+=x&-x)f[x]++;}ll sum(int x){ll s=0;for(;x;x-=x&-x)s+=f[x];return s;}};
int main(int argc,char**argv){ios::sync_with_stdio(false);cin.tie(nullptr);string id=argv[1];bool mut=atoi(argv[2]);
if(id=="ocean"||id=="records"||id=="cars"){
 int T=1;if(id=="cars")cin>>T;while(T--){int n;cin>>n;ll hi=LLONG_MIN,lo=LLONG_MAX,second=LLONG_MAX,ans=0;
 for(int i=0;i<n;i++){ll x;cin>>x;if(id=="ocean")ans+=(mut?x>hi:x>=hi);else if(id=="records")ans+=(i>0&&(x>hi||(!mut&&x<lo)));else ans+=(x<=(mut?second:lo));hi=max(hi,x);if(x<lo){second=lo;lo=x;}else second=min(second,x);}cout<<ans<<'\n';}
}else if(id=="zeros"){
 int n;cin>>n;vector<ll>p(n+1);for(int i=1;i<=n;i++){cin>>p[i];p[i]+=p[i-1];}ll ans=0;
 if(!mut){map<ll,ll>f;for(ll x:p){ans+=f[x];f[x]++;}}else{auto v=p;sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());BIT f(v.size());for(ll x:p){int r=lower_bound(v.begin(),v.end(),x)-v.begin();ans+=f.sum(r);f.add(r);}}cout<<ans<<'\n';
}else if(id=="knapsack"){
 int n;ll W;cin>>n>>W;vector<pair<int,ll>>a(n);int V=0;for(auto&[v,w]:a){cin>>v>>w;V+=v;}const ll inf=4e18;vector<array<ll,2>>d(V+1,{inf,inf});d[0][0]=0;for(auto[v,w]:a)for(int s=V;s>=v;s--)for(int z=0;z<2;z++)d[s][z]=min(d[s][z],d[s-v][z^1]+w);int ans=mut?-1:0;for(int s=0;s<=V;s++)if((mut?d[s][1]:min(d[s][0],d[s][1]))<=W)ans=s;cout<<ans<<'\n';
}else if(id=="intersection"){
 int n,m;cin>>n;vector<ll>a(n);for(auto&x:a)cin>>x;cin>>m;vector<ll>b(m),out;for(auto&x:b)cin>>x;int i=0,j=0;while(i<n||j<m){if(i<n&&j<m&&a[i]==b[j]){if(!mut)out.push_back(a[i]);i++;j++;}else if(j==m||(i<n&&a[i]<b[j])){if(mut)out.push_back(a[i]);i++;}else{if(mut)out.push_back(b[j]);j++;}}for(ll x:out)cout<<x<<'\n';
}else if(id=="digits"){
 string n,m;cin>>n>>m;sort(n.begin(),n.end());if(mut)reverse(n.begin(),n.end());else if(n.size()>1&&n[0]=='0'){auto it=find_if(n.begin(),n.end(),[](char c){return c!='0';});if(it!=n.end())iter_swap(n.begin(),it);}cout<<(m==n?"OK":"WRONG_ANSWER")<<'\n';
}else if(id=="counting"){
 int T;cin>>T;while(T--){ll a,b;int q;cin>>a>>b>>q;ll L=lcm(a,b),M=max(a,b);auto f=[&](ll n){return n/L*(L-M)+max(0LL,n%L-M);};while(q--){ll l,r;cin>>l>>r;ll x=f(r+1)-f(l);cout<<(mut?r-l+1-x:x)<<' ';}cout<<'\n';}
}else if(id=="company"){
 int n;ll d;cin>>n>>d;vector<pair<ll,ll>>a(n);for(auto&[x,y]:a)cin>>x>>y;sort(a.begin(),a.end());ll ans=0,s=0;int l=0;for(int r=0;r<n;r++){s+=a[r].second;while(mut?a[r].first-a[l].first>d:a[r].first-a[l].first>=d)s-=a[l++].second;ans=max(ans,s);}cout<<ans<<'\n';
}else if(id=="monk"){
 int T;cin>>T;while(T--){int n;cin>>n;vector<ll>a(n),b(n);for(auto&x:a)cin>>x;for(auto&x:b)cin>>x;int i=0,j=0,ans=0;while(i<n&&j<n){if(mut?b[j]>a[i]:b[j]>=a[i]){ans=max(ans,j-i);j++;}else i++;}cout<<ans<<'\n';}
}else if(id=="flat"){
 int n,k;cin>>n>>k;if(mut)--k;int S=1;while(S<=300000)S*=2;vector<int>tr(2*S);auto query=[&](int l,int r){int res=0;for(l+=S,r+=S;l<r;l/=2,r/=2){if(l&1)res=max(res,tr[l++]);if(r&1)res=max(res,tr[--r]);}return res;};int ans=0;while(n--){int x;cin>>x;int v=1+(k<0?0:query(max(0,x-k),min(300001,x+k+1)));ans=max(ans,v);for(int p=x+S;p;p/=2)tr[p]=max(tr[p],v);}cout<<ans<<'\n';
}else if(id=="seven"){
 ll n;cin>>n;ll ans=0;function<void(ll,int)>f=[&](ll x,int mask){if(x>n)return;if(x&&(mut?__builtin_popcount((unsigned)mask)>=2:mask==7))ans++;for(int j=0;j<3;j++)if(x<=(n-(3+2*j))/10)f(x*10+3+2*j,mask|(1<<j));};f(0,0);cout<<ans<<'\n';
}else if(id=="playlist"){
 int n,k;cin>>n>>k;vector<pair<ll,ll>>a(n);for(auto&[b,t]:a)cin>>t>>b;sort(a.begin(),a.end());if(!mut)reverse(a.begin(),a.end());priority_queue<ll,vector<ll>,greater<ll>>q;ll sum=0,ans=0;for(auto[b,t]:a){ans=max(ans,(sum+t)*b);q.push(t);sum+=t;if((int)q.size()>=k){sum-=q.top();q.pop();}}cout<<ans<<'\n';
}else if(id=="ayoub"){
 int T;cin>>T;auto tri=[](ll x){return x*(x+1)/2;};while(T--){ll n,m;cin>>n>>m;ll z=n-m,g=m+1,q=z/g,r=z%g;cout<<tri(n)-(mut?tri(z):(g-r)*tri(q)+r*tri(q+1))<<'\n';}
}else if(id=="agency"){
 int T;cin>>T;while(T--){int n,k;cin>>n>>k;vector<int>a(n);for(int&x:a)cin>>x;sort(a.begin(),a.end());if(!mut)reverse(a.begin(),a.end());int x=a[k-1],have=count(a.begin(),a.end(),x),need=count(a.begin(),a.begin()+k,x);vector<ll>c(need+1);c[0]=1;for(int i=1;i<=have;i++)for(int j=min(i,need);j>=1;j--)c[j]=(c[j]+c[j-1])%MOD;cout<<c[need]<<'\n';}
}else if(id=="power"){
 ll n;cin>>n;ll mod=mut?100:10,ans=1,b=1378%mod;for(;n;n/=2,b=b*b%mod)if(n&1)ans=ans*b%mod;cout<<ans<<'\n';
}else if(id=="histogram"){
 int n;cin>>n;vector<ll>a(n+1);for(int i=0;i<n;i++)cin>>a[i];vector<int>s;ll ans=0;for(int i=0;i<=n;i++){while(!s.empty()&&a[s.back()]>=a[i]){ll h=a[s.back()];s.pop_back();ll w=i-(s.empty()?-1:s.back())-1;ll side=min(w,h);ans=max(ans,mut?side*side:w*h);}s.push_back(i);}cout<<ans<<'\n';
}else if(id=="elevator"){
 int n;cin>>n;ll ans=0;for(int i=0;i<n;i++){ll x;cin>>x;ans+=4LL*x*(mut?n-1:i);}cout<<ans<<'\n';
}else if(id=="parity"){
 int T;cin>>T;while(T--){string s,a,b;cin>>s;for(char c:s)((c-'0')%2?a:b)+=c;int i=0,j=0;while(i<(int)a.size()||j<(int)b.size()){if(j==(int)b.size()||(i<(int)a.size()&&(mut?a[i]>b[j]:a[i]<b[j])))cout<<a[i++];else cout<<b[j++];}cout<<'\n';}
}else if(id=="tiles"){
 int T;cin>>T;while(T--){int n,m;ll x,y;cin>>n>>m>>x>>y;ll ans=0;while(n--){string s;cin>>s;s+='*';int len=0;for(char c:s){if(c=='.')len++;else{ans+=(len/2)*(mut?max(y,2*x):min(y,2*x))+(len%2)*x;len=0;}}}cout<<ans<<'\n';}
}else if(id=="cypher"){
 int n,k;cin>>n>>k;k+=mut;vector<int>a(n);map<int,int>f;ll ans=0;int l=0;for(int r=0;r<n;r++){cin>>a[r];f[a[r]]++;while(f[a[r]]>=k)f[a[l++]]--;ans+=l;}cout<<ans<<'\n';
}else if(id=="pipeline"){
 ll n,k;cin>>n>>k;ll t=n-1;if(t>k*(k-1)/2){cout<<-1<<'\n';return 0;}ll lo=0,hi=k-1;while(lo<hi){ll mid=mut?(lo+hi+1)/2:(lo+hi)/2;if(mut){if(mid*(mid+1)/2<=t)lo=mid;else hi=mid-1;}else{if(mid*(2*k-mid-1)/2>=t)hi=mid;else lo=mid+1;}}cout<<lo<<'\n';
}else return 2;
}
