#include<iostream>
#include<bitset>
#include<cmath>
using namespace std;
int main(){
	int weight;
	while(cin>>weight){
		bitset<10> num(weight);
		int i;
		for(i=0;num[i]==0;++i);
		cout<<pow(2.0,i);
		for(++i;i<10;++i){
			if(num[i]==1)cout<<' '<<pow(2.0,i);
		}
		cout<<endl;
	}
}