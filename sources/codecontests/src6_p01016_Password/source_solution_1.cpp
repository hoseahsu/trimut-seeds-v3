#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	bool answer = false;
	for(int i = 0; i + t.size() <= s.size(); ++i){
		bool match = true;
		for(int j = 0; j < t.size(); ++j){
			if(t[j] != '_' && s[i + j] != t[j]){ match = false; }
		}
		if(match){ answer = true; }
	}
	cout << (answer ? "Yes" : "No") << endl;
	return 0;
}
