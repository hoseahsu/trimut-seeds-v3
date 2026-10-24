#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int s,t,d;
ll w[100001];
ll sum=0;
ll af[100001];

int main(void){
	scanf("%d%d%d",&s,&t,&d);
	for(int i=0;i<d;i++){
		scanf("%lld",&w[i]);
		sum-=w[i];
	}
	ll res=-2;
	ll now=s;
	for(int i=0;i<d;i++){
		now+=w[i];
		if(now<=t){
			printf("%d\n",i+1);
			return 0;
		}else if(sum>0LL){
			ll rest=now-t;
			ll val=(ll)i+(rest+sum-1LL)/sum*d;
			if(res==-2){
				res=val;
			}else{
				res=min(res,val);
			}
		}
	}
	printf("%lld\n",res+1LL);
	return 0;
}