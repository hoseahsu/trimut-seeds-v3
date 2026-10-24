#include<bits/stdc++.h>
using namespace std;

long long t,x;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>t;
	
	while(t--){
		cin>>x;
		
		bool flag=false;
		
		for(long long i=1;i<=10000;i++){
			long long tmp=x-i*i*i,tmp2;
			
			
			if(tmp<=0)continue;
			//cout<<"tmp "<<tmp<<"\n";
			
			tmp2=cbrt(tmp)+0.1;
			if(tmp2*tmp2*tmp2==tmp){
				flag=true;
				break;
			}
		}
		
		if(flag)cout<<"Yes\n";
		else cout<<"No\n";
	}

	return 0;
}

