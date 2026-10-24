#include <bits/stdc++.h>
using namespace std;
int n,ans,a[100005];
int main(){
	scanf("%d",&n);
	for (int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	ans=a[1];
	for (int i=2; i<=n; i++){
		ans^=a[i];
	}
	if (ans==0){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	return 0;
}