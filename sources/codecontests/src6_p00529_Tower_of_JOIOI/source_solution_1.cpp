#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N;
string s;
bool used[1000100];
bool check(int x){
	memset(used,false,sizeof(used));
	vector<int> vI,vO;
	int cnt = 0;
	for(int i=N-1;i>=0;i--){
		if(s[i]=='I'){
			used[i]=true;
			vI.pb(i);
			cnt++;
		}
		if(cnt==x)break;
	}
	if(cnt<x)return false;
	reverse(all(vI));
	for(int i=N-1;i>=0;i--){
		if(sz(vI)==0)break;
		if(s[i]=='O'&&i<vI.back()){
			vO.pb(i);
			vI.pop_back();
		}
	}
	if(sz(vI)>0)return false;
	reverse(all(vO));
	for(int i=N-1;i>=0;i--){
		if(sz(vO)==0)break;
		if(s[i]!='O'&&!used[i]&&i<vO.back()){
			vO.pop_back();
		}
	}
	if(sz(vO)>0)return false;
	return true;
}
int main(){
	scanf("%d",&N);
	cin >> s;
	int l = 0,r = N;
	while(r-l>1){
		int mid = (l+r)/2;
		if(check(mid))l=mid;
		else r = mid;
	}
	printf("%d\n",l);
	return 0;
}