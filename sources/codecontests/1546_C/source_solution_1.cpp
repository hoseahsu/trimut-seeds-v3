#include<bits/stdc++.h>
using namespace std;
struct val{
	int odd = 0;
	int even = 0;
};
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int a[n],b[n];for(int i=0;i<n;i++)cin>>a[i],b[i] = a[i];
		sort(b,b+n);
		map<int,val>mp;
		for(int i=0;i<n;i++){
			if(i & 1)mp[b[i]].odd++;
			else mp[b[i]].even++;
		}
		bool yo = true;
		for(int i=0;i<n;i++){
			if(i & 1 && !mp[a[i]].odd || !(i & 1) && !mp[a[i]].even){
				yo = false;
				break;
			}
			else if(i & 1)mp[a[i]].odd--;
			else if(!(i & 1))mp[a[i]].even--;
		}
		if(yo)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}