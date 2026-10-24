#include <bits/stdc++.h>
using namespace std; using ll=long long;
int main(int argc,char**argv){ios::sync_with_stdio(false);cin.tie(nullptr);string kind=argv[1];bool mutant=string(argv[2])=="l3";
 if(kind=="puzzles"){int n,m;cin>>n>>m;vector<int>a(m);for(int &x:a)cin>>x;sort(a.begin(),a.end());int ans=mutant?a.back()-a.front():INT_MAX;if(!mutant)for(int i=n-1;i<m;i++)ans=min(ans,a[i]-a[i-n+1]);cout<<ans<<'\n';}
 else if(kind=="football"){int n;cin>>n;map<string,int>cnt;string s;for(int i=0;i<n;i++){cin>>s;cnt[s]++;}string ans;int best=mutant?INT_MAX:-1;for(auto [s,c]:cnt)if(mutant?c<best:c>best){best=c;ans=s;}cout<<ans<<'\n';}
 else if(kind=="average"){int n;cin>>n;vector<pair<ll,ll>>p(n);for(auto&[x,y]:p)cin>>x>>y;auto dist=[&](int i,int j){long double x=p[i].first-p[j].first,y=p[i].second-p[j].second;return sqrtl(x*x+y*y);};long double ans=0;if(!mutant){for(int i=0;i<n;i++)for(int j=0;j<i;j++)ans+=dist(i,j);ans=ans*2/n;}else{vector<vector<long double>>dp(1<<n,vector<long double>(n,1e100L));for(int i=0;i<n;i++)dp[1<<i][i]=0;for(int mask=1;mask<(1<<n);mask++)for(int u=0;u<n;u++)if(mask>>u&1)for(int v=0;v<n;v++)if(!(mask>>v&1))dp[mask|1<<v][v]=min(dp[mask|1<<v][v],dp[mask][u]+dist(u,v));ans=*min_element(dp.back().begin(),dp.back().end());}cout<<fixed<<setprecision(12)<<ans<<'\n';}
 else if(kind=="coins"){ll A,B,C,X;cin>>A>>B>>C>>X;ll S=X/50,ans=0;for(ll a=0;a<=A&&10*a<=S;a++){ll r=S-10*a;if(!mutant){ll lo=max(0LL,(r-C+1)/2);if(r-C<0)lo=0;ll hi=min(B,r/2);if(lo<=hi)ans+=hi-lo+1;}else{ll hi=min(B,r/2),full=-1;if(r>=C)full=min(hi,(r-C)/2);ans+=(full+1)*(C+1);ll lo=full+1;if(lo<=hi)ans+=(hi-lo+1)*(r+1)-(lo+hi)*(hi-lo+1);}}cout<<ans<<'\n';}
 else return 2;
}
