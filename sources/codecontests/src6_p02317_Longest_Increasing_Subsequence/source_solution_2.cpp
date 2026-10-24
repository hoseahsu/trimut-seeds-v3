#include <iostream>
#include <algorithm>
#define MAX 100005
using namespace std;
int n,a[MAX],L[MAX];

int lis() {
    L[0] = a[0];
    int length = 1;
    for(int i=1;i<n;i++) {
        if(L[length-1] < a[i])  L[length++] = a[i];
        else                    *lower_bound(L,L+length,a[i]) = a[i];
    }
    return length;
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    cout << lis() << endl;
    return 0;
}

