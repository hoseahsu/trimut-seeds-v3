#include<cstdio>

int a[100000+5],n;

void swp(int x,int y){
	int t=a[x];
	a[x]=a[y];
	a[y]=t;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==i){
			swp(i,i+1);
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}	 
