#include <bits/stdc++.h>
using namespace std;
  int main(){
int n;
cin >>n;
vector<int>vec(n);
for(int i=0;i<n;i++){
cin >> vec.at(i);}
  double kouho=0;
  for(int i=0;i<n;i++){
  kouho+=vec.at(i);}
  kouho/=n;
  double thumb=10005;
    int ans=-1;
  for(int i=0;i<n;i++){
    if(abs(kouho-vec.at(i))<thumb){
    thumb=abs(kouho-vec.at(i));
    ans=i;}
  }
  cout << ans <<endl;
}