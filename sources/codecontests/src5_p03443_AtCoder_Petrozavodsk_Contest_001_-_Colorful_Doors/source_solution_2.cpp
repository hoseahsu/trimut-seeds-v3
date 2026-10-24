#include <bits/stdc++.h>
using namespace std;

void fail(){
	cout << "No" << '\n';
	exit(0);
}

void done(vector<int> ret){
	cout << "Yes" << '\n';
	for(int a : ret) cout << a + 1 << ' ';
	cout << '\n';
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	n *= 2;
	string s;
	cin >> s;
	s = "1" + s;
	int c0 = 0;
	for(int i = 0; i < n; i++) if(s[i] == '0') c0++;
	vector<int> ret(n, -1);
	int cur = 0;
	int used = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '0' && s[i+1] == '0'){
			ret[i] = cur;
			used++;
			if(used == 2){
				used = 0;
				cur++;
			}
		}
	}
	if(used == 1) fail();
	if(c0 == 0){
		// single cycle of length n
		if(n % 4 != 0) fail();
		for(int i = 0; i < n; i++){
			if(s[i] == '1' && s[(i+1)%n] == '1'){
				ret[i] = cur + (used & 1);
				used++;
				if(used == 4){
					used = 0;
					cur += 2;
				}
			}
		}
		done(ret);
	}
	int npaths = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '0' && s[(i+1)%n] == '1' && s[(i+2)%n] != '0'){
			npaths++;
		}
	}
	int c11 = 0;
	for(int i = 0; i < n; i++) if(s[i] == '1' && s[(i+1) % n] == '1') c11++;
	// single path of length
	if(npaths <= 1){
		if(c11 % 4 != 0) fail();
		for(int i = 0; i < n; i++){
			if(s[i] == '1' && s[(i+1)%n] == '1'){
				ret[i] = cur + (used & 1);
				used++;
				if(used == 4){
					used = 0;
					cur += 2;
				}
			}
		}
		for(int i = 0; i < n; i++){
			if(s[i] != s[(i+1)%n]){
				ret[i] = cur;
				used++;
				if(used == 2){
					used = 0;
					cur++;
				}
			}
		}
		done(ret);
	}
	if(c11 % 4 != 0){
		int i = 0;
		while(s[i] != '0' || s[(i+1)%n] != '1' || s[(i+2)%n] != '1') i = (i+1)%n;
		ret[i] = cur;
		while(s[(i+1)%n] != '0') i = (i+1)%n;
		ret[i] = cur;
		cur++;
		i = (i+n-1)%n;
		ret[i] = cur;
		while(s[(i+n-1)%n] != '1' || s[i] != '1' || s[(i+1)%n] != '0') i = (i+n-1)%n;
		i = (i+n-1)%n;
		ret[i] = cur;
		cur++;
	}
	for(int i = 0; i < n; i++){
		if(ret[i] == -1 && s[i] == '1' && s[(i+1)%n] == '1'){
			ret[i] = cur + (used & 1);
			used++;
			if(used == 4){
				used = 0;
				cur += 2;
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(ret[i] == -1 && s[i] != s[(i+1)%n]){
			ret[i] = cur;
			used++;
			if(used == 2){
				used = 0;
				cur++;
			}
		}
	}
	done(ret);
}