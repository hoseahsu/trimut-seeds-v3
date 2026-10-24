#include<bits/stdc++.h>

using namespace std;

int main(){

int n;
cin>>n;
map<string,int>judge;
string qtr[4]={"AC","WA","TLE","RE"};
for(int i = 0 ; i < n ; i++ ){
    string str;
    cin>>str;
    judge[str]++;

}
for(int i = 0;i<4;i++){
     cout<<qtr[i]<<" x "<<judge[qtr[i]]<<endl;
}



return 0;
}
