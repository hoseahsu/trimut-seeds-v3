#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf=1e13;
ll n,a[2005],m[2005],x,res=inf,tr;
int main()
{
    memset(m,0x3f,sizeof m);
    scanf("%lld%lld",&n,&x);
    for (int i=0;i<n;++i)
        scanf("%lld",&a[i]);
    for (ll i=0;i<n;++i) {
        tr=x*i;
        for (ll j=0;j<n;++j) {
            m[j]=min(m[j],a[(j-i+n)%n]);
            tr+=m[j];
        }
        res=min(res,tr);
    }
    printf("%lld\n",res);
    return 0;
}
