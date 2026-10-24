#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,string>;
using Map = map<string,ll>;



int main(){
	ll N;
	cin >> N;
	string S;
	cin >> S;
	ll wcounter=0;
	for(ll i=0;i<N;i++){
		if(S[i]=='.')wcounter++;
	;}
	ll ans=wcounter;
	ll num=wcounter;
	for(ll i=0;i<N;i++){
		if(S[i]=='#')num++;
		else if(S[i]=='.')num--;
		ans=min(ans,num)
	;}
	cout<<ans<<endl;

return 0;
}  

