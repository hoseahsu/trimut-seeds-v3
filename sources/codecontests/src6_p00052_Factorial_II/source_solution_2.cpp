#include<iostream>
using namespace std;
int main()
{
	int n,zero;
	while(1){
		cin>>n;
		if(n==0)break;
			else {
			zero=0;
			while(n>0){
				zero=zero+n/5;
				n=n/5;
			}
			cout<<zero<<endl;
		}
	}
	return 0;
}