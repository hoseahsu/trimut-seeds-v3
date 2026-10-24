#include <cstdio>
#include <algorithm>
using namespace std;

const int A=0,B=99;



int rec(char *s,int &i,int a,int b,bool t,bool &f)
{
  int ret;
  if(s[i]=='_'){
    i+=2;
    int x=rec(s,i,a,-1,0,f);
    if(f){
      return x;
    }
    i++;
    int b2=(t?x:-1);
    if(x>=b&&(b2==-1||b2>=b)){
      b2=b;
    }
    int y=rec(s,i,a,b2,t,f);
    if(f){
      return min(x,y);
    }
    ret=min(x,y);
    i++;
  }
  else if(s[i]=='^'){
    i+=2;
    int x=rec(s,i,-1,b,0,f);
    if(f){
      return x;
    }
    i++;
    int a2=(t?x:-1);
    if(x<=a&&(a2==-1||a2<=a)){
      a2=a;
    }
    int y=rec(s,i,a2,b,t,f);
    if(f){
      return max(x,y);
    }
    ret=max(x,y);
    i++;
  }
  else{
    int k=s[i]-'0';
    i++;
    if(t&&k==0){
      f=1;
      return k;
    }
    if(a!=-1&&(k>0?10*k+9:0)<=a){
      f=1;
      return k;
    }
    if(b!=-1&&k>=b){
      f=1;
      return k;
    }
    int x,p;
    if('0'<=s[i]&&s[i]<='9'){
      x=10*k+(s[i]-'0');
      i++;
      p=0;
    }
    else{
      x=k;
      p=1;
    }
    if(t||(a!=-1&&x<=a)||(b!=-1&&x>=b)){
      f=1;
      i+=p;
      return x;
    }
    ret=x;
  }
  return ret;
}

int main()
{
  int q;
  scanf("%d",&q);
  while(q--){
    char s[1001];
    scanf("%s",s);
    int i=0;
    bool f=0;
    int x=rec(s,i,A,B,1,f);
    printf("%d %d\n",x,i);
  }
  return 0;
}
