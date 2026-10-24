#include<iostream>

using namespace std;

int n, a[100009];

int Partition(int p, int r){
  int x=a[r];
  int i=p-1;
  for(int j=p;j<r;j++){
    if(a[j]<=x){
      i++;
      swap(a[i], a[j]);
    }
  }
  swap(a[i+1], a[r]);
  return i+1;
}

int main(){
  cin >> n;
  for(int i=0;i<n;i++)cin >> a[i];
  int idx = Partition(0, n-1);
  for(int i=0;i<n;i++){
    if(i==idx)cout << '[';
    cout << a[i];
    if(i==idx)cout << ']';
    cout << (i<n-1?' ': '\n');
  }
}
