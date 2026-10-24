#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n,ans=0;
	cin >> n;
	vector<int>	a(n),b(n);
	for(int i=0;i<n;i++)	cin >> a[i];
	for(int i=0;i<n;i++)	cin >> b[i];
 	for(int i=1;i<n;i++)	a[i]+=a[i-1];
	for(int i=n-2;i>=0;i--)	b[i]+=b[i+1];
	for(int i=0;i<n;i++)	ans = max(ans,a[i]+b[i]);
	cout << ans << endl;
}