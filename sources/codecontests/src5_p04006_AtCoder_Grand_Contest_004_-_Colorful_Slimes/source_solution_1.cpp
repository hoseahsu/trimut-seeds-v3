#include<bits/stdc++.h>
using namespace std;

int a[2000],v[2000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,x;
	cin>>n>>x;
	long long int ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		v[i]=a[i];
		ans+=a[i];
	}
	for(int i=1;i<n;i++){
		long long int now=1LL*i*x;
		for(int j=0;j<n;j++)
			now=(now+(v[(j+i)%n]=min(v[(j+i)%n],a[j])));
		ans=min(ans,now);
	}
	cout<<ans<<endl;
}
