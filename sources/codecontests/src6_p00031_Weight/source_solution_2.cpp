#include<iostream>
using namespace std;

int main(void){
	int N, ans;
	while(cin >> N){
		for(int i = 0; i < 10; i++){
			if(N & 1){
				ans = 1 << i;
				cout << ans;
				if(N >> 1)
					cout << ' ';
			}
			N >>= 1;
		}
		cout << endl;
	}
}