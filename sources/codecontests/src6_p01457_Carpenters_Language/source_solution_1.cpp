#include<iostream>
using namespace std;
int main(){
	long long n,r=0,l=0,a,b;
	char c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c>>b;
		if(c==')')r+=b;
		else l+=b;
		if(l==r)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}

	return 0;
}