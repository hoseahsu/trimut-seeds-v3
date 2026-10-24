#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
	int n;
	double pi=2*acos(0);
	while(cin>>n&&n!=-1){
		double x=1,y=0,rad=pi;
		for(int i=0;i<n-1;i++){
			rad -= pi/2;
			x += cos(rad);
			y += sin(rad);
			rad = atan2(-y,-x);
		}
		printf("%.2f\n%.2f\n",x,y);
	}
	return 0;
}