#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;
#define ALL(c) begin(c),end(c)
#define RALL(c) rbegin(c),rend(c)
#define ITR(i,b,e) for(auto i=(b);i!=(e);++i)
#define FORE(x,c) for(auto &x:c)
#define REPF(i,a,n) for(int i=a,i##len=(int)(n);i<i##len;++i)
#define REP(i,n) REPF(i,0,n)
#define REPR(i,n) for(int i=(int)(n);i>=0;--i)
#define SZ(c) ((int)c.size())
#define CONTAIN(c,x) (c.find(x)!=end(c))
#define OUTOFRANGE(y,x,h,w) (y<0||x<0||y>=h||x>=w)
#define dump(...)
const int DX[9]={0,1,0,-1,1,1,-1,-1,0},DY[9]={-1,0,1,0,-1,1,1,-1,0};
#define INF (1001001001)
#define INFLL (1001001001001001001ll)
template<class T> ostream& operator << (ostream &os,const vector<T> &v) {
    ITR(i,begin(v),end(v)) os<<*i<<(i==end(v)-1?"":" "); return os; }
template<class T> istream& operator >> (istream &is,vector<T> &v) {
    ITR(i,begin(v),end(v)) is>>*i; return is; }
template<class T> istream& operator >> (istream &is, pair<T,T> &p) {
    is>>p.first>>p.second; return is; }
template<class T> bool chmax(T &a,const T &b) {if(a<b) {a=b;return 1;} return 0;}
template<class T> bool chmin(T &a,const T &b) {if(b<a) {a=b;return 1;} return 0;}
template <class T> using heap = priority_queue<T,vector<T>,greater<T>>;
//------------------------------------------------------------------------------
struct before_main_function {
    before_main_function() {
        #ifdef int
            #undef INF
            #define INF INFLL
            #define stoi stoll
        #endif
        cin.tie(0);ios::sync_with_stdio(false);
        cout<<setprecision(15)<<fixed;
        #define endl "\n"
    }
} before_main_function;
//------------------8<------------------------------------8<--------------------

struct BIT {
    vector<int> dat;
    int n;
    BIT(int n_) {
        n=n_;
        dat=vector<int>(n,0);
    }
    void add(int i,int x) {
        while(i<=n) {
            dat[i]+=x;
            i+=i&-i;
        }
    }
    int sum(int i) {
        int ret=0;
        while(i>0) {
            ret+=dat[i];
            i-=i&-i;
        }
        return ret;
    }
};

bool cmp(pii a, pii b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second > b.second;
}

signed main() {
    int N,C;
    cin>>N>>C;
    vector<pii> a;
    a.reserve(100005);
    map<int,int> sc;
    REP(i,N) {
        sc[i+1]=0;
        a.push_back({0,-(i+1)});
    }
    vector<vector<int>> Q(C,vector<int>(3));
    REP(i,C) {
        cin>>Q[i][0];
        int c=Q[i][0];
        if(c==0) REP(j,2) cin>>Q[i][j+1];
        if(c==1) REP(j,1) cin>>Q[i][j+1];
        
        int t=Q[i][1];
        int p=Q[i][2];
        if(c==0) {
            sc[t]+=p;
            a.push_back({sc[t],-t});
        }
    }
    sort(ALL(a), cmp);
    a.erase(unique(ALL(a)),end(a));
    //reverse(ALL(a));
    sc.clear();

    auto getidx=[&](pii x) {
        return distance(begin(a),lower_bound(ALL(a),x,cmp));
    };
    BIT bit(SZ(a)+1);
    REP(i,N) {
        sc[i+1]=0;
        int idx=getidx({0,-(i+1)});
        bit.add(idx+1,1);
    }
    REP(i,C) {
        int c=Q[i][0];
        if(c==0) {
            int t=Q[i][1];
            int p=Q[i][2];
            int idx1=getidx({sc[t],-t});
            bit.add(idx1+1,-1);
            sc[t]+=p;
            int idx2=getidx({sc[t],-t});
            bit.add(idx2+1,1);
        } else {
            int m=Q[i][1];
            int L=-1,R=SZ(a);
            while(R-L>1) {
                int M=(L+R)/2;
                int s=bit.sum(M+1);
                if(s>=m) {
                    R=M;
                } else {
                    L=M;
                }
            }
            dump(SZ(a),R);
            cout<<a[R].second*(-1)<<" "<<a[R].first<<endl;
        }
    }
    return 0;
}