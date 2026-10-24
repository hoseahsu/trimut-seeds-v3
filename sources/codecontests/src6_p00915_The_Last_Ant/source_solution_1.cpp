#include<bits/stdc++.h>
using namespace std;


int n,l;
char d[200];
int p[200];

int main(){
  while(1){
    cin>>n>>l;
    if(n==0&&l==0)break;
    int maxm=0,id=0;
    for(int i=0;i<n;i++){
      cin>>d[i]>>p[i];
      int a=p[i];
      if(d[i]=='R')a=l-a;
      if(a==maxm&&d[i]=='L'){
	id=i;
      }else if(a>maxm){
	maxm=a;
	id=i;
      }
    }
    
    vector<int> vec;
    int cnt=0;
    
    if(d[id]=='L'){
      for(int i=id;i>=0;i--){
	int e=abs(p[id]-p[i]);
	if(e%2==1)continue;
	if(d[i]=='R')cnt++;
	vec.push_back(i);
      }
    }else{
      for(int i=id;i<n;i++){
	int e=abs(p[id]-p[i]);
	if(e%2==1)continue;
	if(d[i]=='L')cnt++;
	vec.push_back(i);
      }
    }
    cout<<maxm<<' '<<vec[cnt]+1<<endl;
  }
  return 0;
}