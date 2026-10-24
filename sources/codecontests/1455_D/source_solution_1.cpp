//clear adj and visited vector declared globally after each test case
//check for long long overflow
//while adding and subs check if mod becomes -ve
//while using an integer directly in a builtin function add ll
//Mod wale question mein last mein if dalo ie. Ans<0 then ans+=mod;
//Dont keep array name as size or any other key word

#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;
#define Fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define f(i, n) for (long long int i = 0; i < n; i++)
#define ll long long int
#define fo(i, a, b) for (long long int i = a; i <= b; i++)
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define vi vector<int>
#define vl vector<long long int>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long int>>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define mll map<ll,ll>
#define umll unordered_map<ll,ll>
#define newl cout<<"\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll inf = 1e9 + 7;
const ll mod = 998244353;
#define MAX 501

ll mini(ll a,ll b){
    if(a>=b)return b;
    return a;
}

ll maxi(ll a,ll b){
    if(a>=b)return a;
    return b;
}

int notsorted(vl &A,ll n){
    fo(i,1,n-1){
        if(A[i]>A[i+1])return 1;
    }
    return 0;

}

int main(){
    Fio;
    w(t){
        ll n,x;
        cin>>n>>x;
        vl A(n+1);
        fo(i,1,n)cin>>A[i];
        ll ans = 0;
        while(notsorted(A,n)){
            ans++;
            ll i = 0;
            while(i<n && A[i]<=x)i++;
            if(i==n){
                ans = -1;
                break;
            }
            swap(A[i],x);
        }
        cout<<ans;
        newl;
    }
    return 0;
}     