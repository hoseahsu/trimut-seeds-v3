#include<iostream>
#include<queue>
#include<cmath>

using namespace std;
long long a[100005]={0},b[100005]={0},d[100005]={0},sum,v[100005]={0};
int main(){
	long long n,c,i;
	cin>>n>>c;
	d[0]=0;d[n+1]=c;
	for(i=1;i<=n;i++)
		cin>>d[i]>>v[i];
	for(i=1;i<=n;i++)
	{
	a[i]=a[i-1]+v[i]-(d[i]-d[i-1]);
} 
	for(i=n;i>=1;i--){
		b[i]=b[i+1]+v[i]-(d[i+1]-d[i]);
	}
	for(i=2;i<=n;i++){
		a[i]=max(a[i-1],a[i]); 
	}
	for(i=n-1;i>=1;i--){
		b[i]=max(b[i+1],b[i]);
	}
	long long sum=0;
	for(i=1;i<=n;i++){
		sum=max(sum,a[i]);
		sum=max(sum,b[i]);
		sum=max(sum,a[i]+b[i+1]-d[i]);
		sum=max(sum,a[i-1]+b[i]-(c-d[i]));
	}
	cout<<sum<<endl;
	return 0;
}