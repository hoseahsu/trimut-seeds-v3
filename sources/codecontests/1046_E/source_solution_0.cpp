#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y, op, id;
} p[1100];
int multi(point p1, point p2, point p0) {
  int x1, y1, x2, y2;
  x1 = p1.x - p0.x;
  y1 = p1.y - p0.y;
  x2 = p2.x - p0.x;
  y2 = p2.y - p0.y;
  return x1 * y2 - x2 * y1;
}
bool cmp(point p1, point p2) { return multi(p1, p2, p[1]) > 0; }
int aslen, asx[1100], asy[1100];
void pb(int x, int y) {
  asx[++aslen] = x;
  asy[aslen] = y;
}
int n;
int top, sta[1100], insta[1100];
bool in_triangle(point p1, point p2, point p3, point p0) {
  int t1 = multi(p1, p0, p2);
  int t2 = multi(p2, p0, p3);
  int t3 = multi(p3, p0, p1);
  if ((t1 < 0 && t2 < 0 && t3 < 0) || (t1 > 0 && t2 > 0 && t3 > 0)) return true;
  return false;
}
void separate(point p1, point p2, point p3, int L, int R) {
  if (L > R) return;
  int k = -1;
  for (int i = L; i <= R; i++)
    if (p[i].op != p1.op) {
      k = R;
      if (insta[R] != 0) {
        insta[i] = insta[R];
        sta[insta[i]] = i;
        insta[R] = 0;
      }
      swap(p[R], p[i]);
      break;
    }
  pb(p3.id, p[k].id);
  int l = L, r = L - 1;
  bool bk = false;
  for (int i = l; i <= R; i++)
    if (i != k) {
      if (in_triangle(p1, p2, p[k], p[i])) {
        if (p[i].op != p1.op) bk = true;
        r++;
        if (insta[r] != 0) {
          insta[i] = insta[r];
          sta[insta[i]] = i;
          insta[r] = 0;
        }
        swap(p[r], p[i]);
      }
    }
  if (bk == false) {
    for (int i = l; i <= r; i++) {
      pb(p1.id, p[i].id);
      if (p1.op != p[i].op) printf("error 1\n");
    }
  } else
    separate(p1, p2, p[k], l, r);
  l = r + 1;
  bk = false;
  for (int i = l; i <= R; i++)
    if (i != k) {
      if (in_triangle(p1, p3, p[k], p[i])) {
        if (p[i].op != p3.op) bk = true;
        r++;
        if (insta[r] != 0) {
          insta[i] = insta[r];
          sta[insta[i]] = i;
          insta[r] = 0;
        }
        swap(p[r], p[i]);
      }
    }
  if (bk == false) {
    for (int i = l; i <= r; i++) {
      pb(p3.id, p[i].id);
      if (p3.op != p[i].op) printf("error 2\n");
    }
  } else
    separate(p3, p[k], p1, l, r);
  l = r + 1;
  bk = false;
  for (int i = l; i <= R; i++)
    if (i != k) {
      if (in_triangle(p2, p3, p[k], p[i])) {
        if (p[i].op != p3.op) bk = true;
        r++;
        if (insta[r] != 0) {
          insta[i] = insta[r];
          sta[insta[i]] = i;
          insta[r] = 0;
        }
        swap(p[r], p[i]);
      }
    }
  if (bk == false) {
    for (int i = l; i <= r; i++) {
      pb(p3.id, p[i].id);
      if (p3.op != p[i].op) printf("error 3\n");
    }
  } else
    separate(p3, p[k], p2, l, r);
}
void graham() {
  top = 0;
  sta[++top] = 1, sta[++top] = 2;
  memset(insta, 0, sizeof(insta));
  insta[1] = 1, insta[2] = 2;
  for (int i = 3; i <= n; i++) {
    while (top > 1 && multi(p[sta[top]], p[i], p[sta[top - 1]]) <= 0) {
      insta[sta[top]] = 0;
      top--;
    }
    sta[++top] = i;
    insta[sta[top]] = top;
  }
  int s = 0;
  for (int i = 2; i <= top; i++) s += (p[sta[i - 1]].op ^ p[sta[i]].op);
  s += (p[sta[1]].op ^ p[sta[top]].op);
  if (s > 2)
    printf("Impossible\n");
  else if (s == 0) {
    int cc = p[sta[1]].op, k = -1;
    for (int i = 1; i <= n; i++)
      if (insta[i] == 0 && p[i].op != cc) {
        k = n;
        if (insta[n] != 0) {
          insta[i] = insta[n];
          sta[insta[i]] = i;
          insta[n] = 0;
        }
        swap(p[n], p[i]);
        break;
      }
    int L = 1, R = 0;
    for (int i = 2; i <= top; i++) {
      pb(p[sta[i - 1]].id, p[sta[i]].id);
      bool bk = false;
      for (int j = L; j <= n; j++)
        if (insta[j] == 0 && j != k) {
          if (k == -1 || in_triangle(p[sta[i - 1]], p[sta[i]], p[k], p[j])) {
            if (p[j].op != cc) bk = true;
            R++;
            if (insta[R] != 0) {
              insta[j] = insta[R];
              sta[insta[j]] = j;
              insta[R] = 0;
            }
            swap(p[R], p[j]);
          }
        }
      if (bk == false) {
        for (int j = L; j <= R; j++) pb(p[sta[i]].id, p[j].id);
      } else
        separate(p[sta[i - 1]], p[sta[i]], p[k], L, R);
      L = R + 1;
    }
    bool bk = false;
    for (int j = L; j <= n; j++)
      if (insta[j] == 0 && j != k) {
        if (k == -1 || in_triangle(p[sta[top]], p[sta[1]], p[k], p[j])) {
          if (p[j].op != cc) bk = true;
          R++;
          if (insta[R] != 0) {
            insta[j] = insta[R];
            sta[insta[j]] = j;
            insta[R] = 0;
          }
          swap(p[R], p[j]);
        }
      }
    if (bk == false) {
      for (int j = L; j <= R; j++) pb(p[sta[top]].id, p[j].id);
    } else
      separate(p[sta[top]], p[sta[1]], p[k], L, R);
  } else {
    int be;
    bool bk = false;
    for (int i = 1; i <= top; i++)
      if (p[sta[i]].op == 0) {
        if (bk == false) be = i, bk = true;
      } else
        bk = false;
    int L = 1, R = 0;
    int i, k = (be - 1 + top - 1) % top + 1;
    for (i = be % top + 1; p[sta[i]].op == 0; i = i % top + 1) {
      int u = (i - 1 + top - 1) % top + 1;
      pb(p[sta[u]].id, p[sta[i]].id);
      bool bk = false;
      for (int j = L; j <= n; j++) {
        if (insta[j] == false &&
            in_triangle(p[sta[u]], p[sta[i]], p[sta[k]], p[j])) {
          if (p[j].op != 0) bk = true;
          R++;
          if (insta[R] != 0) {
            insta[j] = insta[R];
            sta[insta[j]] = j;
            insta[R] = 0;
          }
          swap(p[R], p[j]);
        }
      }
      if (bk == false) {
        for (int j = L; j <= R; j++) pb(p[sta[i]].id, p[j].id);
      } else
        separate(p[sta[u]], p[sta[i]], p[sta[k]], L, R);
      L = R + 1;
    }
    k = (i - 1 + top - 1) % top + 1;
    for (i = i % top + 1; i != be; i = i % top + 1) {
      int u = (i - 1 + top - 1) % top + 1;
      pb(p[sta[u]].id, p[sta[i]].id);
      bool bk = false;
      for (int j = L; j <= n; j++) {
        if (insta[j] == false &&
            in_triangle(p[sta[u]], p[sta[i]], p[sta[k]], p[j])) {
          if (p[j].op != 1) bk = true;
          R++;
          if (insta[R] != 0) {
            insta[j] = insta[R];
            sta[insta[j]] = j;
            insta[R] = 0;
          }
          swap(p[R], p[j]);
        }
      }
      if (bk == false) {
        for (int j = L; j <= R; j++) pb(p[sta[i]].id, p[j].id);
      } else
        separate(p[sta[u]], p[sta[i]], p[sta[k]], L, R);
      L = R + 1;
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].op), p[i].id = i - 1;
    if (p[i].y < p[1].y || (p[i].y == p[1].y && p[i].x < p[1].x))
      swap(p[i], p[1]);
  }
  if (n == 1) {
    printf("0\n");
    return 0;
  } else if (n == 2) {
    if (p[1].op == p[2].op)
      printf("1\n0 1\n");
    else
      printf("0\n");
    return 0;
  }
  sort(p + 2, p + n + 1, cmp);
  aslen = 0;
  graham();
  if (aslen != 0) {
    printf("%d\n", aslen);
    for (int i = 1; i <= aslen; i++) printf("%d %d\n", asx[i], asy[i]);
  }
  return 0;
}
