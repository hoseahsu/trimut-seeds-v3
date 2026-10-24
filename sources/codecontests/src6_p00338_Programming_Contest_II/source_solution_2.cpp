#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

struct BIT{
    int N;
    vint dat;
    void init(int n){
        N=n;
        dat.resize(N+1);
    }
    void add(int k,int x){
        for(k++;k<=N;k+=k&-k)dat[k]+=x;
    }
    int sum(int k){
        int ret=0;
        for(k++;k;k-=k&-k)ret+=dat[k];
        return ret;
    }
};

int N,C;
int type[100000],t[100000],p[100000];

int sum[100000];

signed main(){
    cin>>N>>C;
    rep(i,C){
        cin>>type[i]>>t[i];
        if(type[i]==0)cin>>p[i],t[i]--;
    }

    vector<pint>vec;
    rep(i,N)vec.pb(pint(0,-i));

    rep(i,C){
        if(type[i]==0){
            sum[t[i]]+=p[i];
            vec.pb(pint(sum[t[i]],-t[i]));
        }
    }

    sort(all(vec));
    vec.erase(unique(all(vec)),vec.end());

    BIT bit;bit.init(vec.size()+114);
    rep(i,N){
        bit.add(i,1);
    }

    memset(sum,0,sizeof(sum));
    rep(i,C){
        if(type[i]==0){
            int l=lower_bound(all(vec),pint(sum[t[i]],-t[i]))-vec.begin();
            bit.add(l,-1);
            sum[t[i]]+=p[i];
            l=lower_bound(all(vec),pint(sum[t[i]],-t[i]))-vec.begin();
            bit.add(l,1);
        }
        else{
            int lb=-1,ub=vec.size();
            t[i]=N-t[i]+1;
            while(ub-lb>1){
                int mid=(ub+lb)/2;
                if(bit.sum(mid)<t[i])lb=mid;
                else ub=mid;
            }
            cout<<-vec[ub].se+1<<" "<<vec[ub].fi<<endl;
        }
    }
    return 0;
}