#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k,s;
  cin >> n >> k >> s;
  for(int i=0;i<k;i++) cout << s << ' ';
  if(s!=1) s--;
  else s++;
  for(int i=k;i<n;i++) cout << s <<' ';
}
