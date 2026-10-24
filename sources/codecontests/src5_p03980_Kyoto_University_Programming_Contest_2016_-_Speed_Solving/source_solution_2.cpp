#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#include<sstream>
using namespace std;
using ulong = unsigned long;
using ll = long long;
const int M = 1e9 + 7;
#pragma unused(M)

string next(string s){
	int idx = 0;
	if(s[idx] == '^' || s[idx] == '_'){
		int cnt = 0;
		for(;idx<s.size();idx++){
			if(s[idx] == '('){
				cnt++;
			}else if(s[idx] == ')'){
				cnt--;
				if(!cnt){ return s.substr(0, idx + 1);}
			}
		}
	}else{
		while(s[idx] >= '0' && s[idx] <= '9') idx++;
		return s.substr(0, idx);
	}
}

pair<int, int> calc(string s, int mini = 0, int maxi = 99){
	// cout<<s<<' '<<mini<<' '<<maxi<<endl;
	string lstr, rstr;
	int l, r;
	if(s[0] == '^'){
		int idx = 2;
		lstr = next(s.substr(idx));
		auto lp = calc(lstr, mini, maxi);
		l = lp.first;
		if(l >= maxi){ return {maxi, idx + lp.second}; }
		idx += lstr.size() + 1;
		rstr = next(s.substr(idx));
		auto rp = calc(rstr, max(mini, l), maxi);
		r = rp.first;
		return {min(maxi, max(mini, max(l, r))), idx + rp.second};
	}else if(s[0] == '_'){
		int idx = 2;
		lstr = next(s.substr(idx));
		auto lp = calc(lstr, mini, maxi);
		l = lp.first;
		if(l <= mini){ return {mini, idx + lp.second}; }
		idx += lstr.size() + 1;
		rstr = next(s.substr(idx));
		auto rp = calc(rstr, mini, min(maxi, l));
		r = rp.first;
		return {min(maxi, max(mini, min(l, r))), idx + rp.second};
	}else{
		int idx = 0;
		lstr = next(s.substr(idx));
		if(lstr[0] - '0' >= maxi){ return {maxi, 1}; }
		if(lstr[0] == '0'){ return {0, 1}; }
		if(lstr[0] - '0' < (mini + 1) / 10){ return {mini, 1}; }
		l = atoi(lstr.c_str());
		return {l, 2};
	}
}

int main(){
	int q;
	cin >> q;
	for(int i=0;i<q;i++){
		string s;
		cin >> s;
		auto p = calc(s);
		cout << p.first << ' ' << p.second << endl;
	}
	return 0;
}

