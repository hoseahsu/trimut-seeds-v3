#include <iostream>
using namespace std;
int main(void){
    long a,b,c,k;
    cin >> a >> b >> c >> k;
    cout << ((k % 2 == 0) ? a - b : b - a) << endl;
}
