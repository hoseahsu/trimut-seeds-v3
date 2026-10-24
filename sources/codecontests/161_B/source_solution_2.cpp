#include <bits/stdc++.h>
using namespace std;
struct sort_pred {
  bool operator()(const std::pair<int, int> &left,
                  const std::pair<int, int> &right) {
    return left.first > right.first;
  }
};
int main() {
  int n, k;
  cin >> n >> k;
  int num = n / k;
  int cart = 1;
  vector<pair<int, int> > one, rest;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (b == 1)
      one.push_back(pair<int, int>(a, i + 1));
    else
      rest.push_back(pair<int, int>(a, i + 1));
  }
  std::sort(one.begin(), one.end(), sort_pred());
  int i;
  double tcost = 0;
  for (i = 0; i < min(k - 1, (int)one.size()); i++) {
    pair<int, int> t = one[i];
    tcost += t.first / 2.0;
    ans.push_back(t.second);
  }
  vector<int> final;
  if (i < one.size()) {
    int m = (int)1e9;
    while (i < one.size()) {
      pair<int, int> t = one[i];
      tcost += t.first;
      m = min(m, t.first);
      final.push_back(t.second);
      i++;
    }
    i = 0;
    while (i < rest.size()) {
      pair<int, int> t = rest[i];
      tcost += t.first;
      m = min(m, t.first);
      final.push_back(t.second);
      i++;
    }
    tcost = tcost - m / 2.0;
  } else {
    int j = 0;
    for (i; i < k - 1; i++) {
      pair<int, int> t = rest[j];
      tcost += t.first;
      ans.push_back(t.second);
      j++;
    }
    for (j; j < rest.size(); j++) {
      pair<int, int> t = rest[j];
      tcost += t.first;
      final.push_back(t.second);
    }
  }
  printf("%.1f\n", tcost);
  for (i = 0; i < ans.size(); i++) {
    cout << 1 << " " << ans[i] << endl;
  }
  cout << final.size() << " ";
  for (i = 0; i < final.size(); i++) {
    cout << final[i] << " ";
  }
}
