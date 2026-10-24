#include <iostream>
using namespace std;

int main(){
	int N, K, a;
	cin >> N >> K;
	a=K;
	for(int i=1; i<N; i++){
		a = a*(K-1);
	}
	cout << a ;
}