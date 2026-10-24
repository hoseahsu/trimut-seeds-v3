#include<iostream>
using namespace std;

int main() {
  long N, K; cin >> N >> K;
  cout << min( N % K, K - (N % K) ) << endl;
}