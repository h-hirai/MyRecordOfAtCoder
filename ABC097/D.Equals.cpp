#include <iostream>
#include <vector>

struct UnionFindTree {
  std::vector<long> par;

  UnionFindTree(long N) : par(N) {
    for (long i=0; i<N; i++) {
      par[i] = i;
    }
  }

  long root(long x) {
    if (par[x] == x) {
      return x;
    } else {
      return par[x] = root(par[x]);
    }
  }

  bool same(long x, long y) {
    return root(x) == root(y);
  }

  void unite(long x, long y) {
    long root_x = root(x);
    long root_y = root(y);
    if (root_x == root_y) return;
    par[root_x] = root_y;
  }
};

int main() {
  long N, M;

  std::cin >> N;
  std::cin >> M;

  std::vector<long> P(N);

  for (size_t i=0; i<N; i++) {
    long p;
    std::cin >> p;
    P[i] = p-1;
  }

  UnionFindTree tree(N);

  for (size_t i=0; i<M; i++) {
    long x, y;
    std::cin >> x;
    std::cin >> y;
    tree.unite(x-1, y-1);
  }

  long ans=0;

  for (size_t i=0; i<N; i++) {
    if (tree.same(P[i], i)) {
      ans++;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
