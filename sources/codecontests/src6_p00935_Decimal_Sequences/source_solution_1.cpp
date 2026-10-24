#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
bool p[10000];
int main(){
	int n,c;
	cin>>n;
	int a[n];
	r(i,n)cin>>a[i];
	r(i,n)p[a[i]]=true;
	if(n>1)r(i,n-1){
		int s=a[i]*10+a[i+1];
		p[s]=true;
	}
	if(n>2)r(i,n-2){
		int s=a[i]*100+a[i+1]*10+a[i+2];
		p[s]=true;
	}
	if(n>3)r(i,n-3){
		int s=a[i]*1000+a[i+1]*100+a[i+2]*10+a[i+3];
		p[s]=true;
	}c=0;
	while(p[c])c++;
	cout<<c<<endl;
}