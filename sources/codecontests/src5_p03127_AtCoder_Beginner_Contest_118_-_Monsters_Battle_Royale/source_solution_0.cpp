#include<iostream>
using namespace std;
int main(){
  int n,a,b,c,i=1;
  cin >> n;
  cin >> a;
  do{
    cin >> b;
    if(a<b){c=b;b=a;a=c;}
    while(a%b){
      c=b;b=a%b;a=c;
    }
    a=b;i++;
  }while(i<n);
  cout << a;
  return 0;
}