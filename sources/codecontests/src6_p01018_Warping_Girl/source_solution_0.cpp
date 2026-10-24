#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <deque>
#include <bitset>
#include <list>
#include <cctype>
#include <utility>
 
using namespace std;
 
typedef long long ll;
 
const static int tx[] = {+0,+1,+0,-1};
const static int ty[] = {-1,+0,+1,+0};
 
static const double EPS = 1e-12;

class MagicalCircle{
public:
  int pos;
  int dist;
  int time;
  MagicalCircle(int _p,int _d,int _t) : pos(_p),dist(_d),time(_t){}
  bool operator<(const MagicalCircle& m) const{
    return pos < m.pos;
  }
  bool operator>(const MagicalCircle& m) const{
    return pos > m.pos;
  }
  bool operator<(const int num) const{
    return pos < num;
  }
  bool operator>(const int num) const{
    return pos > num;
  }
};

class State{
public:
  int pos;
  int time;
  State(int _p,int _t) : pos(_p),time(_t){}
  bool operator<(const State& s) const{
    return time < s.time;
  }
  bool operator>(const State& s) const{
    return time > s.time;
  }
};

int main(){
  int distance;
  int total_magical_circles;
  while(~scanf("%d %d",&distance,&total_magical_circles)){

    vector<MagicalCircle> magical_circles;
    for(int circle_idx=0;circle_idx<total_magical_circles;circle_idx++){
      int pos;
      int dist;
      int time;
      scanf("%d %d %d",&pos,&dist,&time);
      magical_circles.push_back(MagicalCircle(pos,dist,time));
    }

    magical_circles.push_back(MagicalCircle(distance,0,0));
    sort(magical_circles.begin(),magical_circles.end());

    priority_queue<State,vector<State>,greater<State> > que;
    que.push(State(0,0));

    map<int,int> dp;
    while(!que.empty()){
      State s = que.top();
      que.pop();

      if(dp.find(s.pos) != dp.end()) continue;
      dp[s.pos] = s.time;

      int idx = lower_bound(magical_circles.begin(),magical_circles.end(),s.pos) - magical_circles.begin();

      if(magical_circles[idx].pos == s.pos){
	//use
	int next_time = s.time + magical_circles[idx].time;
	int next_pos = s.pos + magical_circles[idx].dist;
	que.push(State(next_pos,next_time));

	//un-use
	int next_time2 = s.time + 1;
	int next_pos2 = s.pos + 1;
	que.push(State(next_pos2,next_time2));
      }
      else{
	//just move
	int next_time = s.time + (magical_circles[idx].pos - s.pos);
	int next_pos = magical_circles[idx].pos;
	que.push(State(next_pos,next_time));
      }
    }

    printf("%d\n",dp[distance]);
  }
}
