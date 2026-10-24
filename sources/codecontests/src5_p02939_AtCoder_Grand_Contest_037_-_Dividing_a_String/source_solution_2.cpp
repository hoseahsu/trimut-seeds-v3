#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  string s;
   cin>>s;
   int ans=s.size();
   for(int i=0;i<s.size();i++){
       if(s[i]==s[i+1]){
           ans--;
           i+=2;
       }
   }
   cout<<ans<<endl;
  return 0;
}
