#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void selection_sort_task(){
 int n;cin>>n;vector<ll>a(n);for(auto&x:a)cin>>x;int swaps=0;
 if(SLOW){for(int i=0;i<n;i++){int b=i;for(int j=i;j<n;j++)if(MUT?a[j]>a[b]:a[j]<a[b])b=j;if(i!=b){swap(a[i],a[b]);swaps++;}}}
 else{
  using P=pair<ll,int>;int z=1;while(z<n)z*=2;
  auto best=[](P a,P b){if(a.second<0)return b;if(b.second<0)return a;if(a.first!=b.first)return (MUT?a.first>b.first:a.first<b.first)?a:b;return a.second<b.second?a:b;};
  vector<P>t(2*z,{0,-1});for(int i=0;i<n;i++)t[z+i]={a[i],i};for(int i=z-1;i;i--)t[i]=best(t[2*i],t[2*i+1]);
  auto setval=[&](int i,ll v){int j=z+i;t[j]={v,i};for(j/=2;j;j/=2)t[j]=best(t[2*j],t[2*j+1]);};
  for(int i=0;i<n;i++){P ans={0,-1};for(int l=z+i,r=z+n;l<r;l/=2,r/=2){if(l&1)ans=best(ans,t[l++]);if(r&1)ans=best(ans,t[--r]);}int b=ans.second;if(i!=b){swap(a[i],a[b]);swaps++;setval(i,a[i]);setval(b,a[b]);}}
 }
 for(int i=0;i<n;i++)cout<<(i?" ":"")<<a[i];cout<<'\n'<<swaps<<'\n';
}

void walk_task(){int t;cin>>t;while(t--){int n;cin>>n;vector<ll>a(n);for(auto&v:a)cin>>v;ll ans=0,d=MUT?2:1;if(SLOW){for(ans=1;;ans++){bool ok=true;for(int i=0;i<n;i++)if(ans-d*i<a[i]){ok=false;break;}if(ok)break;}}else for(int i=0;i<n;i++)ans=max(ans,a[i]+d*i);cout<<ans<<'\n';}}

void reverse_task(){int n;string s;cin>>n>>s;if(SLOW){for(int l=0;l<n;l++)for(int r=l+1;r<n;r++){string t=s;reverse(t.begin()+l,t.begin()+r+1);if(MUT?t>s:t<s){cout<<"YES\n"<<l+1<<' '<<r+1<<'\n';return;}}}else for(int i=0;i+1<n;i++)if(MUT?s[i]<s[i+1]:s[i]>s[i+1]){cout<<"YES\n"<<i+1<<' '<<i+2<<'\n';return;}cout<<"NO\n";}

void helpful_task(){string s;cin>>s;vector<int>a;for(char c:s)if(c!='+')a.push_back(c-'0');if(SLOW){for(int i=0;i<(int)a.size();i++)for(int j=0;j+1<(int)a.size()-i;j++)if(MUT?a[j]<a[j+1]:a[j]>a[j+1])swap(a[j],a[j+1]);}else{int c[4]={};for(int x:a)c[x]++;a.clear();for(int t=1;t<=3;t++){int x=MUT?4-t:t;for(int j=0;j<c[x];j++)a.push_back(x);}}for(int i=0;i<(int)a.size();i++)cout<<(i?"+":"")<<a[i];cout<<'\n';}

void apples_task(){int n;cin>>n;vector<int>a(n);int total=0,ones=0,twos=0;for(int&v:a){cin>>v;v/=100;total+=v;ones+=v==1;twos+=v==2;}bool ok=false;if(SLOW){if(total%2==0){vector<unsigned char>d(total+1);d[0]=1;for(int x:a)for(int j=total;j>=x;j--)d[j]|=d[j-x];ok=d[total/2];}}else if(MUT)ok=ones%2==0&&twos%2==0;else ok=ones%2==0&&(ones>0||twos%2==0);cout<<(ok?"YES":"NO")<<'\n';}

