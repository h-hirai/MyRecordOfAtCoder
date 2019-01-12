#include <iostream>
#include <vector>
#include <map>

int main() {
  ssize_t H, W;

  std::cin >> H >> W;

  std::vector<bool> grid(H*W);
  std::vector<size_t> ids(H*W);
  std::vector<size_t> cnt_b;
  std::vector<size_t> cnt_w;
  cnt_b.reserve(H*W);
  cnt_w.reserve(H*W);

  size_t num_id = 0;

  for (ssize_t i=0; i<H; i++) {
    for (ssize_t j=0; j<W; j++) {
      char c;
      std::cin >> c;
      grid[W*i+j] = c == '#';

      auto self = W*i+j;

      if (i>0) {
        auto up = W*(i-1)+j;
        if (grid[self] != grid[up]) {
          auto id = ids[up];
          ids[self] = id;
          if (grid[self])
            cnt_b[id]++;
          else
            cnt_w[id]++;
          continue;
        }
      }

      if (j>0) {
        auto left = W*i+j-1;
        if (grid[self] != grid[left]) {
          auto id = ids[left];
          ids[self] = id;
          if (grid[self])
            cnt_b[id]++;
          else
            cnt_w[id]++;
          continue;
        }
      }

      if (i==0 && j==0) {
        cnt_b.push_back(grid[self]?1:0);
        cnt_w.push_back(grid[self]?0:1);
        num_id++;
        continue;
      }

      cnt_b.push_back(grid[self]?1:0);
      cnt_w.push_back(grid[self]?0:1);
      ids[self] = num_id;
      num_id++;
    }
  }

  size_t ans = 0;

  for (size_t i=0; i<num_id; i++) {
    ans += cnt_b[i] * cnt_w[i];
  }

  std::cout << ans << std::endl;

  return 0;
}
