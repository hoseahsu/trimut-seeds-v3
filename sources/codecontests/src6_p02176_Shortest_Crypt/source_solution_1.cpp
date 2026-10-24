/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll ue = 0, migi = 0;
    rep(i,0,N){
        if(S[i] >= 'A' && S[i] <= 'M'){
            ue++;
        }else if(S[i] >= 'N' && S[i] <= 'Z'){
            ue--;
        }else if(S[i] >= 'a' && S[i] <= 'm'){
            migi++;
        }else{
            migi--;
        }
    }
    ll sz = abs(ue) + abs(migi);
    print(sz);
    rep(i,0,abs(ue)){
        if(ue > 0){
            cout << 'A';
        }else{
            cout << 'N';
        }
    }
    rep(i,0,abs(migi)){
        if(migi > 0){
            cout << 'a';
        }else{
            cout << 'n';
        }
    }
    cout << endl;

    
}
