#include <iostream>
#include <vector>
using namespace std;

vector<int> sieve(int n) {
  vector<int> prime(n);
  for(int i=2; i<n; i++) prime[i]=i;
  for(int i=2; i*i<n; i++) {
    if(prime[i]) {
      for(int j=i*i; j<n; j+=i) prime[j]=0;
    }
  }
  return prime;
}

int main() {
  vector<int> prime=sieve(1000000);
  int a,b,n;
  while(cin >> a >> b >> n) {
    if(a==0 && b==0 && n==0) break;
    while(n) {
      if(prime[a]!=0) n--;
      a+=b;
    }
    cout << a-b << endl;
  }
  return 0;
}
