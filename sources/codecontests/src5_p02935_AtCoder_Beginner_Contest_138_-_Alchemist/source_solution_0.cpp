#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	float a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	if(n==1){
		cout<<a[0]<<endl;
		return 0;
	}
	double c=(a[0]+a[1])/2;
	for(int i=2;i<n;i++){
		c=(c+a[i])/2;
	}
	cout<<c<<endl;
}