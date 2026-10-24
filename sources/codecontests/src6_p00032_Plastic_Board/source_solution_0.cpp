#include <iostream>
using namespace std;

int main(void){

	int rectangle=0, lozenge=0;

	while (true){
		int a,b,c;
		char e;
		cin>>a>>e>>b>>e>>c;
		if (cin.eof()) break;
		if (a==b) lozenge++;
		if (a*a+b*b==c*c) rectangle++;
	}
	cout<<rectangle<<endl;
	cout<<lozenge<<endl;
	return 0;
}