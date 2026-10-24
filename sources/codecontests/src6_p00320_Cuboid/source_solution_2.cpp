#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define LINF (ll)INF*INF
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(int i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

#define int ll //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vp;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int lcm(int a, int b){
    return a/gcd(a,b)*b;
}


signed main(void) {
    vp a(6);
    rep(i,6){
        cin >> a[i].first >> a[i].second;
        if(a[i].first > a[i].second)swap(a[i].first,a[i].second);
    }
    sort(all(a));
    if(a[0] != a[1] || a[2] != a[3] || a[4] != a[5]){
        cout << "no" << endl;
    }else{
        if(a[0].first == a[2].first && a[0].second == a[4].first && a[2].second == a[4].second)
            cout << "yes" << endl;
        else 
            cout << "no" << endl;
    }
}

