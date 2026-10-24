#include<iostream>
using namespace std;int main(){int n,k,sum=0;string s;cin>>n>>k>>s;for(int i=1;i<n;++i)sum+=s[i]==s[i-1];cout<<min(n-1,sum+2*k);return 0;}