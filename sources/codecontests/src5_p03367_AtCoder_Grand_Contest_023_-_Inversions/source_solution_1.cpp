#include<bits/stdc++.h>
#define mo 1000000007
#define ni2 500000004
#define N 200010
#define ll long long
using namespace std;
ll po(ll x,ll y){ll z=1;while(y){if(y%2)z=x*z%mo;x=x*x%mo;y/=2;}return z;}
struct fs{ll x;int y;}q[N],p[N];
fs operator *(fs x,ll y){if (y==0) x.y++;else x.x=x.x*y%mo;return x;}
fs operator *(fs x,fs y){fs z;z.y=x.y+y.y;z.x=x.x*y.x%mo;return z;}
fs operator /(fs x,fs y){fs z;z.y=x.y-y.y;z.x=x.x*po(y.x,mo-2)%mo;return z;}
fs operator +(fs x,fs y){
	if (x.y>y.y) swap(x,y);
	if (x.y==y.y)x.x=x.x+y.x;
	if (x.x%mo==0){x.y++;x.x/=mo;}
	x.x%=mo;
	return x;
}
ll zh(fs x){if (x.y==0)return x.x;return 0;}
ll sum,a[N],g[N],ans;
int n;
void work(int l,int r){
	if (l>=r) return ;
	int mid=(l+r)/2;
	work(l,mid);work(mid+1,r);
	fs x;x=(fs){0,n+1};
	for (int i=mid,j=r;i>=l;i--){
		while (a[j]>=a[i]&&j>mid){x=x+p[a[j]];j--;}
		ans=(ans+(sum*zh(x/p[a[i]])%mo)*ni2)%mo;
	}
	x=(fs){0,n+1};
	for (int j=r,i=mid;j>mid;j--){
		while (a[i]>a[j]&&i>=l){x=x+p[a[i]];i--;}
		ans=(ans+sum*(mid-i+mo-zh(x/p[a[j]])*ni2%mo))%mo;
	}
	sort(a+l,a+r+1);
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){cin>>a[i];g[a[i]]++;}
	for (int i=n;i>=1;i--)g[i]+=g[i+1];
	for (int i=1;i<=n;i++)g[i]=g[i]-n+i;
	for (int i=1;i<=n;i++)if (g[i]<=0){puts("0");return 0;}
	q[0]=(fs){1,0};for (int i=1;i<=n;i++)q[i]=q[i-1]*g[i];
	p[0]=(fs){1,0};for (int i=1;i<=n;i++)p[i]=p[i-1]*(g[i]-1);
	for (int i=1;i<=n;i++)p[i]=p[i]/q[i];
	sum=q[n].x;
	work(1,n);
	cout<<ans<<endl;
	return 0;
}