#include <iostream>
#include <vector>

class UnionFind {
  public:
    std::vector<int> par;
    std::vector<int> rank;
    std::vector<int> size;

    UnionFind(int N) : par(N), rank(N), size(N) {        
        for (int i = 0; i < N; i++) {
            par[i]  = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }

    int find(int x)
    {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y) { return; }

        if (rank[x] < rank[y]) {
            par[x] = y;
            size[y] += size[x];
        } else {
            par[y] = x;
            size[x] += size[y];
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }       
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
};

int main()
{
    int N, M;
    std::cin >> N >> M;

    UnionFind uf(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        uf.unite(a - 1, b - 1);
    }
    
    int city = 0;
    int town = 0;
    std::vector<bool> used(N, false);
    
    for (int i = 0; i < N; i++) {
        int x = uf.find(i);
        if (used[x]) { continue; }

        used[x] = true;
        if (uf.size[x] == 1) {
            town++;
        } else {
            city++;
        }
    }

    int diff = town - city;
    std::cout << (diff < 0 ? -diff : diff) << std::endl;
    
    return 0;
}