#include<bits/stdc++.h>
using namespace std;
int main(){
  bitset<7> a[10];
  string num2[10]={"0111111","0000110","1011011","1001111","1100110","1101101","1111101","0100111","1111111","1101111"};
  for(int i=0;i<10;i++){
    a[i]=bitset<7>(num2[i]);
  }
  while(1){
    long long n,num;
    cin>>n;
    if(n==-1) break;
    bitset<7> now(0);
    for(int i=0;i<n;i++){
      cin>>num;
      bitset<7> out=now^a[num];
      cout<<(now^a[num])<<endl;
      now=a[num];
    }
  }
}