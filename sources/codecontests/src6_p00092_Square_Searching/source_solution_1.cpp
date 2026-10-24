#include<iostream>
#include<algorithm>
using namespace std;

int n;
int s[1001][1024];
int calc(int y,int x,int n){
	int a,b,c,d;
	n--;
	a=s[y-1][x-1];
	b=s[y-1][x+n];
	c=s[y+n][x-1];
	d=s[y+n][x+n];
	return d-c-b+a;
}
int main(){
	while(cin>>n,n){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				char c;
				cin>>c;
				s[i][j] = (c=='*')+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int lb=ans,ub=n-max(i,j)+2;
				if(ub+1<=ans)continue;
				while(ub-lb>1){
					int m=(lb+ub)/2;
					if(calc(i,j,m))ub=m;
					else lb=m;
				}
				ans=max(ans,lb);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}