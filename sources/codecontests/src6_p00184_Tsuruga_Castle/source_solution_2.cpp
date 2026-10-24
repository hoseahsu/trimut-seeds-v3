#include <iostream>
using namespace std;

int main(){
	int n, o;

	while(cin>>n, n!=0){
		int a[7]={0};
		while(n--){
			cin>>o;
			if(o<10)a[0]++;
			else if(o<20)a[1]++;
			else if(o<30)a[2]++;
			else if(o<40)a[3]++;
			else if(o<50)a[4]++;
			else if(o<60)a[5]++;
			else if(o>=60)a[6]++;
		}
		for(int i=0; i<7; i++){
			cout<<a[i]<<"\n";
		}
	}

	return 0;
}