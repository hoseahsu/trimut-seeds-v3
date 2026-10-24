#include<iostream>
using namespace std;
int n,a,c,i;
int main(){
  cin>>n;
  for(i=0;i<n;++i){
    cin>>c;
    a^=c;
  }
  cout<<(a?"No":"Yes");
}
