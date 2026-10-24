#include <bits/stdc++.h>
class raw_input {
 public:
  template <typename T>
  raw_input& operator>>(T& arg) {
    if constexpr (std::is_integral<T>::value) {
      if constexpr (sizeof(T) == sizeof(int)) {
        scanf("%d", &arg);
      } else {
        scanf("%lld", &arg);
      }
    }
    if constexpr (std::is_floating_point<T>::value) {
      if constexpr (sizeof(T) == sizeof(double)) {
        scanf("%lf", &arg);
      } else {
        scanf("%LF", &arg);
      }
    }
    return *this;
  }
  raw_input& operator>>(char* arg) {
    scanf("%s", arg);
    return *this;
  }
  raw_input& operator>>(char& c) {
    while ((c = getchar()) != EOF && (c == ' ' || c == '\n'))
      ;
    return *this;
  }
} gin{};
using namespace std;
struct engine {
  bool used = false;
  int l, r;
  int mmim;
  int mumm;
  engine() {}
  void set(int l_, int r_) {
    l = l_;
    r = r_;
    mumm = 0;
    mmim = 0;
    used = true;
  }
  void update(int hmm) { mmim = max(mmim, hmm); }
  int get() { return l; }
  int how() {
    int mine = max(0, r - mmim);
    return min(r - l, mine);
  }
  void increment(int v) {
    mmim += v;
    l += v;
  }
} e{};
int a[100005];
int main() {
  int n, d;
  gin >> n >> d;
  for (int i = (0); i <= (n - 1); ++i) gin >> a[i];
  long long prev = 0;
  int ans = 0;
  for (int i = (0); i <= (n - 1); ++i) {
    prev += a[i];
    if (e.used && prev > d) {
      cout << -1 << endl;
      return 0;
    }
    if (e.used == false && prev > d) {
      cout << -1 << endl;
      return 0;
    }
    if (a[i] == 0 && prev < 0) {
      if (e.used) {
        int inc = e.how();
        if (inc + prev >= 0) {
          int mmim = min(abs(prev), 1LL * inc);
          e.increment(mmim);
          prev += mmim;
        } else {
          ++ans;
          e.set(0, d);
          prev = 0;
        }
      } else {
        e.set(0, d);
        prev = 0;
        ++ans;
      }
    }
    e.update(prev);
  }
  cout << ans << endl;
  return 0;
}
