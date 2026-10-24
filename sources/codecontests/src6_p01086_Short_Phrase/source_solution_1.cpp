#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)

using namespace std;

string str[41];
int k;
int n;

bool check(int p, int c)
{
	int cnt =0;
	for(int i=p;i<n;i++){
		cnt += str[i].length();
		k++;
		if(cnt == c) return true;
		else if(cnt > c)return false;
	}
	return false;
}

int main(){
	while(cin>>n, n){
		rep(i,n) cin >> str[i];
		rep(i,n){
			k = i;
			if(check(k,5) && check(k,7) && check(k,5) && check(k,7) && check(k,7)) {
				cout << i+1 << endl;
				break;
			}
		}
	}
	return 0;
}