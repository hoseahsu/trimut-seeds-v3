#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define int long long 
signed main(){
    int n,m;
    cin >> n >> m;
    vector<int>a(n);
    rep(i,n) cin >> a[i];
    set<pair<int,pair<int,int> > > st;
    set<pair<int,pair<int,int> >,greater< pair<int,pair<int,int> > >  > st2;
    rep(i,n){
        st.insert(MP(max(i,a[i]),MP(i,a[i])));
        st2.insert(MP(min(i,a[i]),MP(i,a[i])));
    }
    ll ans = 0;
    rep(i,m){
        auto x = *st.begin();
        auto y = *st2.begin();
        //cerr << x.second.first << " " << x.second.second << " " << y.second.first << " " << y.second.second << endl; 
        if(y.second.first > x.second.first&& y.second.second > x.second.second &&x.second!=y.second){
            st.erase(x);
            st.erase(MP(max(y.second.first,y.second.second),y.second));
            st.erase(MP(min(x.second.first,x.second.second),x.second));
            st2.erase(y);
            pair<int,pair<int,int> > a,b,c,d;
            a = MP(max(x.second.first,y.second.second),MP(x.second.first,y.second.second));
            b = MP(max(y.second.first,x.second.second),MP(y.second.first,x.second.second));
            c = MP(min(x.second.first,y.second.second),MP(x.second.first,y.second.second));
            d = MP(min(y.second.first,x.second.second),MP(y.second.first,x.second.second));
            st.insert(a);
            st.insert(b);
            st2.insert(c);
            st2.insert(d);
        }
    }
    for(auto x:st){
        //cerr << x.second.second << " ";
        ans += abs(x.second.first-x.second.second);
    }
    //cerr << endl;
    cout << ans << endl;
    return 0;
}
