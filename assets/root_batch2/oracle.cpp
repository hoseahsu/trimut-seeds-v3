#include <bits/stdc++.h>
using namespace std;using ll=long long;const ll MOD=1000000007;
int main(int argc,char**argv){ios::sync_with_stdio(false);cin.tie(nullptr);string id=argv[1];bool mut=atoi(argv[2]);
if(id=="ocean"||id=="records"||id=="cars"){
 int T=1;if(id=="cars")cin>>T;while(T--){int n;cin>>n;vector<ll>a(n);for(auto&x:a)cin>>x;ll ans=0;for(int i=0;i<n;i++){int less=0,equal=0,greater=0;for(int j=0;j<i;j++){less+=a[j]<a[i];equal+=a[j]==a[i];greater+=a[j]>a[i];}if(id=="ocean")ans+=(greater==0&&(!mut||equal==0));else if(id=="records")ans+=(i>0&&(less==i||(!mut&&greater==i)));else ans+=(less<=(mut?1:0));}cout<<ans<<'\n';}
}else if(id=="zeros"){
 int n;cin>>n;vector<ll>a(n);for(auto&x:a)cin>>x;ll ans=0;for(int i=0;i<n;i++){ll s=0;for(int j=i;j<n;j++){s+=a[j];ans+=mut?s>0:s==0;}}cout<<ans<<'\n';
}else if(id=="knapsack"){
 int n;ll W;cin>>n>>W;vector<ll>v(n),w(n);for(int i=0;i<n;i++)cin>>v[i]>>w[i];ll ans=mut?-1:0;function<void(int,ll,ll,int)>dfs=[&](int i,ll s,ll wt,int c){if(i==n){if(wt<=W&&(!mut||c%2))ans=max(ans,s);return;}dfs(i+1,s,wt,c);dfs(i+1,s+v[i],wt+w[i],c+1);};dfs(0,0,0,0);cout<<ans<<'\n';
}else if(id=="intersection"){
 int n,m;cin>>n;vector<ll>a(n);for(auto&x:a)cin>>x;cin>>m;vector<ll>b(m),out;for(auto&x:b)cin>>x;for(ll x:a){bool found=false;for(ll y:b)found|=x==y;if(found!=mut)out.push_back(x);}if(mut)for(ll x:b){bool found=false;for(ll y:a)found|=x==y;if(!found)out.push_back(x);}sort(out.begin(),out.end());for(ll x:out)cout<<x<<'\n';
}else if(id=="digits"){
 string a,b;cin>>a>>b;sort(a.begin(),a.end());string best;do{if(a.size()>1&&a[0]=='0')continue;if(best.empty()||(mut?a>best:a<best))best=a;}while(next_permutation(a.begin(),a.end()));cout<<(best==b?"OK":"WRONG_ANSWER")<<'\n';
}else if(id=="counting"){
 int T;cin>>T;while(T--){ll a,b;int q;cin>>a>>b>>q;while(q--){ll l,r,ans=0;cin>>l>>r;for(ll x=l;x<=r;x++)ans+=mut?((x%a)%b)==((x%b)%a):((x%a)%b)!=((x%b)%a);cout<<ans<<' ';}cout<<'\n';}
}else if(id=="company"){
 int n;ll d;cin>>n>>d;vector<pair<ll,ll>>a(n);for(auto&[x,y]:a)cin>>x>>y;ll ans=0;function<void(int,ll,ll,ll)>dfs=[&](int i,ll low,ll high,ll s){if(i==n){if(low==LLONG_MAX||(mut?high-low<=d:high-low<d))ans=max(ans,s);return;}dfs(i+1,low,high,s);dfs(i+1,min(low,a[i].first),max(high,a[i].first),s+a[i].second);};dfs(0,LLONG_MAX,LLONG_MIN,0);cout<<ans<<'\n';
}else if(id=="monk"){
 int T;cin>>T;while(T--){int n;cin>>n;vector<ll>a(n),b(n);for(auto&x:a)cin>>x;for(auto&x:b)cin>>x;int ans=0;for(int i=0;i<n;i++)for(int j=i;j<n;j++)if(mut?b[j]>a[i]:b[j]>=a[i])ans=max(ans,j-i);cout<<ans<<'\n';}
}else if(id=="flat"){
 int n,k;cin>>n>>k;vector<int>a(n),dp(n,1);for(int&x:a)cin>>x;int ans=1;for(int i=0;i<n;i++){for(int j=0;j<i;j++)if(mut?abs(a[i]-a[j])<k:abs(a[i]-a[j])<=k)dp[i]=max(dp[i],dp[j]+1);ans=max(ans,dp[i]);}cout<<ans<<'\n';
}else if(id=="seven"){
 ll n;cin>>n;ll ans=0;for(ll i=1;i<=n;i++){ll x=i;int mask=0;bool ok=true;while(x){int d=x%10;x/=10;if(d==3)mask|=1;else if(d==5)mask|=2;else if(d==7)mask|=4;else ok=false;}ans+=ok&&(mut?__builtin_popcount((unsigned)mask)>=2:mask==7);}cout<<ans<<'\n';
}else if(id=="playlist"){
 int n,k;cin>>n>>k;vector<ll>t(n),b(n);for(int i=0;i<n;i++)cin>>t[i]>>b[i];ll ans=0;function<void(int,int,ll,ll)>dfs=[&](int i,int c,ll sum,ll beauty){if(c>k)return;if(i==n){if(c)ans=max(ans,sum*beauty);return;}dfs(i+1,c,sum,beauty);dfs(i+1,c+1,sum+t[i],mut?max(beauty,b[i]):min(beauty,b[i]));};dfs(0,0,0,mut?0:LLONG_MAX);cout<<ans<<'\n';
}else if(id=="ayoub"){
 int T;cin>>T;while(T--){int n,m;cin>>n>>m;vector<int>a(n);ll ans=mut?LLONG_MAX:0;function<void(int,int)>dfs=[&](int i,int left){if(left<0||left>n-i)return;if(i==n){ll s=0;for(int l=0;l<n;l++){bool one=false;for(int r=l;r<n;r++){one|=a[r];s+=one;}}ans=mut?min(ans,s):max(ans,s);return;}a[i]=0;dfs(i+1,left);a[i]=1;dfs(i+1,left-1);};dfs(0,m);cout<<ans<<'\n';}
}else if(id=="agency"){
 int T;cin>>T;while(T--){int n,k;cin>>n>>k;vector<ll>a(n);for(auto&x:a)cin>>x;ll best=mut?LLONG_MAX:LLONG_MIN,ways=0;function<void(int,int,ll)>dfs=[&](int i,int c,ll sum){if(c>k||c+n-i<k)return;if(i==n){if(mut?sum<best:sum>best){best=sum;ways=1;}else if(sum==best)ways=(ways+1)%MOD;return;}dfs(i+1,c,sum);dfs(i+1,c+1,sum+a[i]);};dfs(0,0,0);cout<<ways<<'\n';}
}else if(id=="power"){
 ll n;cin>>n;ll ans=1;while(n--)ans=ans*1378%(mut?100:10);cout<<ans<<'\n';
}else if(id=="histogram"){
 int n;cin>>n;vector<ll>a(n);for(auto&x:a)cin>>x;ll ans=0;for(int i=0;i<n;i++){ll h=LLONG_MAX;for(int j=i;j<n;j++){h=min(h,a[j]);ll w=j-i+1,s=min(w,h);ans=max(ans,mut?s*s:w*h);}}cout<<ans<<'\n';
}else if(id=="elevator"){
 int n;cin>>n;vector<ll>a(n+1);for(int i=1;i<=n;i++)cin>>a[i];ll ans=mut?0:LLONG_MAX;for(int x=1;x<=n;x++){ll cost=0;for(int i=1;i<=n;i++)cost+=2*a[i]*(abs(x-i)+(i-1)+(x-1));ans=mut?max(ans,cost):min(ans,cost);}cout<<ans<<'\n';
}else if(id=="parity"){
 int T;cin>>T;while(T--){string s;cin>>s;set<string>vis{s};queue<string>q;q.push(s);string best=s;while(!q.empty()){s=q.front();q.pop();best=mut?max(best,s):min(best,s);for(int i=0;i+1<(int)s.size();i++)if((s[i]-s[i+1])%2){swap(s[i],s[i+1]);if(vis.insert(s).second)q.push(s);swap(s[i],s[i+1]);}}cout<<best<<'\n';}
}else if(id=="tiles"){
 int T;cin>>T;while(T--){int n,m;ll x,y;cin>>n>>m>>x>>y;ll sum=0;while(n--){string s;cin>>s;function<ll(int)>f=[&](int p)->ll{if(p==m)return 0;if(s[p]=='*')return f(p+1);ll z=x+f(p+1);if(p+1<m&&s[p+1]=='.'){ll v=y+f(p+2);z=mut?max(z,v):min(z,v);}return z;};sum+=f(0);}cout<<sum<<'\n';}
}else if(id=="cypher"){
 int n,k;cin>>n>>k;vector<int>a(n);for(int&x:a)cin>>x;ll ans=0;for(int i=0;i<n;i++){map<int,int>cnt;int mx=0;for(int j=i;j<n;j++){mx=max(mx,++cnt[a[j]]);ans+=mut?mx>k:mx>=k;}}cout<<ans<<'\n';
}else if(id=="pipeline"){
 ll n;int k;cin>>n>>k;ll ans=mut?-1:LLONG_MAX;function<void(int,ll,int)>dfs=[&](int x,ll sum,int c){if(x==k){if(sum==n-1)ans=mut?max(ans,(ll)c):min(ans,(ll)c);return;}dfs(x+1,sum,c);dfs(x+1,sum+x,c+1);};dfs(1,0,0);cout<<(ans==LLONG_MAX?-1:ans)<<'\n';
}else return 2;
}
