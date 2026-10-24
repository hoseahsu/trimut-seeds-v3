#include "bits/stdc++.h"
#define rep(var,cnt) for(int (var)=0; (var)<(cnt); ++(var))

using namespace std;

using pi=pair<int,int>;

int main() {
	int N; cin>>N;
	vector<pi> aw(N);
	vector<int> aa(N),ww(N);
	rep(i,N) cin>>aa[i];
	rep(i,N) cin>>ww[i];
	rep(i,N) aw[i]=pi(aa[i],ww[i]);
	vector<int> index(N);
	iota(index.begin(),index.end(),0);
	
	int ans=INT_MAX;
	do{
		int tmp=0;
		rep(i,N){
			if(aw[index[i]].first==0){
				if(aw[index[(i+1)%N]].first==1){
					tmp+=aw[index[i]].second;
					//cout<<"  "<<index[i]<<" fuman "<<aw[index[i]].second<<endl;
				}
			}
			else{
				if(aw[index[(i-1+N)%N]].first==0){
					tmp+=aw[index[i]].second;
					//cout<<"  "<<index[i]<<" fuman "<<aw[index[i]].second<<endl;
				}
			}
		}
		if(tmp<ans){
			ans=tmp;
			/*rep(i,N){
				cout<<index[i];
			}
			cout<<endl;*/
		}
	}while(next_permutation(index.begin(),index.end()));
	cout<<ans<<endl;
}
