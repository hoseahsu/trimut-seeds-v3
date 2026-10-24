#include <bits/stdc++.h>
using namespace std;using ll=long long;
int main(int argc,char**argv){ios::sync_with_stdio(false);cin.tie(nullptr);string kind=argv[1];bool mutant=string(argv[2])=="l3";
 if(kind=="puzzles"){int n,m;cin>>n>>m;vector<int>a(m);for(int&x:a)cin>>x;int ans=mutant?-1:INT_MAX;for(int i=0;i<m;i++)for(int j=0;j<m;j++)if(a[i]<=a[j]){int count=0;for(int k=0;k<m;k++)if(a[i]<=a[k]&&a[k]<=a[j])count++;if(count>=n)ans=mutant?max(ans,a[j]-a[i]):min(ans,a[j]-a[i]);}cout<<ans<<'\n';}
 else if(kind=="football"){int n;cin>>n;vector<string>a(n);for(string&s:a)cin>>s;int best=mutant?INT_MAX:-1;string ans;for(int i=0;i<n;i++){int count=0;for(int j=0;j<n;j++)count+=a[i]==a[j];if(mutant?count<best:count>best){best=count;ans=a[i];}}cout<<ans<<'\n';}
 else if(kind=="average"){int n;cin>>n;vector<pair<ll,ll>>p(n);for(auto&[x,y]:p)cin>>x>>y;vector<int>order(n);iota(order.begin(),order.end(),0);long double total=0,best=1e100L;unsigned long long count=0;do{long double z=0;for(int k=1;k<n;k++){long double x=p[order[k]].first-p[order[k-1]].first,y=p[order[k]].second-p[order[k-1]].second;z+=sqrtl(x*x+y*y);}total+=z;best=min(best,z);count++;}while(next_permutation(order.begin(),order.end()));cout<<fixed<<setprecision(12)<<(mutant?best:total/count)<<'\n';}
 else if(kind=="coins"){ll A,B,C,X;cin>>A>>B>>C>>X;ll ans=0;for(ll a=0;a<=A;a++)for(ll b=0;b<=B;b++)for(ll c=0;c<=C;c++){ll value=500*a+100*b+50*c;ans+=mutant?(value<=X):(value==X);}cout<<ans<<'\n';}
 else return 2;
}
