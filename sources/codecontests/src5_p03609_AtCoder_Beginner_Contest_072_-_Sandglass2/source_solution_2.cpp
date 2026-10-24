#include<iostream>
int main(){
    int X, t;
    std::cin >> X >> t;
    std::cout << (t > X ? 0 : X - t);
}