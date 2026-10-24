#include <iostream>
#include <cstring>
using namespace std;

#define REP(i,n,m) for(int i=n;i<m;i++)
#define rep(i,n) REP(i,0,n)

int n,cnt[14],ans[54];

bool solve(int idx,int sum){
	if(idx == 0 && sum == 0) return true;
	if(idx < 0 || sum < 0) return false;

	rep(i,14){
		if(cnt[i]>0 && (sum - i) % i == 0){
			ans[idx-1] = i;
			cnt[i]--;
			if(solve(idx-1,sum-i)) return true;
			cnt[i]++;
		}
	}

	return false;
}

int main(void){
	while(cin>>n,n){
		int sum = 0;
		memset(cnt,0,sizeof(cnt));
		rep(i,n){
			int x;
			cin>>x;
			sum += x;
			cnt[x]++;
		}
		bool flg = solve(n,sum);
		if(flg){
			rep(i,n-1) cout<<ans[i]<<" ";
			cout<<ans[n-1]<<endl;
		}
		else{
			cout<<"No\n";
		}
	}

	return 0;
}