#include <iostream>
using namespace std;

int c;

int seisu_1(int n){
    if(0<=n && n<10) return c;
    if(n == (n/10)*(n%10)) return -1;
    else{    
    int nmax=(n/10)*(n%10), m;
    for(int j=10; j<=n; j*=10){
        m = (n/j)*(n%j);
        if(nmax<m)  nmax = m;
    }
    c++;
    return seisu_1(nmax);
    }
}


int main(void){
    int Q, n;
    cin >> Q;
    for(int i=1; i<=Q; i++){
        c = 0;
        cin >> n;
        cout << seisu_1(n) << endl;
    }
    
    return 0;
}
