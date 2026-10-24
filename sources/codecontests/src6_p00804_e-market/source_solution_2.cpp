#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#include<set>
#include<sstream>
#include<climits>
#include<numeric>
using namespace std;
#define REP(i, j) for(int i = 0; i < j; i++)
#define FOR(i, j, k) for(int i = j; i < k; i++)
const int INF = INT_MAX;

class Order{
  public:
    string name, type, item;
    int price;
    Order(string _n, string _t, string _i, int _p){
      name = _n;
      type = _t;
      item = _i;
      price = _p;
    }
    string to_string(){
      stringstream ss;
      ss <<name <<" " <<type <<" " <<item <<" " <<price;
      return ss.str();
    }
};

class Item{
  public:
    string name;
    int min, max;
    vector<int> all_price;
    Item(string _n, int _min, int _max, vector<int> _a){
      name = _n;
      min = _min;
      max = _max;
      all_price = _a;
    }
    string to_string(){
      stringstream ss;
      int ave = all_price.size() == 0? 0 : (int)(floor(accumulate(all_price.begin(), all_price.end(), 0.0) / all_price.size()));
      ss <<name <<" " <<min <<" " <<ave <<" " <<max;
      return ss.str();
    }
    bool operator <(const Item i) const{
      return name < i.name;
    }
};

class User{
  public:
    string name;
    int buy, sell;
    User(string _n, int _b, int _s){
      name = _n;
      buy = _b;
      sell = _s;
    }
    string to_string(){
      stringstream ss;
      ss <<name <<" " <<buy <<" " <<sell;
      return ss.str();
    }
    void cal(int p, string type){
      if(type == "BUY") buy += p;
      else if(type == "SELL") sell += p;
    }
    bool operator <(const User i) const{
      return name < i.name;
    }
};

int main(){
  int num;
  while(cin >>num && num){
    vector<Order> ov;
    vector<Item> iv;
    vector<User> uv;
    set<string> item_name, user_name;
    REP(i, num){
      string n, t, it;
      int p;
      cin >>n >>t >>it >>p;
      ov.push_back( Order(n, t, it, p) );
      if(item_name.find(it) == item_name.end()){
        item_name.insert(it);
        iv.push_back(Item(it, INF, -1, vector<int>()));
      }
      if(user_name.find(n) == user_name.end()){
        user_name.insert(n);
        uv.push_back( User(n, 0, 0) );
      }
    }
    sort(iv.begin(), iv.end());
    sort(uv.begin(), uv.end());

    //debug
    //REP(i, ov.size()) cout <<ov[i].to_string() <<endl; cout <<endl;
    //REP(i, iv.size()) cout <<iv[i].to_string() <<endl; cout <<endl;
    //REP(i, uv.size()) cout <<uv[i].to_string() <<endl; cout <<endl;

    vector<bool> is_end(ov.size(), false);
    REP(i, ov.size()){
      string p_type = ov[i].type == "BUY"? "SELL" : "BUY";
      int partner = -1, price = p_type == "BUY"? -1 : INF;

      for(int j = i - 1; j >= 0; --j){
        if(is_end[j] || ov[i].item != ov[j].item || ov[i].name == ov[j].name || ov[i].type == ov[j].type) continue;
        if((p_type == "SELL" && ov[i].price >= ov[j].price && ov[j].price <= price)
          || (p_type == "BUY" && ov[i].price <= ov[j].price && ov[j].price >= price)){
          partner = j;
          price = ov[j].price;
        }
      }
      //debug
      //cout <<partner <<", " <<price <<endl;

      if(partner == -1) continue;

      is_end[i] = true;
      is_end[partner] = true;
      int r_price = (int)(floor(((double)(ov[i].price) + ov[partner].price) / 2));
      REP(j, iv.size()){
        if(iv[j].name == ov[i].item){
          iv[j].max = max(iv[j].max, r_price);
          iv[j].min = min(iv[j].min, r_price);
          iv[j].all_price.push_back(r_price);
        }
      }
      REP(j, uv.size()){
        if(uv[j].name == ov[i].name) uv[j].cal(r_price, ov[i].type);
        if(uv[j].name == ov[partner].name) uv[j].cal(r_price, ov[partner].type);
      }
    }

    REP(i, iv.size()) if(iv[i].max != -1) cout <<iv[i].to_string() <<endl;
    cout <<"--" <<endl;
    REP(i, uv.size()) cout <<uv[i].to_string() <<endl;
    cout <<"----------" <<endl;
  }
  return 0;
}