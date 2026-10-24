#include <iostream>
using namespace std;
int main(){
	int m,n;
	while(cin>>m){
		if(m==0)break;
		cin>>n;
		int count=0;
		for(int i=m;i<=n;++i){
			int a=i;
			while((a%2==0)||(a%3==0)||(a%5==0)){
				if(a%2==0)a/=2;
				else if(a%3==0)a/=3;
				else if(a%5==0)a/=5;
			}
			if(a==1)count++;
		}
		cout<<count<<"\n";
	}
}