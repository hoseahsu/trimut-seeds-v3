#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100000];
int ans;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=k;i++){
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}