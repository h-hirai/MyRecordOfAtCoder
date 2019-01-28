#include <vector>

struct UnionFind {
  std::vector<size_t> par;
  std::vector<size_t> rank;

  UnionFind(size_t N) : par(N), rank(N) {
    for (size_t i=0; i<N; i++) {
      par[i] = i;
    }
  }

  size_t root(size_t x) {
    if (par[x] == x) {
      return x;
    } else {
      return par[x] = root(par[x]);
    }
  }

  bool same(size_t x, size_t y) {
    return root(x) == root(y);
  }

  void unite(size_t x, size_t y) {
    size_t root_x = root(x);
    size_t root_y = root(y);
    if (root_x == root_y) return;

    if (rank[root_x] < rank[root_y])
      par[root_x] = root_y;
    else
      par[root_y] = root_x;

    if (rank[root_x] == rank[root_y])
      rank[root_x]++;
  }
};
