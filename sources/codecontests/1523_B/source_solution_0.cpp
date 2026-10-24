#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define fi first
//#define se second
typedef long long ll;
const ll INF=1e18*9;
const int N=1e6+15;
const int M=203;
const int mod1=1e9+7;
const int mod=998244353;
const int base=131;
int n,m,k,ans,x,y,mid,sx=-1,sy=-1,mx,mi=INF,aa,cnt=1;
int a[N];
//char b[M][M];
//stack<int>st;
//pair<int,int>P[N];
//int c[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
//int c1[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
//bool vis[N];
//pair<int,int>p[N];
struct node
{
    int x,y,z;
};
map<int,int>mp,mp1;
string s,ss;

vector<node>ve;
//bool ok(int sx){return ((sx%4==0 && sx%100) || (sx%400==0));}
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={-1,0,1,-1,1,-1,0,1};
//bool cmp(int a,int b){return a>b; }
/*inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}*/

void solve()
{
    //cout<<"SF"<<endl;
    int pos=0,f1=0,s1=0,s2=0;ans=0;mx=INF;
    cin>>n;ve.clear();
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int l=1,r=n;
    while(l<=r)
    {
        ve.push_back(node{1,l,r});
        a[l]+=a[r];
        ve.push_back(node{2,l,r});
        a[r]-=a[l];
        ve.push_back(node{1,l,r});
        a[l]+=a[r];
        ve.push_back(node{2,l,r});
        a[r]-=a[l];
        ve.push_back(node{1,l,r});
        a[l]+=a[r];
        ve.push_back(node{2,l,r});
        a[r]-=a[l];
        l++;r--;
    }
    /*for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<endl;*/
    cout<<ve.size()<<endl;
    for(auto i:ve)cout<<i.x<<" "<<i.y<<" "<<i.z<<endl;







}
/*

*/
signed main()
{
    //cout<<__gcd(3333300,20000)<<endl;
    //cout<<(5&1)<<endl;
    //cout<<C(1e8,354)<<endl;
    //init(1e8+1,100019);
    ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
    //int T;for(T=read();T--;)
    int T;for(cin>>T;T--;)
    //while(cin>>n>>k)
    solve();

}
