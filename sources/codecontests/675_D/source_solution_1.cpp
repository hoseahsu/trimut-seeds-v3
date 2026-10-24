#include <bits/stdc++.h>
using namespace std;
const int MaxNodes = 2e5 + 2;
extern struct node nodes[MaxNodes];
enum DIR { LF, RI };
struct node {
  int val;
  int freq, par, Sz, ch[2];
  void set(int nodeValue) {
    ch[0] = ch[1] = par = 0;
    val = nodeValue;
    freq = Sz = 1;
  }
  void push_up() { Sz = freq + nodes[ch[LF]].Sz + nodes[ch[RI]].Sz; }
} nodes[MaxNodes];
int freeList[MaxNodes], freeListSz, nextNodeId;
int getFreeNodeId() {
  if (freeListSz) {
    return freeList[--freeListSz];
  }
  return nextNodeId++;
}
void init() {
  nextNodeId = 1;
  freeListSz = 0;
}
void makeFree(int nodeId) { freeList[freeListSz++] = nodeId; }
void link(int par, int child, DIR d) {
  if (par) {
    nodes[par].ch[d] = child;
    nodes[par].push_up();
  }
  if (child) {
    nodes[child].par = par;
  }
}
DIR getDir(int par, int child) { return (DIR)(nodes[par].ch[RI] == child); }
void rotate(int p, DIR d) {
  int gp = nodes[p].par;
  int q = nodes[p].ch[!d];
  link(p, nodes[q].ch[d], (DIR)(!d));
  link(q, p, d);
  link(gp, q, getDir(gp, p));
}
void splay(int nodeId, int &root) {
  while (nodes[nodeId].par) {
    int p = nodes[nodeId].par;
    int gp = nodes[p].par;
    int pd = getDir(p, nodeId);
    int gpd = getDir(gp, p);
    if (!gp) {
      rotate(p, (DIR)(!pd));
    } else if (pd == gpd) {
      rotate(gp, (DIR)(!gpd));
      rotate(p, (DIR)(!gpd));
    } else {
      rotate(p, (DIR)(!pd));
      rotate(gp, (DIR)(!gpd));
    }
  }
  root = nodeId;
}
void getNodeAt(int value, int &root) {
  while (value != nodes[root].val) {
    if (value < nodes[root].val) {
      if (nodes[root].ch[LF]) {
        root = nodes[root].ch[LF];
      } else {
        break;
      }
    } else {
      if (nodes[root].ch[RI]) {
        root = nodes[root].ch[RI];
      } else {
        break;
      }
    }
  }
  splay(root, root);
}
void insert(int &root, int value) {
  if (!root) {
    root = getFreeNodeId();
    nodes[root].set(value);
    return void();
  }
  getNodeAt(value, root);
  if (nodes[root].val == value) {
    nodes[root].freq++;
    nodes[root].Sz++;
  } else {
    DIR d = (DIR)(value > nodes[root].val);
    int id = getFreeNodeId();
    nodes[id].set(value);
    link(id, nodes[root].ch[d], d);
    link(root, 0, d);
    link(id, root, (DIR)(!d));
    root = id;
  }
}
int lb(int &root, int value) {
  if (!root) {
    return 0;
  }
  int ret = 0, cur;
  for (cur = root; nodes[cur].val != value;) {
    DIR d = (DIR)(value > nodes[cur].val);
    if (d) {
      ret += nodes[nodes[cur].ch[LF]].Sz + nodes[cur].freq;
    }
    if (nodes[cur].ch[d]) {
      cur = nodes[cur].ch[d];
    } else
      break;
  }
  if (value == nodes[cur].val) {
    ret += nodes[nodes[cur].ch[LF]].Sz;
  }
  splay(cur, root);
  return ret;
}
int ub(int &root, int value) { return lb(root, value + 1); }
int getByIdx(int &root, int index) {
  if (index >= nodes[root].Sz) {
    return INT_MIN;
  }
  int cur = root;
  while (nodes[nodes[cur].ch[LF]].Sz > index or
         index >= nodes[nodes[cur].ch[LF]].Sz + nodes[cur].freq) {
    if (nodes[nodes[cur].ch[LF]].Sz > index) {
      cur = nodes[cur].ch[LF];
    } else {
      index -= nodes[nodes[cur].ch[LF]].Sz + nodes[cur].freq;
      cur = nodes[cur].ch[RI];
    }
  }
  splay(cur, root);
  return nodes[cur].val;
}
void splayMax(int &root) {
  int cur;
  for (cur = root; nodes[cur].ch[RI]; cur = nodes[cur].ch[RI])
    ;
  splay(cur, root);
}
int merge(int ls, int gr) {
  if (!ls) return gr;
  splayMax(ls);
  link(ls, gr, RI);
  return ls;
}
void del(int &root, int value) {
  getNodeAt(value, root);
  if (value == nodes[root].val) {
    if (nodes[root].freq > 1) {
      --nodes[root].freq;
      --nodes[root].Sz;
    } else {
      makeFree(root);
      link(0, nodes[root].ch[LF], LF);
      link(0, nodes[root].ch[RI], LF);
      root = merge(nodes[root].ch[LF], nodes[root].ch[RI]);
    }
  }
}
void print(int node, int depth) {
  if (!node) {
    return void();
  }
  print(nodes[node].ch[LF], depth + 1);
  printf("%s%d\n", string(depth, ' ').c_str(), nodes[node].val);
  print(nodes[node].ch[RI], depth + 1);
}
void print(int node) {
  puts("--------------");
  print(node, 0);
  puts("--------------");
  fflush(stdout);
}
void fastscan(int &number) {
  bool negative = false;
  register int c;
  number = 0;
  while (c = getchar(), isspace(c))
    ;
  if (c == '-') {
    negative = true;
    c = getchar();
  }
  for (; (c > 47 && c < 58); c = getchar())
    number = (number << 3) + (number << 1) + c - 48;
  if (negative) number = -number;
}
int main() {
  init();
  int root = 0, n, x;
  fastscan(n);
  fastscan(x);
  insert(root, INT_MIN);
  insert(root, INT_MAX);
  insert(root, x);
  map<int, int> mp;
  mp[INT_MIN] = n + 1;
  mp[INT_MAX] = n + 1;
  mp[x] = n;
  while (--n) {
    fastscan(x);
    int aftIndx = lb(root, x);
    int aft = getByIdx(root, aftIndx);
    int bef = getByIdx(root, aftIndx - 1);
    printf("%d%c", min(make_pair(mp[aft], aft), make_pair(mp[bef], bef)).second,
           " \n"[n == 1]);
    mp[x] = n;
    insert(root, x);
  }
}
