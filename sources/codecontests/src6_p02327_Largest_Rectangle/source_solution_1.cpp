// C++ 14
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>
#include <math.h>

#define ll long long
#define Int int
#define loop(x, start, end) for(Int x = start; x < end; x++)
#define loopdown(x, start, end) for(int x = start; x > end; x--)
#define span(a,x,y) a.begin()+x,a.begin()+y
#define span_all(a) a.begin(),a.end()
#define len(x) (x.size())
#define last(x) (*(x.end()-1))

using namespace std;

#define MAX_H 1401
#define MAX_W 1401

Int H, W;
bool C[MAX_H][MAX_W];
Int HIST[MAX_H][MAX_W];

void input() {
  cin >> H >> W;
  loop(h,0,H) {
    loop(w,0,W) {
      cin >> C[h][w];
    }
  }
}

// O(N)
Int max_hist(Int hist[]) {
  stack<Int> S;
  Int max_ = 0, area = 0, tp = -1, width = 0;

  loop (i,0,W) {
    Int height = hist[i];

    // Pop every bar which is higher than me and calculate area for each of them.
    while (!S.empty() && hist[S.top()] > height) {
      tp = S.top();S.pop();

      width = S.empty() ? i : i - S.top() - 1;
      area = hist[tp] * width;
      if (max_ < area) max_ = area;
    }

    // Now bars are sorted in ascending order (greater or equal)
    S.push(i);
  }

  Int maxWidth = W;
  while (!S.empty()) {
    tp = S.top();S.pop();

    width = S.empty() ? maxWidth : maxWidth - S.top() - 1;
    area = hist[tp] * width;
    if (max_ < area) max_ = area;
  }

  return max_;
}

void solve() {
  loop(w,0,W) {
    HIST[0][w] = C[0][w] ? 0 : 1;
  }

  loop(w,0,W) {
    loop(h,1,H) {
      HIST[h][w] = C[h][w] ? 0 : HIST[h-1][w] + 1;
    }
  }

  Int max_ = 0;
  loop(h,0,H) {
    max_ = max(max_, max_hist(HIST[h]));
  }

  cout << max_ << endl;
}

int main(void) {
  input();
  solve();
}
