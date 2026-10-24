#import<iostream>
int main(){int a=0,b;for(std::cin>>b;std::cin>>b;)a|=b;std::cout<<__builtin_ctz(a);}