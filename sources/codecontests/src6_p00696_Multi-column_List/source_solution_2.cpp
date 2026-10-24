#include <bits/stdc++.h>
using namespace std;
char mp[100][2001];
int p,c,w,s;
int I,J;

void init(){
  I=J=0;
  memset(mp,'.',sizeof(mp));
  for(int i=0;i<p;i++)mp[i][c*w+(c-1)*s]='\0';
}

int Idx(int a){
  if(!a)return 0;
  return a*(s+w);
}

void write(string str){
  for(int i=0;i<(int)str.size();i++) mp[I][Idx(J)+i]=str[i];
  I++;

  if(I==p&&J>=c-1){
    for(int i=0;i<p;i++) printf("%s\n",mp[i]);
    cout<<"#"<<endl;
    init();
  }
  if(I==p)I=0,J++;

}


//p=tate, c=page , w=moji, s=space
int main(){
  
  while(1){
    cin>>p;
    if(!p)return 0;
    cin>>c>>w>>s;
    
    init();
    string str;
    getline(cin,str);

    while(1){
      getline(cin,str);
      if(str=="?")break;
      if(!str.size()){write("");continue;}

      string a="";
      for(int i=0;i<str.size();i++){
	a+=str[i];
	if((int)a.size()>=w)write(a),a="";
      }
      if(a.size())write(a);
    }
    if(I!=0||J!=0)I=p-1,J=c-1,write("");
    cout<<"?"<<endl;
  }

  return 0;
}