#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b,i,j,n,cur=1;
	cin >> a >> b;
	string s;
	cin >> s;
	for(i=0; i<a+b+1; i++){
		if((i!=a && s[i]=='-')||(i==a && s[i]!='-')){
			cout << "No"; return 0;
		}
	}
	
	cout << "Yes";
}