#include <bits/stdc++.h>
using namespace std;
int arr[200000];
int cntr[500000];
bool state[200000];
vector<int> primes;
vector<int> factors[200000];
void sieve() {
  primes.push_back(2);
  for (int i = 3; i <= 500000 / i; ++i) {
    bool good = true;
    for (int j : primes) {
      good = good && (i % j);
    }
    if (good) {
      primes.push_back(i);
    }
  }
}
void factorize(int num, vector<int> &f) {
  for (int p : primes) {
    if (num > 1 && num % p == 0) {
      f.push_back(p);
      while (num > 1 && num % p == 0) {
        num /= p;
      }
    }
  }
  if (num > 1) {
    f.push_back(num);
  }
}
void modify(int idx, int val) {
  vector<int> &f = factors[idx];
  for (int msk = 1; msk < (1 << ((int)(f).size())); ++msk) {
    int p = 1;
    for (int i = 0; i < ((int)(f).size()); ++i) {
      if ((msk >> i) & 1) {
        p *= f[i];
      }
    }
    cntr[p] += val;
  }
}
int getUnion(int idx) {
  int ret = 0;
  vector<int> &f = factors[idx];
  for (int msk = 1; msk < (1 << ((int)(f).size())); ++msk) {
    int p = 1;
    for (int i = 0; i < ((int)(f).size()); ++i) {
      if ((msk >> i) & 1) {
        p *= f[i];
      }
    }
    if ((__builtin_popcount(msk)) & 1) {
      ret += cntr[p];
    } else {
      ret -= cntr[p];
    }
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  sieve();
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    factorize(arr[i], factors[i]);
  }
  int active = 0;
  long long ans = 0;
  while (q--) {
    int a;
    cin >> a, --a;
    if (state[a] == 0) {
      ans += active - getUnion(a);
      modify(a, 1);
      ++active;
    } else {
      --active;
      modify(a, -1);
      ans -= active - getUnion(a);
    }
    state[a] ^= 1;
    cout << ans << '\n';
  }
  return 0;
}
