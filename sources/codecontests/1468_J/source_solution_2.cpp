#include<bits/stdc++.h>
#define ms(a,b)        memset(a,b,sizeof(a))
#define PI             acos(-1.0)
#define ll             long long int
#define pii            pair< int, int >
#define READ           freopen("in.txt","r",stdin)
#define WRITE          freopen("out.txt","w",stdout)
#define MOD            (ll)(1e9+7)
#define MAX            (ll)(2e5+5)

using namespace std;


int par[MAX];

struct edge{
    int u,v;
    ll w,W;
    edge(){}
    edge(int U,int V,ll WW)
    {
        u=U,v=V,w=WW;
    }
    bool operator<(const edge &a)const
    {
//        if(w==a.w)
//        {
//            if(u==a.u)
//                return v<a.v;
//            return u<a.u;
//        }
        return w<a.w;
    }
};

vector<edge> v;

int find_par(int r)
{
    if(r==par[r])return r;
    return par[r]=find_par(par[r]);
}

ll mst(int n,int k)
{
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++)
    {
        par[i]=i;
    }
    ll ans=0,f=MOD;
    int cnt=0;
    for(int i=0;i<v.size();i++)
    {
        int u = find_par(v[i].u);
        int vv = find_par(v[i].v);
        if(u!=vv && cnt<n-1)
        {
            par[u]=vv;
            cnt++;
            if(v[i].w>0)
            {
                ans+=v[i].w;
            }
            if(cnt==n-1)
            {

                break;
            }
        }
    }
    if(ans==0)
    {
        ll mn=MOD;
        for(int i=0;i<v.size();i++)
            mn=min(mn,abs(v[i].W-k));
        ans=mn;
    }

//    ans+=f;
    return ans;
}

int main()
{
//    READ;
//    WRITE;
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
    int ts;
    cin>>ts;
    while(ts--)
    {
        v.clear();
        ll n,m,k;
        cin>>n>>m>>k;
        for(int i=0;i<m;i++)
        {
            edge e;
            cin>>e.u>>e.v>>e.w;
            e.W=e.w;
            e.w=max(0LL,e.w-k);
            v.push_back(e);
        }
//        for(int i=0;i<m;i++)
//            cerr<<v[i].u<<" "<<v[i].v<<" "<<v[i].w<<"\n";
//        cerr<<"\n\n";
//        sort(v.begin(),v.end());
        ll ans=mst(n,k);
        cout<<ans<<"\n";
    }
    return 0;
}
