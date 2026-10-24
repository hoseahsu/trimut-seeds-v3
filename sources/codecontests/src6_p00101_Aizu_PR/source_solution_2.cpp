#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n;cin.ignore();

    while(n--){
        getline(cin,s);
        char a[1000];
        strcpy(a,s.c_str());
        int len=strlen(a);
        for(int i=0;i<len-6;i++){
            if(!strncmp(a+i,"Hoshino",7))strncpy(a+i,"Hoshina",7);
        }
        cout<<a<<endl;
    }
    return 0;
}