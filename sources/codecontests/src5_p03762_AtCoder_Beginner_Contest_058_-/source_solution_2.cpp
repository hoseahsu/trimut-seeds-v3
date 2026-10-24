#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int main()
{
 int n, m;
 cin >> n >> m;
 long long x[n], y[m], xi[n-1], yi[m-1];
 long long xsum=0, ysum=0;
 for(int i=0; i<n; i++) cin >> x[i];
 for(int i=0; i<m; i++) cin >> y[i];
 for(int i=0; i<n-1; i++) xi[i]=x[i+1]-x[i];
 for(int i=0; i<m-1; i++) yi[i]=y[i+1]-y[i];
 for(int i=0; i<n-1; i++){
   xsum=(xsum+xi[i]*(i+1)*(n-i-1))%1000000007;
 }
 for(int i=0; i<m-1; i++){
   ysum=(ysum+yi[i]*(i+1)*(m-i-1))%1000000007;
 }
 cout<< (xsum*ysum)%1000000007;
  return 0;
}