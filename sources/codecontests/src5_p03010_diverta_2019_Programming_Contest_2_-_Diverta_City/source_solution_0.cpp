#include<bits/stdc++.h>
using namespace std;
long long a1[13]={1,2,4,7,12,20,29,38,52,101},a2[13]={1,2,4,7,12,20,30,39,67,101},n,an[15][15],no=1;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)an[i][i]=0;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++)an[i][j]=an[j][i]=no*a1[j-i-1];
		no*=a2[n-i];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)cout<<an[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}