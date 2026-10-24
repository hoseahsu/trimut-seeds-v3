#include <stdio.h>
#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
    int n;
    string str;
    cin >> n;
    cin.ignore();
    while(n--) {
        getline(cin, str);
        int num;
        while(num = str.find("Hoshino"), num != -1) {
            str[num + 6] = 'a';
        }
        cout << str << endl;
    }
    return 0;
}