#include <iostream>
#include <fstream>
#include <algorithm>
//#define LOCAL
using namespace std;
typedef long long ll;
const int mx=1e3+10;
ll num[mx];


int main() {
#ifdef LOCAL
ifstream fin("1.txt");
streambuf*p;
p=cin.rdbuf(fin.rdbuf());
#endif // LOCAL
ll n;
cin>>n;
for(ll i=0;i<n;i++) cin>>num[i];
ll qn;
cin>>qn;
for(ll i=1;i<=qn;i++){
    ll b, e, t;
    cin>>b>>e>>t;
    ll k=e-b;
    for(ll d=0;d<k;d++){
        swap(num[b+d], num[t+d]);
    }
}
for(ll i=0;i<n;i++){
    if(0==i) printf("%lld", num[i]);
    else printf(" %lld", num[i]);
}
puts("");

#ifdef LOCAL
fin.close();
#endif // LOCAL
}


