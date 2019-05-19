#include <iostream>
#include <vector>
#include <set>

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

int main() {
  int N, M;

  std::cin >> N >> M;

  UnionFind uf(N);

  for (int i=0; i<M; i++) {
    int x, y, _z;
    std::cin >> x >> y >> _z;

    uf.unite(x, y);
  }

  std::set<int> rs;

  for (int i=0; i<N; i++) {
    rs.insert(uf.root(i));
  }

  int ans = rs.size();

  std::cout << ans << std::endl;

  return 0;
}
