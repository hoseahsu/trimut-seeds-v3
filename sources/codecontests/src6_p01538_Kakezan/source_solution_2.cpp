#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int q;
    cin >> q;
    while( q-- ){
        int count = 0;
        int n;
        cin >> n;
        while( n >= 10 ){
            int d = 0;
            int max = 0;
            while( d++ < 6){
                int a, b;
                a = n / pow( 10, d );
                b = n % (int)pow( 10, d );
                if( max < a * b ) max = a * b;
            }
            count++;
            n = max;
        }
        cout << count << endl;
    }
}