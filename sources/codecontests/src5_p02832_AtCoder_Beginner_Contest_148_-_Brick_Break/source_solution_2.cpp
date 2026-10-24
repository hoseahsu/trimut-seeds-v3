#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;

int main(){
  int i,c=0,n=1,N;
  cin>>N;
  vi A(N);
  for(i=0;i<N;i++){
    cin>>A[i];
    if(A[i]==n)n++;
    else c++;
  }
  if(n==1)c=-1;
  cout<<c<<endl;
}
