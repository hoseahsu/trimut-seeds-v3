#include <bits/stdc++.h>
using namespace std;

int a[1005];

int main(){
  
  while(1){
  
    int n, m;
    cin>>n>>m;
    
    if( !n && !m ) break;
    
    for(int i=0;i<n;i++) cin>>a[i];
  
    int ans = 0;
  
    for(int i=0;i<n;i++){
    
      for(int j=i+1;j<n;j++){
      
	int sum = a[i] + a[j];
      
	if( sum <= m ) ans = max( ans, sum );
      
      }
    
    }
  
    if( ans == 0 ) cout<<"NONE"<<endl;
    else cout<<ans<<endl;

  }
  
  return 0;
}

