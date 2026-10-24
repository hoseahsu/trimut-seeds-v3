#include <bits/stdc++.h>
using namespace std;
 
int main() {
long long a=0,b=0,c=0,d=0,m=0,n=0,p=0,q=0;

cin >> a;

vector<long long> x(a,0);

for(int i=0;i<a;i++)
{
cin >> x.at(i);
if(x.at(i)>b)
{
b=x.at(i);
}
if(x.at(i)<b)
{
c+=b-x.at(i);
}
}

cout << c;

}