#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
	int cntS=0,cntT=0;
	string s;
	cin>>s;
	rep(i,(int)s.size()){
		if(s[i]=='S')cntS++;
		else if(cntS==0)cntT++;
		else cntS--;
	}
	cout<<cntS+cntT<<endl;

	return 0;
}
