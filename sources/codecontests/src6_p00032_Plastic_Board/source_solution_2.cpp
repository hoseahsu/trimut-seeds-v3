#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  int a,b,c,cnt_tyou=0,cnt_hishi=0;
  while(scanf("%d,%d,%d",&a,&b,&c) != EOF){
    if(a==b) cnt_hishi++;
    if(a*a + b*b == c*c) cnt_tyou++;
  }
  cout<<cnt_tyou<<endl<<cnt_hishi<<endl;
  return 0;
}