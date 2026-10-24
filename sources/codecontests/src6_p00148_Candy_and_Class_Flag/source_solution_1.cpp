#include <iostream>
#include <iomanip>
using namespace std;


int main(int argc, const char * argv[]) {
    
    int n;
    while (cin >> n) {
        
        cout << "3C"  << setfill('0') << setw(2) << ((n % 39 == 0) ? 39 : n % 39) << endl;
        
    }
    
    return 0;
}