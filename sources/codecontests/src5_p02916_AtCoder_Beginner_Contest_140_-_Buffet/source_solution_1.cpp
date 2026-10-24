#include <bits/stdc++.h>
using namespace std;
int main () {
	int n,ans=0;
	cin>>n;
	int a[n],b,c[n];
	for (int i=0;i<n;i++) {
		cin>>a[i];
	}
	for (int i=0;i<n;i++) {
		cin>>b;
		ans+=b;
	}
	for (int i=0;i<n-1;i++) {
		cin>>c[i];
	}
	for (int i=0;i<n-1;i++) {
		if (a[i]+1==a[i+1]) {
			ans+=c[a[i]-1];
		}
	}
	cout<<ans;
}