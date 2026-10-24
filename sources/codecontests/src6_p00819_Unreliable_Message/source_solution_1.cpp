#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<cmath>
#include<cstring>
using namespace std;
int main(){
  int i,j,k;
  int n;
  cin>>n;
  for(i=0;i<n;++i){
    char s[7],t[26];
    cin>>s>>t;
    int sln=strlen(s);
    int tln=strlen(t);
    for(j=sln-1;j>=0;--j){
      if(0){
      }else if(s[j]=='J'){
	char u=t[tln-1];
	for(k=tln-1;k>0;--k)
	  t[k]=t[k-1];
	t[0]=u;
      }else if(s[j]=='C'){
	char u=t[0];
	for(k=1;k<tln;++k)
	  t[k-1]=t[k];
	t[tln-1]=u;
      }else if(s[j]=='E'){
	char u[12];
	memcpy(u,t,tln/2*sizeof(char));
	memcpy(t,t+(tln+1)/2,tln/2*sizeof(char));
	memcpy(t+(tln+1)/2,u,tln/2*sizeof(char));
      }else if(s[j]=='A'){
	char u[26];
	for(k=0;k<tln;++k)
	  u[k]=t[tln-k-1];
	memcpy(t,u,tln*sizeof(char));
      }else if(s[j]=='P'){
	for(k=0;k<tln;++k){
	  if(0){
	  }else if(t[k]=='0'){
	    t[k]='9';
	  }else if('1'<=t[k]&&t[k]<='9'){
	    --t[k];
	  }
	}
      }else if(s[j]=='M'){
	for(k=0;k<tln;++k){
	  if(0){
	  }else if(t[k]=='9'){
	    t[k]='0';
	  }else if('0'<=t[k]&&t[k]<='8'){
	    ++t[k];
	  }
	}
      }
    }
    cout<<t<<endl;
  }
  return 0;
}