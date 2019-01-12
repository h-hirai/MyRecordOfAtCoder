#include <iostream>
#include <vector>
#include <map>

int main() {
  ssize_t H, W;

  std::cin >> H >> W;

  std::vector<bool> grid(H*W);
  std::map<size_t, size_t> cnt_b;
  std::map<size_t, size_t> cnt_w;

  for (ssize_t i=0; i<H; i++) {
    for (ssize_t j=0; j<W; j++) {
      char c;
      std::cin >> c;
      grid[W*i+j] = c == '#';

      auto self = W*i+j;

      cnt_b.insert(std::make_pair(self, grid[self]?1:0));
      cnt_w.insert(std::make_pair(self, grid[self]?0:1));

      if (i>0) {
        auto up = W*(i-1)+j;
        if (grid[self] != grid[up]) {
          cnt_b[self] += cnt_b[up];
          cnt_w[self] += cnt_w[up];
          cnt_b.erase(up);
          cnt_w.erase(up);
        }
      }

      if (j>0) {
        auto left = W*i+j-1;
        if (grid[self] != grid[left]) {
          cnt_b[self] += cnt_b[left];
          cnt_w[self] += cnt_w[left];
          cnt_b.erase(left);
          cnt_w.erase(left);
        }
      }
    }
  }

  size_t ans = 0;

  for (auto p : cnt_b) {
    auto k = std::get<0>(p);
    auto b = std::get<1>(p);
    auto w = cnt_w[k];
    ans += b * w;
  }

  std::cout << ans << std::endl;

  return 0;
}
