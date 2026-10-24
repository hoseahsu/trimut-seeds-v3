#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
// #include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 5e5+5;
const int mod = 1e9+7;

int a[maxn],b[maxn][2];
int map[maxn],s[maxn];

int find(int x){
    if(map[x] == x) return x;
    return map[x] = find(map[x]);
}

void insert(int x,int y){
    int xx = find(x);
    int yy = find(y);
    map[xx] = map[yy];
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int n,m;
    int S = 0,ans = 1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<a[i];j++) cin>>b[i][j];
    }
    for(int i=1;i<=m;i++) map[i] = i;
    int last = 0;
    for(int i=1;i<=n;i++){
        if(a[i] == 1){
            if(last && find(last) == find(b[i][0])) continue;
            else if(last) insert(last,b[i][0]); 
            last = b[i][0];
            ans *= 2; ans %= mod;
            s[S++] = i;
        }else if(find(b[i][0]) == find(b[i][1])){
            continue;
        }else{
            insert(b[i][0],b[i][1]);
            ans *= 2; ans %= mod;
            s[S++] = i;
        }
        
    }
    cout<<ans<<" "<<S<<"\n";
    sort(s,s+S);
    for(int i=0;i<S;i++){
        cout<<s[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
