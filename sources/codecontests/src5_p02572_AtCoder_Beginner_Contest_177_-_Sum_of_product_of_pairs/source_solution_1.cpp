#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<long long> v(n);
	long long M=1e9+7;
	for(int i=0;i<n;i++) cin>>v[i];
	vector<long long> s(n,0);
	s[n-1]=v[n-1];
	for(int i=n-2;i>=0;i--){
		s[i]=(s[i+1]+v[i])%M;
	}
	long long p=0;
	for(int i=0;i<n-1;i++){
		p=(p + v[i]*s[i+1])%M;
	}
	cout<<p<<endl;
}