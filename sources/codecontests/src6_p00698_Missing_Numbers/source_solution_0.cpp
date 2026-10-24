#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

#define EPS (1e-8)

const int q = -999999999;

typedef long long ll;

typedef vector<ll> vec;
typedef vector<vec> mat;

vec gauss_jordan(mat& A, vec& b) {
  int n = A.size();
  mat B(n, vec(n+1));
  rep(i, n) rep(j, n) B[i][j] = A[i][j];
  rep(i, n) B[i][n] = b[i];

  rep(i, n) {
    int pivot = i;
    REP(j, i, n) {
      if(abs(B[j][i]) > abs(B[pivot][i])) pivot = j;
    }
    swap(B[i], B[pivot]);

    if(abs(B[i][i]) < EPS) return vec();

    REP(j, i+1, n+1) B[i][j] /= B[i][i];
    rep(j, n) {
      if(i != j) {
        REP(k, i+1, n+1) B[j][k] -= B[j][i] * B[i][k];
      }
    }
  }

  vec x(n);
  rep(i, n) x[i] = B[i][n];
  return x;
}

int N, M;
mat in;
vector<pair<int, int>> qpos;

#define fail { cout << "NO\n"; goto next; }

int main() {

  bool first = 0;
  while(cin >> N >> M && N) {
    if(first) cout << endl;
    first = 1;
    bool remain = 0;
    in.clear(); in.resize(N + 1); rep(i, N + 1) in[i].resize(M + 1);
    qpos.clear();
    rep(i, N + 1) rep(j, M + 1) {
      string s; cin >> s;
      if(s == "?") in[i][j] = q, qpos.emplace_back(i, j);
      else in[i][j] = stoi(s);
    }

    rep(_, (N + 1) * (M + 1) + 10) {
    {
      rep(i, N + 1) {
        int xcnt = 0;
        ll sum = 0;
        int lastq = -1;
        rep(j, M) {
          if(in[i][j] == q) xcnt ++, lastq = j;
          else sum += in[i][j];
        }
        if(xcnt == 0) {
          if(in[i][M] == q) in[i][M] = sum;
          else if(in[i][M] != sum) fail;
        }
        else if(xcnt == 1) {
          if(in[i][M] == q) {}
          else in[i][lastq] = in[i][M] - sum;
        }
        else {}
      }
    }

    {
      rep(j, M + 1) {
        int xcnt = 0;
        ll sum = 0;
        int lastq = -1;
        rep(i, N) {
          if(in[i][j] == q) xcnt ++, lastq = i;
          else sum += in[i][j];
        }
        if(xcnt == 0) {
          if(in[N][j] == q) in[N][j] = sum;
          else if(in[N][j] != sum) fail;
        }
        else if(xcnt == 1) {
          if(in[N][j] == q) {}
          else in[lastq][j] = in[N][j] - sum;
        }
        else {}
      }
    }}

    rep(i, N + 1) rep(j, M + 1) {
      remain |= in[i][j] == q;
    }

    if(remain) fail;

    for(auto e: qpos) {
      cout << in[e.first][e.second] << endl;
    }

  next:;
  }
  
  return 0;
}