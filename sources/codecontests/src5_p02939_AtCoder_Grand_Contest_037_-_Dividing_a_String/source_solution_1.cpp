#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	int l = s.size();
	string s1 = "",s2 = "";
	int cnt = 0;
	for(int i = 0;i < l;i++){
		s1 += s[i];
		if(s1 != s2){
			cnt++;
			s2 = s1;
			s1 = "";
		}
	}
	cout << cnt << endl;
	return 0;
}