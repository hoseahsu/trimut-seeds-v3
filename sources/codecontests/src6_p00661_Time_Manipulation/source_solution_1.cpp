#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) (EQ((a).real(),(b).real()) && EQ((a).imag(),(b).imag()))

typedef complex<double> P;
typedef long long ll;

const int MAX_M=100000;
int a[MAX_M];

ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}

pair<ll,ll> InclusionExclusion(ll n,ll m){
    // a1,a2,..Ì¤¿A­È­ÆàPÂÅèØêéàÌÌa
    ll sum=0;
    // ­È­ÆàPÂÅèØêéàÌÌÂ
    ll res=0;
    for(int i=1;i<(1<<m);i++){
        ll num=0;
        for(ll j = i;j!=0;j>>=1)
            num+=j&1;
        ll lcm=1;
        for(int j = 0; j <m; j++){
            if((i>>j)&1){
                lcm=lcm/gcd(lcm,a[j])*a[j];
                if(lcm>n)
                    break;
            }
        }
        if(num%2==0){
            int t=n/lcm;
            sum-=lcm*t*(t+1)/2;
            res-=n/lcm;
        }
        else{
            res+=n/lcm;
            ll t=n/lcm;
            sum+=lcm*t*(t+1)/2;
        }
    }
    sum=n*(n+1)/2-sum;
    res=n-res;
    return make_pair(res,sum);
}

void solve(){
    ll n,m;
    while(cin>>n>>m&&!(n==0&&m==0)){
        for(int i = 0; i < m; i++)
            cin>>a[i];
        pair<ll,ll> p=InclusionExclusion(n,m);
        if(p.first==0){
            p.second=0;p.first=1;
        }
        printf("%.7f\n",(double)p.second/p.first);
    }
}

int main(){solve();return 0;}