struct BIT{int n;vector<ll>t;BIT(int n):n(n),t(n+1){}void add(int i,ll x){for(;i<=n;i+=i&-i)t[i]+=x;}ll sum(int i){ll v=0;for(;i;i-=i&-i)v+=t[i];return v;}};
void books_task(){int n,m;cin>>n>>m;vector<ll>w(n);for(auto&v:w)cin>>v;vector<int>b(m),order,seen(n);for(int&v:b){cin>>v;--v;if(!seen[v]){seen[v]=1;order.push_back(v);}}if(MUT)reverse(order.begin(),order.end());vector<int>unused;for(int i=0;i<n;i++)if(!seen[i])unused.push_back(i);if(MUT)order.insert(order.begin(),unused.begin(),unused.end());else order.insert(order.end(),unused.begin(),unused.end());ll ans=0;if(SLOW){for(int x:b){int p=0;while(order[p]!=x)ans+=w[order[p++]];order.erase(order.begin()+p);order.insert(order.begin(),x);}}else{BIT bit(n+m+2);vector<int>pos(n);for(int i=0;i<n;i++){pos[order[i]]=m+1+i;bit.add(pos[order[i]],w[order[i]]);}int next=m;for(int x:b){ans+=bit.sum(pos[x]-1);bit.add(pos[x],-w[x]);pos[x]=next--;bit.add(pos[x],w[x]);}}cout<<ans<<'\n';}

void chat_task(){string s;set<string>active;ll ans=0;while(getline(cin,s)){if(s.empty())continue;if(s[0]=='+')active.insert(s.substr(1));else if(s[0]=='-')active.erase(s.substr(1));else{int p=s.find(':');string sender=s.substr(0,p);ll len=s.size()-p-1;if(SLOW){for(const auto&person:active)if(!MUT||person!=sender)ans+=len;}else ans+=len*(active.size()-(MUT&&active.count(sender)?1:0));}}cout<<ans<<'\n';}

void robots_task(){int n;ll k;cin>>n>>k;vector<ll>a(n);for(auto&v:a)cin>>v;if(SLOW){for(int round=1;round<=n;round++)for(int j=0;j<round;j++){if(--k==0){cout<<a[MUT?round-1-j:j]<<'\n';return;}}}else{ll l=1,r=n;while(l<r){ll mid=(l+r)/2;if(mid*(mid+1)/2>=k)r=mid;else l=mid+1;}ll j=k-l*(l-1)/2-1;cout<<a[MUT?l-1-j:j]<<'\n';}}

void swaps_task(){int n,m;cin>>n>>m;vector<int>a(n),p(n),sz(n,1);for(int&x:a)cin>>x;iota(p.begin(),p.end(),0);vector<vector<int>>g(n);function<int(int)>find=[&](int x){while(p[x]!=x)x=p[x]=p[p[x]];return x;};while(m--){int u,v;cin>>u>>v;--u;--v;g[u].push_back(v);g[v].push_back(u);int x=find(u),y=find(v);if(x!=y){if(sz[x]<sz[y])swap(x,y);p[y]=x;sz[x]+=sz[y];}}if(SLOW){vector<int>seen(n),q;for(int i=0;i<n;i++){int best=i;q.clear();q.push_back(i);seen[i]=i+1;for(int k=0;k<(int)q.size();k++){int u=q[k];if(u>=i&&(MUT?a[u]<a[best]:a[u]>a[best]))best=u;for(int v:g[u])if(seen[v]!=i+1){seen[v]=i+1;q.push_back(v);}}swap(a[i],a[best]);}}else{vector<vector<int>>inds(n);for(int i=0;i<n;i++)inds[find(i)].push_back(i);for(auto&v:inds){vector<int>vals;for(int i:v)vals.push_back(a[i]);sort(vals.begin(),vals.end());if(!MUT)reverse(vals.begin(),vals.end());for(int j=0;j<(int)v.size();j++)a[v[j]]=vals[j];}}for(int i=0;i<n;i++)cout<<(i?" ":"")<<a[i];cout<<'\n';}

void twogram_task(){int n;string s;cin>>n>>s;string ans;int best=MUT?INT_MAX:-1;if(SLOW){for(int i=0;i+1<n;i++){int c=0;for(int j=0;j+1<n;j++)c+=s[i]==s[j]&&s[i+1]==s[j+1];if(MUT?c<best:c>best){best=c;ans=s.substr(i,2);}}}else{map<string,int>freq;for(int i=0;i+1<n;i++)freq[s.substr(i,2)]++;for(auto [x,c]:freq)if(MUT?c<best:c>best){best=c;ans=x;}}cout<<ans<<'\n';}

void ranks_task(){int n;cin>>n;vector<int>a(n);for(int&v:a)cin>>v;vector<int>freq(1002),pref(1002);if(!SLOW){for(int x:a)freq[x]++;for(int i=1;i<=1000;i++)pref[i]=pref[i-1]+freq[i];}for(int i=0;i<n;i++){int rank=1;if(SLOW){for(int x:a)rank+=MUT?x<a[i]:x>a[i];}else rank+=MUT?pref[a[i]-1]:n-pref[a[i]];cout<<(i?" ":"")<<rank;}cout<<'\n';}

