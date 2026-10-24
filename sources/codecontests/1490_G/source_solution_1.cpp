//int max = 2 147 483 647 (2^31-1)
//ll max = 9 223 372 036 854 775 807 (2^63-1)
#include<bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<n;i++)
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;

//Fast input and output
void fast_io(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);}

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<< (ostream &cout, pair<A,B> const &p) {return cout << "(" << p.f << ", " << p.s << ")";}
template<typename A> ostream& operator<< (ostream &cout, vector<A> const&v){
cout << "["; forn(i,(int)v.size()){ if (i) cout << ", "; cout << v[i];} return cout << "]";}

ll divi(ll a, ll b){
  if(a>=0) return a/b;
  return (a+1)/b-1;
}

//main code
int main(){
  fast_io();
  //cout << divi(-1,2) << endl;
  int test; cin >> test;
  forn(tc,test){
    int n,m; cin >> n >> m;
    vector<ll> a(n);
    forn(i,n) cin >> a[i];
    vector<ll> pref=a;
    for(int i=1;i<n;i++) pref[i]+=pref[i-1];
    vector<ll>pmax=pref;
    for(int i=1;i<n;i++) pmax[i]=max(pmax[i],pmax[i-1]);
    //cout << pref << "  " << pmax << endl;
    forn(i,m){
      ll x, ans=0; cin >> x;
      if(pref[n-1]>0){
        ans=max(divi((x-pmax[n-1]-1),pref[n-1])+1,(ll)0)*n;
        x-=max(divi((x-pmax[n-1]-1),pref[n-1])+1,(ll)0)*pref[n-1];
      }
      //cout << x << " " << ans << "\n";
      int l=-1,r=n-1;
      while(l+1<r){
        int m=(l+r)/2;
        if(pmax[m]<x) l=m;
        else r=m;
      }
      //cout << r << " ";
      if(pmax[r]>=x) cout << ans+r << " ";
      else cout << "-1 ";
    }
    cout << "\n";
  }
}
