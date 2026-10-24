#include <bits/stdc++.h>
int Recursively(int l1, int r1, int l2, int r2, int step) {
  if (r1 < l1 || r2 < l2) {
    return 0;
  } else if (r1 == r2) {
    return r1 - std::max(l1, l2) + 1;
  } else if (l1 == l2) {
    return std::min(r1, r2) - l1 + 1;
  } else if (step == 1) {
    return 1;
  } else {
    int mid = (1 << (step - 1));
    int result = 0;
    if (l1 <= mid && l2 <= mid && r1 >= mid && r2 >= mid) {
      result = std::min(r1, r2) - std::max(l1, l2) + 1;
      if ((l1 <= l2 && r1 >= r2) || (l2 <= l1 && r2 >= r1)) {
        return result;
      }
    }
    if (l1 < mid && r2 > mid) {
      result = std::max(
          result, Recursively(l1, std::min(mid - 1, r1),
                              std::max(mid + 1, l2) - mid, r2 - mid, step - 1));
    }
    if (l2 < mid && r1 > mid) {
      result = std::max(
          result, Recursively(l2, std::min(mid - 1, r2),
                              std::max(mid + 1, l1) - mid, r1 - mid, step - 1));
    }
    if (l1 < mid && l2 < mid) {
      result = std::max(result, Recursively(l1, std::min(mid - 1, r1), l2,
                                            std::min(mid - 1, r2), step - 1));
    }
    if (r1 > mid && r2 > mid) {
      result = std::max(
          result, Recursively(std::max(mid + 1, l1) - mid, r1 - mid,
                              std::max(mid + 1, l2) - mid, r2 - mid, step - 1));
    }
    return result;
  }
}
int main() {
  int l1, r1, l2, r2;
  std::cin >> l1 >> r1 >> l2 >> r2;
  std::cout << Recursively(l1, r1, l2, r2, 30);
  return 0;
}
