#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a,b,c;
    long long k;
    cin>>a>>b>>c>>k;
    cout<<(k%2==0?a-b:b-a)<<endl;
    return 0;
}