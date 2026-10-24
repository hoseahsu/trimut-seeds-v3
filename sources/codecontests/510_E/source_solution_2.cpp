#include <bits/stdc++.h>
const int INF = 999999;
int is_prime(int number) {
  for (int i = 2; i <= sqrt(number + 1); ++i) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}
class Dinic {
 public:
  class Edge {
   public:
    Edge(int to, int cap, int flow, Edge* back)
        : to(to), cap(cap), flow(flow), back(back) {}
    bool remain() const { return flow < cap; }
    void add_flow(int f) {
      flow += f;
      back->flow -= f;
    }
    int to;
    int cap;
    int flow;
    Edge* back;
  };
  Dinic(int n, int src_in, int sink_in)
      : table(n), memo(n), level(n, -1), src(src_in), sink(sink_in) {}
  int dinic_augment(int v, int cap) {
    if (v == sink) {
      return cap;
    }
    const int v_size = static_cast<int>(table[v].size());
    for (int i = memo[v]; i < v_size; ++i) {
      const auto& e = table[v][i];
      if (level[e->to] != level[v] + 1) {
        continue;
      }
      if (!e->remain()) {
        continue;
      }
      const int f = dinic_augment(e->to, std::min(cap, e->cap - e->flow));
      if (f > 0) {
        e->add_flow(f);
        memo[v] = i + 1;
        return f;
      }
    }
    return 0;
  }
  void add_edge(int from, int to, int cap) {
    Edge* e = new Edge(to, cap, 0, nullptr);
    Edge* r = new Edge(from, 0, 0, e);
    e->back = r;
    table[from].push_back(e);
    table[to].push_back(r);
  }
  int calc() {
    int flow = 0;
    while (true) {
      fill(begin(level), end(level), -1);
      std::queue<int> q;
      q.push(src);
      level[src] = 0;
      while (!q.empty()) {
        const int v = q.front();
        q.pop();
        for (const auto& e : table[v]) {
          if (e->remain() and level[e->to] == -1) {
            level[e->to] = level[v] + 1;
            q.push(e->to);
          }
        }
      }
      bool updated = false;
      fill(begin(memo), end(memo), 0);
      while (true) {
        int add = dinic_augment(src, INF);
        if (add == 0) {
          break;
        }
        flow += add;
        updated = true;
      }
      if (updated == false) {
        break;
      }
    }
    return flow;
  }
  std::vector<std::vector<Edge*> > table;
  std::vector<int> memo, level;
  int src, sink;
};
int main() {
  int n;
  std::cin >> n;
  std::vector<int> nodes;
  for (int i = 0; i < n; ++i) {
    int tmp;
    std::cin >> tmp;
    nodes.push_back(tmp);
  }
  Dinic dinic(n + 2, n, n + 1);
  int flow = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (is_prime(nodes[i] + nodes[j])) {
        if (nodes[i] % 2 == 0) {
          dinic.add_edge(i, j, 1);
        } else {
          dinic.add_edge(j, i, 1);
        }
      }
    }
    if (nodes[i] % 2 == 0) {
      dinic.add_edge(n, i, 2);
      flow += 2;
    } else {
      dinic.add_edge(i, n + 1, 2);
    }
  }
  if (flow != n or dinic.calc() != flow) {
    std::cout << "Impossible" << std::endl;
  } else {
    const auto& graph = dinic.table;
    std::vector<bool> used(n, false);
    std::vector<std::vector<int> > components;
    for (int i = 0; i < n; ++i) {
      if (used[i]) {
        continue;
      }
      int cur = i;
      used[i] = true;
      components.push_back(std::vector<int>());
      while (true) {
        components.back().push_back(cur + 1);
        for (auto e : graph[cur]) {
          if (e->flow != 0 and e->to < n and !used[e->to]) {
            used[e->to] = true;
            cur = e->to;
            break;
          }
        }
        if (cur + 1 == components.back().back()) {
          break;
        }
      }
    }
    std::cout << components.size() << std::endl;
    for (const auto& c : components) {
      std::cout << c.size() << ' ';
      for (int i = 0; i < c.size(); ++i) {
        std::cout << c[i];
        if (i < c.size() - 1) {
          std::cout << ' ';
        }
      }
      std::cout << std::endl;
    }
  }
  return 0;
}
