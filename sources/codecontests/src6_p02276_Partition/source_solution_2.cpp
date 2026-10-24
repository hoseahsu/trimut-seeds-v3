#include <iostream>
using namespace std;

int partition(int *A,int p,int r){
  int x,i,t;
  x=A[r];
  i=p-1;
  
  for (int j=p;j<r;j++){
    if (A[j]<=x){
      i++;
      t=A[i];
      A[i]=A[j];
      A[j]=t;
    }
  }

  t=A[i+1];
  A[i+1]=A[r];
  A[r]=t;

  return i+1;
}

int main(){
  int i,n,A[100005],q;

  cin >> n;
  for(i=0;i<n;i++)
    cin >> A[i];

  q=partition(A,0,n-1);

  for (i=0;i<q;i++)
    cout << A[i] << " ";
  
  cout << "[" << A[q] << "]";
  
  for (i=q+1;i<n;i++)
    cout << " " << A[i];
  
  cout << endl;
  
  return 0;
}