#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, x, m, mn = INT_MAX;
    cin>>n>>x;
    for(int i = 0;i<n;i++){
        cin>>m;
        x-=m;
        mn = min(mn, m);
    }
    cout<<x/mn+n<<"\n";
}