#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
 
using namespace std;
 
int main(){
  int n;
  cin>>n;
  int f[n],a[n],t[n],x[n],y[n];
  for(int i=0;i<n;i++)
    cin>>f[i]>>a[i]>>t[i]>>x[i]>>y[i];
 
  double dist[2];
  double time[2];
  bool passed[2];
  dist[0]=dist[1]=0.0;
  time[0]=time[1]=0.0;
  passed[0]=passed[1]=false;

  if(n==1){
    puts("-1 -1");
    puts("-1 -1");
  }else{
    for(int i=1;i<n;i++){
      if(a[i]!=a[i-1] && t[i]==t[i-1]){
	double d=sqrt(pow((double)(x[i]-x[i-1]),2)+pow((double)(y[i]-y[i-1]),2));
	if(dist[t[i]] < d){
	  dist[t[i]]=d;
	  time[t[i]]=((double)(f[i]-f[i-1])/60.0);
	  passed[t[i]]=true;
	}else if(dist[t[i]] == d && time[t[i]]>(double)(f[i]-f[i-1])/60.0){
	  time[t[i]]=((double)(f[i]-f[i-1])/60.0);
	}
      }
    }
    if(passed[0]==true)
      printf("%lf %lf\n",dist[0],time[0]);
    else
      puts("-1 -1");
    
    if(passed[1]==true)
      printf("%lf %lf\n",dist[1],time[1]); 
    else
      puts("-1 -1");
  }
   
  return 0;
}