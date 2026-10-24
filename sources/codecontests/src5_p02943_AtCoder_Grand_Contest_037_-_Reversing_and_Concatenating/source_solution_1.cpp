#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
typedef long long LL;

LL n,k,q = 0,p[5005];
char ch = 'z';
string s,t;

int main(){
	cin >> n >> k;
	cin >> s;
	for(LL i = 0;i < n;i ++) ch = min(ch,s[i]);
	for(LL i = 0;i < n;i ++){
		p[i] = (s[i] == ch ? p[i - 1] + 1 : 0);
		q = max(q,p[i]);
	}
	q = max(q,p[n - 1] << 1);
	t = s; reverse(t.begin(),t.end()); s = s + t;
	t = s.substr(0,n);
	for(LL i = 1;i <= n;i ++) t = min(t,s.substr(i,n));
//	for(LL i = 0;i <= n;i ++) cout << s.substr(i,n) << endl;
//	cout << q << endl;
	for(LL i = 2;i <= k;i ++){
		s = t; reverse(s.begin(),s.end()); s += t;
		t = s.substr(n - q,n);
		q <<= 1; if(q > n) break;
	}
	cout << t << endl;
	return 0;
}