#include<bits/stdc++.h>
using namespace std;
int main(){
	int s = 0, mini = 1e9;
	for(int i = 0; i < 5; i++){
		int x;
		cin >> x;
		s += 10 * (ceil((double)x / 10));
		if(x % 10 < mini && x % 10 != 0)
			mini = x % 10;	
	}
	if(mini == 1e9)
		return cout << s, 0;
	cout << s - 10 + mini;
}
