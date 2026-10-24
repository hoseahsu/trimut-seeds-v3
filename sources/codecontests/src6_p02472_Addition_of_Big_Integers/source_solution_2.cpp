#include <iostream>
#include <algorithm>
using namespace std;
//S
struct BigInt{
  string val;
  BigInt():val("0"){}
  BigInt(string s){
    bool firstdigit = false;
    for(int i = 0; s.size() > i; i++){
      if('0' <= s[i] && s[i] <= '9'){
        if(!firstdigit && s[i] == '0')continue;
        firstdigit = true;
        val.push_back(s[i]);
      }else if(s[i] == '-' && val.empty()){
        val.push_back(s[i]);
      }else{
        val = "0";
        break;
      }
    }
  }
  BigInt abs(BigInt p){
    if(p.val[0] == '-'){
      p.val = p.val.substr(1,p.val.size()-1);
    }
    return p;
  }
  BigInt SignTurn(BigInt p){
    if(p.val[0] == '-'){
      p.val = p.val.substr(1,p.val.size()-1);
    }else{
      p.val = "-" + p.val;
    }
    return p;
  }
  BigInt max(BigInt a,BigInt b){
    if(a.val.size() > b.val.size()){
      return a;
    }else if(a.val.size() < b.val.size()){
      return b;
    }else{
      for(int i = 0; a.val.size()> i; i++){
        if(a.val[i] > b.val[i]){
          return a;
        }
        if(a.val[i] < b.val[i]){
          return b;
        }
      }
    }
    return a;
  }

  BigInt operator+=(const BigInt &p){
    BigInt z = *this;
    BigInt k = p;
    if(z.val[0] == '-' && p.val[0] == '-'){
      return  SignTurn(abs(z)+abs(k));//(-123)+(-124) -> -((123)+(124))
    }else if(z.val[0] == '-'){
      return k-abs(z);//(-123)+(124) -> (124)-(123)
    }else if(p.val[0] == '-'){
      return (z)-abs(k);//(123)+(-124) -> (123)-(124)
    }else{
      //123 + 1234
      bool Mvup = false;
      string ret = "";
      if(z.val.size() < k.val.size()){
        swap(z,k);
      }
      //val.size() > k.val.size();
      for(int i = z.val.size()-1; 0 <= i; i--){
        if(z.val.size()-k.val.size() > i){
          //val[i]+Mvup
          ret.push_back(((z.val[i]-'0'+(Mvup?1:0))%10)+'0');
          Mvup = ((z.val[i]-'0'+(Mvup?1:0))>=10);
        }else{
          //val[i],k.val[i-(val.size()-k.val.size())]+Mvup
          ret.push_back(((z.val[i]-'0'+k.val[i-(z.val.size()-k.val.size())]-'0'+(Mvup?1:0))%10)+'0');
          Mvup = ((z.val[i]-'0'+k.val[i-(z.val.size()-k.val.size())]-'0'+(Mvup?1:0)) >= 10);
        }
      }
      if(Mvup)ret.push_back('1');
      reverse(ret.begin(),ret.end());
      if(ret.empty())ret.push_back('0');
      z.val = ret;
    }
    return z;

  }
  BigInt operator-=(const BigInt &p){
    BigInt z = *this;
    BigInt k = p;
    if(z.val[0] == '-' && k.val[0] == '-'){
      return (z)+abs(k);//(-123)-(-123) -> (-123)+(123)
    }else if(z.val[0] == '-'){
      return (z)+SignTurn(k);//(-123)-(123) -> (-123)+(-123)
    }else if(k.val[0] == '-'){
      return abs(k)+(z);//(123)-(-123) -> (123)+(123)
    }else{
      string ret = "";
      //z >= k
      bool Mvdwn = false;
      bool minus = false;
      if(max((z),k) != z){
        minus = true;
        swap(z,k);
      }
      for(int i = z.val.size()-1; 0 <= i; i--){
        if(z.val.size() - k.val.size() > i){
          if(z.val[i]-'0' < (Mvdwn?1:0)){
            ret.push_back(10+z.val[i]-(Mvdwn?1:0));
            Mvdwn = true;
          }else{
            ret.push_back(z.val[i]-(Mvdwn?1:0));
            Mvdwn = false;
          }
        }else{
          if(z.val[i] < k.val[i-(z.val.size()-k.val.size())]+(Mvdwn?1:0)){
            ret.push_back(10+z.val[i]-(k.val[i-(z.val.size()-k.val.size())]+(Mvdwn?1:0)) + '0');
            Mvdwn = true;
          }else{
            ret.push_back(z.val[i]- (k.val[i-(z.val.size()-k.val.size())]+(Mvdwn?1:0)) + '0');
            Mvdwn = false;
          }
        }
      }
      while(ret[ret.size()-1] == '0' && ret.size() > 1)ret.pop_back();
      if(minus)ret.push_back('-');
      reverse(ret.begin(),ret.end());
      z.val = ret;
    }
    return z;
  }
  BigInt operator+(const BigInt &p){return (*this) += p;}
  BigInt operator-(const BigInt &p){return (*this) -= p;}

  bool operator==(const BigInt &p){return val == p.val;}
  bool operator!=(const BigInt &p){return val != p.val;}

  friend ostream &operator<<(ostream &os, const BigInt &p){
    return os << p.val;
  }
};



//E

int main(){
  string A,B;cin>>A>>B;//TODO:標準入力で読み込ませることができるようにする?

  BigInt a = A;
  BigInt b = B;
  //cout << a << " " << b << endl;
  //cout << a.abs() << " " << b.abs() << endl;
  cout << a+b << endl;
}
