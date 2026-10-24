#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n;
	while(cin >> n, n){
		int count = 0;
		for(int i = 1; i <= n/2; i++){
			int sum = 0;
			for(int j = i; sum < n; j++){
				sum += j;
				if(sum == n){
					count++;
					break;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}
