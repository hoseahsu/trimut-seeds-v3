#include <iostream>
using namespace std;

int main() {
	int k;
	cin >> k;
	int c = 0, m=0;
	while(k--){
		int a, b;
		cin >> a >> b;
		if(a == b){
			c++;
			m = max(m,c);
		}else{
			c=0;
		}
	}
	if(m>=3){
		cout << "Yes" ;
	}else{
		cout << "No";
	}
	return 0;
}