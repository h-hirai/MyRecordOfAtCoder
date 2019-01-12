#include <iostream>
#include <vector>
#include <map>

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
  ssize_t H, W;

  std::cin >> H >> W;

  std::vector<bool> grid(H*W);

  for (ssize_t i=0; i<H; i++) {
    for (ssize_t j=0; j<W; j++) {
      char c;
      std::cin >> c;
      grid[W*i+j] = c == '#';
    }
  }


  UnionFindTree group(H*W);

  for (ssize_t i=0; i<H; i++) {
    for (ssize_t j=0; j<W; j++) {
      auto self = W*i+j;
      if (i>0) {
        auto up = W*(i-1)+j;
        if (grid[self] != grid[up]) {
          group.unite(self, up);
        }
      }
      if (j>0) {
        auto left = W*i+j-1;
        if (grid[self] != grid[left]) {
          group.unite(self, left);
        }
      }
      if (j+1<W) {
        auto right = W*i+j+1;
        if (grid[self] != grid[right]) {
          group.unite(self, right);
        }
      }
      if (i+1<H) {
        auto down = W*(i+1)+j;
        if (grid[self] != grid[down]) {
          group.unite(self, down);
        }
      }
    }
  }

  std::map<ssize_t, size_t> cnt_b;
  std::map<ssize_t, size_t> cnt_w;

  for (ssize_t i=0; i<H; i++) {
    for (ssize_t j=0; j<W; j++) {
      auto r = group.root(W*i+j);

      if (grid[W*i+j])
        cnt_b[r]++;
      else
        cnt_w[r]++;
    }
  }

  size_t ans = 0;

  for (auto p : cnt_b) {
    auto r = std::get<0>(p);
    auto b = std::get<1>(p);
    auto w = cnt_w[r];

    ans += b*w;
  }

  std::cout << ans << std::endl;

  return 0;
}