void sums_task(){int n,q;cin>>n>>q;vector<ll>a(n+1),p(n+1);for(int i=1;i<=n;i++){cin>>a[i];p[i]=p[i-1]+a[i];}while(q--){int l,r;cin>>l>>r;ll sum=0,diff=0;if(SLOW){for(int i=l;i<=r;i++)sum+=a[i];diff=MUT?a[l]:a[r];if(MUT)for(int i=l+1;i<=r;i++)diff-=a[i];else for(int i=r-1;i>=l;i--)diff-=a[i];}else{sum=p[r]-p[l-1];diff=2*(MUT?a[l]:a[r])-sum;}cout<<sum<<' '<<diff<<'\n';}}

void digits_task(){string s;int k;cin>>s>>k;ll ans=0;if(SLOW){string v="1";while(v.size()<s.size()||(v.size()==s.size()&&v<=s)){int nz=0;for(char c:v)nz+=c!='0';ans+=MUT?nz<=k:nz==k;int i=v.size()-1;while(i>=0&&v[i]=='9')v[i--]='0';if(i<0)v='1'+v;else v[i]++;}}else{ll dp[4][2]={};dp[0][1]=1;for(char c:s){ll nd[4][2]={};for(int count=0;count<=k;count++)for(int tight=0;tight<2;tight++)for(int d=0;d<=(tight?c-'0':9);d++){int cc=count+(d!=0);if(cc<=k)nd[cc][tight&&d==c-'0']+=dp[count][tight];}memcpy(dp,nd,sizeof dp);}if(MUT){for(int count=1;count<=k;count++)ans+=dp[count][0]+dp[count][1];}else ans=dp[k][0]+dp[k][1];}cout<<ans<<'\n';}

void buffet_task(){int n;cin>>n;vector<int>a(n);vector<ll>b(n),c(n-1);for(int&x:a){cin>>x;--x;}for(auto&x:b)cin>>x;for(auto&x:c)cin>>x;ll ans=accumulate(b.begin(),b.end(),0LL);if(SLOW){for(int dish=0;dish+1<n;dish++){int x=-1,y=-1;for(int i=0;i<n;i++){if(a[i]==dish)x=i;if(a[i]==dish+1)y=i;}if(MUT?x==y+1:y==x+1)ans+=c[dish];}}else for(int i=0;i+1<n;i++){if(MUT?a[i]==a[i+1]+1:a[i+1]==a[i]+1)ans+=c[min(a[i],a[i+1])];}cout<<ans<<'\n';}

void newworld_task(){int t;cin>>t;while(t--){int n,k;cin>>n>>k;vector<ll>x(n);for(auto&v:x)cin>>v;ll ans=0;if(SLOW){const ll inf=1LL<<60;vector<ll>dp(n,inf),nd(n);dp[0]=0;for(int step=1;step<=k;step++){fill(nd.begin(),nd.end(),inf);for(int j=step;j<n;j++)for(int i=step-1;i<j;i++)if(dp[i]!=inf)nd[j]=min(nd[j],max(dp[i],x[j]-x[i]));dp.swap(nd);}ans=dp[n-1];}else if(MUT){auto good=[&](ll d){ll last=x[0];int cnt=0;for(int i=1;i+1<n;i++)if(x[i]-last>=d&&x.back()-x[i]>=d){cnt++;last=x[i];}if(x.back()-last>=d)cnt++;return cnt>=k;};ll l=1,r=x.back()-x[0];while(l<r){ll mid=(l+r+1)/2;if(good(mid))l=mid;else r=mid-1;}ans=l;}else{auto good=[&](ll d){int cnt=0,i=0;while(i+1<n){int j=i;while(j+1<n&&x[j+1]-x[i]<=d)j++;if(j==i)return false;i=j;cnt++;}return cnt<=k;};ll l=1,r=x.back()-x[0];while(l<r){ll mid=(l+r)/2;if(good(mid))r=mid;else l=mid+1;}ans=l;}cout<<ans<<'\n';}}

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);switch(TASK){case 1:selection_sort_task();break;case 2:walk_task();break;case 3:reverse_task();break;case 4:helpful_task();break;case 5:apples_task();break;case 6:books_task();break;case 7:chat_task();break;case 8:robots_task();break;case 9:swaps_task();break;case 10:twogram_task();break;case 11:ranks_task();break;case 12:sums_task();break;case 13:digits_task();break;case 14:buffet_task();break;case 15:newworld_task();break;}}
