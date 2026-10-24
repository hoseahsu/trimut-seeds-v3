#include <bits/stdc++.h>
using namespace std;
template <class T>
T f_min(T x, T y) {
  return x < y ? x : y;
}
template <class T>
T f_max(T x, T y) {
  return x > y ? x : y;
}
template <class T>
T f_abs(T x) {
  return x < 0 ? -x : x;
}
char A[200005], B[200005];
int al, bl;
int S[200005], E[200005];
struct Node {
  int s, e;
  bool v[130];
};
Node node[800000];
void build_tree(int loc, int s, int e) {
  node[loc].s = s;
  node[loc].e = e;
  memset(node[loc].v, 0, sizeof node[loc].v);
  if (s == e) return;
  int mid = (s + e) >> 1;
  build_tree(loc << 1, s, mid);
  build_tree(loc << 1 | 1, mid + 1, e);
}
void insert(int loc, int s, int e, int a) {
  if (node[loc].s == s && node[loc].e == e) {
    node[loc].v[a] = 1;
    return;
  }
  int mid = (node[loc].s + node[loc].e) >> 1;
  if (e <= mid)
    insert(loc << 1, s, e, a);
  else if (s > mid)
    insert(loc << 1 | 1, s, e, a);
  else
    insert(loc << 1, s, mid, a), insert(loc << 1 | 1, mid + 1, e, a);
}
bool query(int loc, int s, int a) {
  if (node[loc].v[a]) return 1;
  if (node[loc].s == node[loc].e) return 0;
  int mid = (node[loc].s + node[loc].e) >> 1;
  if (s <= mid)
    return query(loc << 1, s, a);
  else
    return query(loc << 1 | 1, s, a);
}
void get_data() {
  scanf("%s%s", A, B);
  al = strlen(A);
  bl = strlen(B);
}
bool get_S() {
  int i, j;
  for (i = j = 0; j < bl; j++, i++) {
    for (; i < al && A[i] != B[j]; i++)
      ;
    if (i == al) return 0;
    S[j] = i;
  }
  return 1;
}
bool get_E() {
  int i, j;
  for (i = al - 1, j = bl - 1; j >= 0; j--, i--) {
    for (; i >= 0 && A[i] != B[j]; i--)
      ;
    if (i == -1) return 0;
    E[j] = i;
  }
  return 1;
}
void run() {
  if (bl > al) {
    printf("No\n");
    return;
  }
  if (!get_S() || !get_E()) {
    printf("No\n");
    return;
  }
  build_tree(1, 0, al - 1);
  int i, s, e;
  for (i = 0; i < bl; i++) {
    if (!i)
      s = 0;
    else
      s = S[i - 1] + 1;
    if (i == bl - 1)
      e = al - 1;
    else
      e = E[i + 1] - 1;
    if (s <= e) {
      insert(1, s, e, B[i]);
    }
  }
  for (i = 0; i < al; i++) {
    if (!query(1, i, A[i])) break;
  }
  if (i < al)
    printf("No\n");
  else
    printf("Yes\n");
}
int main() {
  get_data();
  run();
  return 0;
}
